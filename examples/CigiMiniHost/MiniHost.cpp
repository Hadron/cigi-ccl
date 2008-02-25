/** <pre>
 *  The CIGI MiniHost
 *  Copyright (c) 2004 The Boeing Company
 *  
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *  
 *  
 *  FILENAME:   MiniHost.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Multi-Purpose Viewer
 *  
 *  PROGRAM DESCRIPTION: 
 *  This class contains the data and methods necessary to
 *   handle the network interface.
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  03/29/2004 Andrew Sampson                       MPV_CR_DR_1
 *  Initial Release.
 * </pre>
 *  The Boeing Company
 *  1.0
 */


#include "Network.h"  // network includes winsock2.h which must be included before windows.h


// Tiny XML includes
#define TINYXML_USE_STL
#define TIXML_USE_STL

#include <tinyxml.h>
#include <tinystr.h>


// CIGI related includes
// From CCL
#include <CigiHostSession.h>
#include <CigiExceptions.h>
#include <CigiEntityCtrlV3.h>
#include <CigiIGCtrlV3_2.h>
#include <CigiSOFV3_2.h>
#include <CigiAnimationStopV3.h>

// Handling routines
#include "SOFP.h"
#include "AnimStop.h"
#include "DefaultProc.h"


// System includes
#include <stdio.h>

#include <iostream>
#include <list>

#ifdef WIN32
#include <Windows.h>
#include <conio.h>
#endif

#include <time.h>

// Special database information structure
typedef struct Database_info
{
   int id;
   double lat;
   double lon;
   double alt;
} DbInfo;



using namespace std;


// ================================================
// Global variables
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

// Networking class/object
Network network;

// CIGI specific 
static CigiHostSession *HostSn;
static CigiOutgoingMsg *OmsgPtr;
static CigiIncomingMsg *ImsgPtr;
static SOFP *pSOFP;
static AnimStop *pAnimStop;
static DefaultProc DefaultPckt;
static CigiEntityCtrlV3 COwn;
static CigiIGCtrlV3_2 CIGC;

// CIGI network message buffers and information
int recvLen;
static unsigned char *pCigiOutBuf;

#define RECV_BUFFER_SIZE 32768
static unsigned char CInBuf[RECV_BUFFER_SIZE];

static int CigiInSz;
static int CigiOutSz;

static int Port_H2IG;
static int Port_IG2H;
static string IGAddr;

// The database information
int CurrentDB;

std::list<DbInfo *> dblist;
std::list<DbInfo *>::iterator idbl;



// ================================================
// Pre-declaration of Local routines
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void ReadConfig(void);
int init_cigi_if(void);





// ================================================
// Main
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int main(int argc, char* argv[])
{
   CigiInSz = 0;
   
   ReadConfig();
   
   if(dblist.empty())
   {
      cout << "\n\nNo Database Information!\n\n";
      return(0);
   }
   
   init_cigi_if();
   
   /* CIGI messaging */
   CigiOutgoingMsg &Omsg = *OmsgPtr;
   
   
   // Initialize ownship position
   idbl = dblist.begin();
   COwn.SetLat((*idbl)->lat);
   COwn.SetLon((*idbl)->lon);
   COwn.SetAlt((*idbl)->alt);
   COwn.SetYaw(0.0);
   COwn.SetPitch(0.0);
   COwn.SetRoll(0.0);


   Omsg.BeginMsg();


   while(1)
   {
      
      /* process incoming CIGI message - this should be short */
      if( CigiInSz > 0 ) {
         try {
            ImsgPtr->ProcessIncomingMsg((unsigned char *)CInBuf,CigiInSz);
         }
         catch( CigiException &theException ){
            std::cout << "getNetMessages - Exception: " << theException.what() << std::endl;
         }
      }


      // load the IG Control
      Omsg << CIGC;
      
      /* Update ownship position */
      double olat = COwn.GetLat();
      COwn.SetLat(olat + 0.0000137);
      

      Omsg << COwn;



      // Do packaging here to 
      // Package msg
      try {
         Omsg.PackageMsg(&pCigiOutBuf,CigiOutSz);
      } catch( CigiException &theException ){
         std::cout << "getNetMessages - Exception: " << theException.what() << std::endl;
      }


      // wait for Start Of Frame
      long HoldTime;
      bool RcvrProc = false;
      long CheckTime = time(&HoldTime);
      while(!RcvrProc)
      {
         if((CigiInSz = network.recv( CInBuf, RECV_BUFFER_SIZE )) > 0)
            RcvrProc = true;
         else
         {
            long TstTime = time(&HoldTime);
            if((TstTime - CheckTime) > 1)
            {
               cout << "Did not receive SOF\n";
               RcvrProc = true;
               CigiInSz = 0;
            }
         }
      }


      if(pCigiOutBuf != NULL)
      {
         if(CigiInSz > 0)
            Omsg.UpdateIGCtrl(pCigiOutBuf,CInBuf);
         else
            Omsg.UpdateIGCtrl(pCigiOutBuf,NULL);


         // send CIGI message
         int sentBytes = network.send(pCigiOutBuf,CigiOutSz);
      }

      Omsg.FreeMsg();   // Frees the buffer containing the message that was just sent

   }
   
   
   // shut down the network
   network.closeSocket();
   
   delete HostSn;
   delete pSOFP;
   delete pAnimStop;
   
   return 0;
}



