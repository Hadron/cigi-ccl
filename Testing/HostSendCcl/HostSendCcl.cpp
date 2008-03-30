// HostSendCcl.cpp : Defines the entry point for the console application.
//
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
 *  FILENAME:   HostSendCcl.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Multi-Purpose Viewer
 *
 *  PROGRAM DESCRIPTION:
 *  This class contains the data and methods necessary to
 *   test certain portions of CIGI.
 *
 *
 * </pre>
 *  The Boeing Company
 *  1.0
 */


#include "Network.h"  // network includes winsock2.h which must be included before windows.h

#include "StdAfx.h"

// Tiny XML includes
#define TINYXML_USE_STL
#define TIXML_USE_STL

#include <tinyxml.h>
#include <tinystr.h>


// CIGI related includes
// From CCL
#include <CigiHostSession.h>
#include <CigiExceptions.h>
#include <CigiIGCtrlV3_2.h>
#include <CigiIGCtrlV3.h>
#include <CigiIGCtrlV2.h>
#include <CigiIGCtrlV1.h>


// System includes
#include <stdio.h>

#include <iostream>
#include <list>

#ifdef WIN32
#include <Windows.h>
#include <conio.h>
#endif

#include <time.h>


// Test Includes
#include "XSOF.h"
#include "DefaultProc.h"
#include "OutputProc3.h"
#include "OutputProc2.h"
#include "OutputProc1.h"


// Special database information structure
typedef struct Database_info
{
   int id;
   double lat;
   double lon;
   double alt;
} DbInfo;


//using namespace std;


// ================================================
// Global variables
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

// Networking class/object
Network network;

// CIGI specific
static CigiHostSession *HostSn;
static CigiOutgoingMsg *OmsgPtr;
static CigiIncomingMsg *ImsgPtr;

OutputProcessor *OutProc;

XSOF *Pr_SOF = NULL;
DefaultProc *Pr_Default = NULL;


static CigiIGCtrlV3_2 CIGC3_2;
static CigiIGCtrlV3 CIGC3;
static CigiIGCtrlV2 CIGC2;
static CigiIGCtrlV1 CIGC1;
static CigiBaseIGCtrl *pCIGC;

// CIGI network message buffers and information
int recvLen;
static unsigned char *pCigiOutBuf;

#define RECV_BUFFER_SIZE 32768
static unsigned char CInBuf[RECV_BUFFER_SIZE];

static int CigiInSz;
static int CigiOutSz;

static string IGAddr;

static int Port_H2IG;
static int Port_IG2H;
static int MajorVer;
static int MinorVer;

static string CsvFile;


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
int _tmain(int argc, _TCHAR* argv[])
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
      Omsg << *pCIGC;


      OutProc->Out();


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

   delete Pr_SOF;
   delete Pr_Default;

   delete OutProc;

   return 0;
}



// ================================================
// Read Configuration
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void ReadConfig(void)
{

   TiXmlNode *bnode = NULL;  // base node

   TiXmlText *ParseTxt = NULL;

   TiXmlHandle *hConfig = NULL; // pointer to a Config handle

   TiXmlElement *Config = NULL;

   TiXmlText *DbDta = NULL;




   TiXmlDocument doc("MiniHost.def");
   bool stat = doc.LoadFile();

   //set default values
   Port_H2IG = 8000;
   Port_IG2H = 8001;
   IGAddr = "127.0.0.1";

   MajorVer = 3;
   MinorVer = 2;

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


         ParseTxt = hConfig->FirstChildElement("IG_Addr").Child(0).Text();
         if(ParseTxt)
            IGAddr = ParseTxt->Value();

         ParseTxt = hConfig->FirstChildElement("Port_To_IG").Child(0).Text();
         Port_H2IG = (ParseTxt) ? atoi(ParseTxt->Value()) : 8000;

         ParseTxt = hConfig->FirstChildElement("Port_From_IG").Child(0).Text();
         Port_IG2H = (ParseTxt) ? atoi(ParseTxt->Value()) : 8001;

         ParseTxt = hConfig->FirstChildElement("Major_Version_Cigi").Child(0).Text();
         MajorVer = (ParseTxt) ? atoi(ParseTxt->Value()) : 0;

         if((MajorVer == 1) || (MajorVer == 2))
            MinorVer = 0;
         else if(MajorVer == 3)
         {
            ParseTxt = hConfig->FirstChildElement("Minor_Version_Cigi").Child(0).Text();
            MinorVer = (ParseTxt) ? atoi(ParseTxt->Value()) : 0;

            if(MinorVer < 2)
               MinorVer = 0;
            else if(MinorVer > 3)
               MinorVer = 3;
         }


         ParseTxt = hConfig->FirstChildElement("Csv_File_Name").Child(0).Text();
         if(ParseTxt)
            CsvFile = ParseTxt->Value();
         else
            CsvFile.clear();

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
int init_cigi_if(void)
{
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

   CigiOutgoingMsg &Omsg = HostSn->GetOutgoingMsgMgr();
   CigiIncomingMsg &Imsg = HostSn->GetIncomingMsgMgr();
   OmsgPtr = &Omsg;
   ImsgPtr = &Imsg;

   HostSn->SetCigiVersion(MajorVer,MinorVer);
   HostSn->SetSynchronous(true);

   Imsg.SetReaderCigiVersion(MajorVer,MinorVer);
   Imsg.UsingIteration(false);


   // Version specific items
   pCIGC = &CIGC3_2;
   int tSOF_ID = CIGI_SOF_PACKET_ID_V3_2;
   OutProc = NULL;
   if(MajorVer == 3)
   {
      if(MinorVer < 2)
      {
         tSOF_ID = CIGI_SOF_PACKET_ID_V3;
         pCIGC = &CIGC3;
      }
      else
      {
         tSOF_ID = CIGI_SOF_PACKET_ID_V3_2;
         pCIGC = &CIGC3_2;
      }
      OutProc = new OutputProcessor3;
   }
   else if(MajorVer == 2)
   {
      tSOF_ID = CIGI_SOF_PACKET_ID_V2;
      pCIGC = &CIGC2;
      OutProc = new OutputProcessor2;
   }
   else if(MajorVer == 1)
   {
      tSOF_ID = CIGI_SOF_PACKET_ID_V1;
      pCIGC = &CIGC1;
      OutProc = new OutputProcessor1;
   }

   if(OutProc == NULL)
   {
      MajorVer = 3;
      MinorVer = 3;
      OutProc = new OutputProcessor3;
   }


   // SOF
   Pr_SOF = new XSOF;
   Imsg.RegisterEventProcessor(tSOF_ID,
                              (CigiBaseEventProcessor *) Pr_SOF);

   // Default Packet Processor
   Pr_Default = new DefaultProc;
	Imsg.RegisterEventProcessor(0, (CigiBaseEventProcessor *) Pr_Default);



   // Initialize the outgoing message processor
   OutProc->Init(HostSn,CsvFile,MajorVer,MinorVer);



   // initialize the IG Control
   pCIGC->SetDatabaseID(0,false);
   pCIGC->SetIGMode(CigiBaseIGCtrl::Operate);
   CIGC3.SetTimeStampValid(false);
   CIGC3_2.SetTimeStampValid(false);



   return err_status;
}