// ================================================
// Read Configuration
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void ReadConfig(void)
{
   
   TiXmlNode *bnode = NULL;  // base node
   
   TiXmlText *Port_To_Cigi = NULL;
   TiXmlText *Port_From_Cigi = NULL;
   TiXmlText *IG_Addr = NULL;
   
   TiXmlHandle *hConfig = NULL; // pointer to a Config handle
   
   TiXmlElement *Config = NULL;
   
   TiXmlText *DbDta = NULL;
   
   
   
   
   TiXmlDocument doc("MiniHost.def");
   bool stat = doc.LoadFile();
   
   //set default values
   Port_H2IG = 8000;
   Port_IG2H = 8001;
   IGAddr = "127.0.0.1";
   
   
   if(stat)
   {
      bnode = doc.FirstChild("MiniHostInitialization");
      
      if(bnode == NULL)
         stat = false;  // The file is not a Mission Function Initialization file
   }
   
   
   if(stat)
   {
      // get base configuration
      Config = bnode->FirstChildElement("Config");
      
      if(Config != NULL)
      {
         hConfig = new TiXmlHandle(Config);
         
         
         IG_Addr = hConfig->FirstChildElement("IG_Addr").Child(0).Text();
         if(IG_Addr)
            IGAddr = IG_Addr->Value();
         
         Port_To_Cigi = hConfig->FirstChildElement("Port_To_IG").Child(0).Text();
         Port_H2IG = (Port_To_Cigi) ? atoi(Port_To_Cigi->Value()) : 8000;
         
         Port_From_Cigi = hConfig->FirstChildElement("Port_From_IG").Child(0).Text();
         Port_IG2H = (Port_From_Cigi) ? atoi(Port_From_Cigi->Value()) : 8001;
         
         delete hConfig;
         
      }
      
      
      
      // get Database configuration
      Config = bnode->FirstChildElement("DBase");
      
      while(Config != NULL)
      {
         hConfig = new TiXmlHandle(Config);
         
         DbInfo *pDbInfo = new DbInfo;
         
         DbDta = hConfig->FirstChildElement("ID").Child(0).Text();
         pDbInfo->id = (DbDta) ? atoi(DbDta->Value()) : 5;
         
         DbDta = hConfig->FirstChildElement("Lat").Child(0).Text();
         pDbInfo->lat = (DbDta) ? atof(DbDta->Value()) : 0.0;
         
         DbDta = hConfig->FirstChildElement("Lon").Child(0).Text();
         pDbInfo->lon = (DbDta) ? atof(DbDta->Value()) : 0.0;
         
         DbDta = hConfig->FirstChildElement("Alt").Child(0).Text();
         pDbInfo->alt = (DbDta) ? atof(DbDta->Value()) : 0.0;
         
         dblist.push_back(pDbInfo);
         
         Config = Config->NextSiblingElement("DBase");
      }
      
   }
   
}



// ================================================
// Initialize interface to CIGI
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int init_cigi_if(void){
   int err_status = 0;
   
   /* open sockets to CIGI */
   // hostemu-ip-addr, hostemu-socket, local-socket
   printf("init_cigi_if: initializing ports to CIGI\n");
   bool netstatus = network.openSocket( 
      IGAddr.c_str(), 
      Port_H2IG, 
      Port_IG2H );
   
   if( !netstatus ) {
      printf( "could not connect to CIGI IG server\n" );
      exit( 1 );
   } else {
      printf( "successfully connected to CIGI IG server\n" );
   }
   
   
   HostSn = new CigiHostSession(1,32768,2,32768);
   pSOFP = new SOFP;
   pAnimStop = new AnimStop;
   
   CigiOutgoingMsg &Omsg = HostSn->GetOutgoingMsgMgr();
   CigiIncomingMsg &Imsg = HostSn->GetIncomingMsgMgr();
   OmsgPtr = &Omsg;
   ImsgPtr = &Imsg;
   
   HostSn->SetCigiVersion(3,2);
   HostSn->SetSynchronous(true);
   
   Imsg.SetReaderCigiVersion(3,2);
   Imsg.UsingIteration(false);
   
   // set up a default handler for unhandled packets
   Imsg.RegisterEventProcessor(0, (CigiBaseEventProcessor *) &DefaultPckt);
   
   // register SOF
   Imsg.RegisterEventProcessor(
      CIGI_SOF_PACKET_ID_V3_2,
      (CigiBaseEventProcessor *) pSOFP);
   
   //Register animation stop
   Imsg.RegisterEventProcessor(CIGI_ANIMATION_STOP_PACKET_ID_V3,
      (CigiBaseEventProcessor *) pAnimStop);
   
   // initialize the IG Control
   CIGC.SetIGMode(CigiBaseIGCtrl::Operate);
   
   
   // initialize the Ownship
   //  the other parameters are set by CigiEntityCtrlV3
   COwn.SetEntityID(0);
   COwn.SetEntityType(0);
   COwn.SetEntityState(CigiBaseEntityCtrl::Active);
   
   
   return err_status;
}









