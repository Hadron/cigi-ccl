/** <pre>
 *  The CIGI IG tester
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
 *  FILENAME:   IgSendCcl.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Multi-Purpose Viewer
 *  
 *  PROGRAM DESCRIPTION: 
 *  This contains the code needed to run the IG side CIGI
 *   communications tester.
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  12/21/2007 Greg Basler                       MPV_CR_DR_1
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
#include <CigiIGSession.h>
#include <CigiExceptions.h>

#include <CigiIGCtrlV1.h>
#include <CigiIGCtrlV2.h>
#include <CigiIGCtrlV3.h>
#include <CigiIGCtrlV3_2.h>

#include <CigiSOFV1.h>
#include <CigiSOFV2.h>
#include <CigiSOFV3.h>
#include <CigiSOFV3_2.h>

// Test Includes
#include "OutputProc3.h"
#include "OutputProc2.h"
#include "OutputProc1.h"

// Handling routines
#include "DefaultProc.h"
#include "XIGCtrl.h"

// System includes
#include <stdio.h>

#include <iostream>
#include <list>

#ifdef WIN32
#include <Windows.h>
#include <conio.h>
#endif

#ifdef WIN32
#include <time.h>
#else
#include <sys/time.h>
#endif

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
static CigiIGSession *IGSn;
static CigiOutgoingMsg *OmsgPtr;
static CigiIncomingMsg *ImsgPtr;
static DefaultProc DefaultPckt;

static CigiSOFV1 CSOF1;
static CigiSOFV2 CSOF2;
static CigiSOFV3 CSOF3;
static CigiSOFV3_2 CSOF3_2;
static CigiBaseSOF *pSOF;


static XIGCtrl Pr_IGCtrl;

// Packet Output processor
OutputProcessor *OutProc;


// CIGI network message buffers and information
int recvLen;
static unsigned char *pCigiOutBuf;

#define RECV_BUFFER_SIZE 32768
static unsigned char CInBuf[RECV_BUFFER_SIZE];

static int CigiInSz;
static int CigiOutSz;

static int Port_H2IG;
static int Port_IG2H;
static string HostAddr;
static int MajorVer;
static int MinorVer;

static string CsvFile;

static float timeDelayLimit;
static int Hz;


static CigiSOFV3_2 check_SOF;

// ================================================
// Pre-declaration of Local routines
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void ReadConfig(void);
int init_cigi_if(void);
void waitUntilBeginningOfFrame(void);

#ifndef WIN32
float timevaldiff( struct timeval *t1, struct timeval *t2 );
#endif



// ================================================
// Main
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int main(int argc, char* argv[])
{
   CigiInSz = 0;
   OutProc = NULL;
   
   ReadConfig();
   
   init_cigi_if();
   
   /* CIGI messaging */
   CigiOutgoingMsg &Omsg = *OmsgPtr;



   Omsg.BeginMsg();


   while(1)
   {

      /* process incoming CIGI message - this could be long */
      if( CigiInSz > 0 ) {
         try {
            ImsgPtr->ProcessIncomingMsg((unsigned char *)CInBuf,CigiInSz);
         }
         catch( CigiException &theException ){
            std::cout << "getNetMessages - Exception: " << theException.what() << std::endl;
         }
      }


      // load the SOF
      Omsg << *pSOF;


      OutProc->Out();


      // wait until start of frame time
      waitUntilBeginningOfFrame();


      // Do packaging here to 
      // Package msg
      try {
         Omsg.PackageMsg(&pCigiOutBuf,CigiOutSz);
      } catch( CigiException &theException ){
         std::cout << "getNetMessages - Exception: " << theException.what() << std::endl;
      }


      // Update Frame IDs
      Omsg.UpdateSOF(pCigiOutBuf);


      // send SOF message
      int sentBytes = network.send(pCigiOutBuf,CigiOutSz);


      // Check frame counter
		check_SOF.Unpack(pCigiOutBuf,false,NULL);
//		cout << check_SOF.GetFrameCntr() << endl;


      Omsg.FreeMsg();   // Frees the buffer containing the message that was just sent


      // wait for Host message
      long HoldTime;
      bool RcvrProc = false;
      long CheckTime = (long)time(&HoldTime);
      while(!RcvrProc)
      {
         if((CigiInSz = network.recv( CInBuf, RECV_BUFFER_SIZE )) > 0)
            RcvrProc = true;
         else
         {
            long TstTime = (long)time(&HoldTime);
            if((TstTime - CheckTime) > 1)
            {
               cout << "Did not receive IG Control\n";
               RcvrProc = true;
               CigiInSz = 0;
            }
         }
      }

   }


   // shut down the network
   network.closeSocket();
   
   delete IGSn;

   if(OutProc != NULL)
      delete OutProc;

   return 0;
}



// ================================================
// Read Configuration
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void ReadConfig(void)
{
   
   TiXmlNode *bnode = NULL;  // base node
   
   TiXmlText *CfgDta = NULL;

   TiXmlHandle *hConfig = NULL; // pointer to a Config handle
   
   TiXmlElement *Config = NULL;
   
   TiXmlText *DbDta = NULL;
   
   
   
   
   TiXmlDocument doc("CigiDummyIG.def");
   bool stat = doc.LoadFile();
   
   //set default values
   Port_H2IG = 8000;
   Port_IG2H = 8001;
   HostAddr = "127.0.0.1";
  
   MajorVer = 3;
   MinorVer = 3;



   
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
         
         
         CfgDta = hConfig->FirstChildElement("Host_Addr").Child(0).Text();
         if(CfgDta)
            HostAddr = CfgDta->Value();
         
         CfgDta = hConfig->FirstChildElement("Port_To_IG").Child(0).Text();
         Port_H2IG = (CfgDta) ? atoi(CfgDta->Value()) : 8000;
         
         CfgDta = hConfig->FirstChildElement("Port_To_Host").Child(0).Text();
         Port_IG2H = (CfgDta) ? atoi(CfgDta->Value()) : 8001;

         CfgDta = hConfig->FirstChildElement("Hertz_rate").Child(0).Text();
         Hz = (CfgDta) ? atoi(CfgDta->Value()) : 60;
         timeDelayLimit = 1.0f/((float)Hz);

         CfgDta = hConfig->FirstChildElement("Major_Version_Cigi").Child(0).Text();
         MajorVer = (CfgDta) ? atoi(CfgDta->Value()) : 0;

         if((MajorVer == 1) || (MajorVer == 2))
            MinorVer = 0;
         else if(MajorVer == 3)
         {
            CfgDta = hConfig->FirstChildElement("Minor_Version_Cigi").Child(0).Text();
            MinorVer = (CfgDta) ? atoi(CfgDta->Value()) : 3;

            if(MinorVer < 2)
               MinorVer = 0;
            else if(MinorVer > 3)
               MinorVer = 3;
         }
         else
         {
            MajorVer = 3;
            MinorVer = 3;
         }


         CfgDta = hConfig->FirstChildElement("Csv_File_Name").Child(0).Text();
         if(CfgDta)
            CsvFile = CfgDta->Value();
         else
            CsvFile.clear();


         delete hConfig;
         
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
      HostAddr.c_str(), 
      Port_IG2H,
      Port_H2IG );
   
   if( !netstatus ) {
      printf( "could not connect to CIGI host server\n" );
      exit( 1 );
   } else {
      printf( "successfully connected to CIGI host server\n" );
   }
   
   
   IGSn = new CigiIGSession(1,32768,2,32768);
   // Add packet event handlers here!

   CigiOutgoingMsg &Omsg = IGSn->GetOutgoingMsgMgr();
   CigiIncomingMsg &Imsg = IGSn->GetIncomingMsgMgr();
   OmsgPtr = &Omsg;
   ImsgPtr = &Imsg;


   // Version specific items
   pSOF = &CSOF2;
   int tIGCtrl_ID = CIGI_IG_CTRL_PACKET_ID_V3_2;
   OutProc = NULL;
   if(MajorVer == 3)
   {
      if(MinorVer < 2)
      {
         tIGCtrl_ID = CIGI_IG_CTRL_PACKET_ID_V3;
         pSOF = &CSOF3;
      }
      else
      {
         tIGCtrl_ID = CIGI_IG_CTRL_PACKET_ID_V3_2;
         pSOF = &CSOF3_2;
      }
      OutProc = new OutputProcessor3;
   }
   else if(MajorVer == 2)
   {
      tIGCtrl_ID = CIGI_IG_CTRL_PACKET_ID_V2;
      pSOF = &CSOF2;
      OutProc = new OutputProcessor2;
   }
   else if(MajorVer == 1)
   {
      tIGCtrl_ID = CIGI_IG_CTRL_PACKET_ID_V1;
      pSOF = &CSOF1;
      OutProc = new OutputProcessor1;
   }

   if(OutProc == NULL)
   {
      MajorVer = 3;
      MinorVer = 3;
      OutProc = new OutputProcessor3;
   }

   IGSn->SetCigiVersion(MajorVer,MinorVer);
   IGSn->SetSynchronous(true);
   
   Imsg.SetReaderCigiVersion(MajorVer,MinorVer);
   Imsg.UsingIteration(false);
   
   // set up a default handler for unhandled packets
   Imsg.RegisterEventProcessor(0, (CigiBaseEventProcessor *) &DefaultPckt);

   // Register all the IG Ctrl processor
   Imsg.RegisterEventProcessor(tIGCtrl_ID,(CigiBaseEventProcessor *) &Pr_IGCtrl);



   // Initialize the outgoing message processor
   OutProc->Init(IGSn,CsvFile,MajorVer,MinorVer);


   // initialize the SOF
   pSOF->SetDatabaseID(1);
   pSOF->SetIGStatus(0);
   pSOF->SetIGMode(CigiBaseSOF::Operate);

   CSOF1.SetFrameCntr(0);

   CSOF2.SetFrameCntr(0);
   CSOF2.SetTimeStamp(0.0f);

   CSOF3.SetFrameCntr(0);
   CSOF3.SetTimeStamp(0);
   CSOF3.SetTimeStampValid(false);
   CSOF3.SetEarthRefModel(CigiBaseSOF::WGS84);

   CSOF3_2.SetFrameCntr(0);
   CSOF3_2.SetTimeStamp(0);
   CSOF3_2.SetTimeStampValid(false);
   CSOF3_2.SetEarthRefModel(CigiBaseSOF::WGS84);
   CSOF3_2.SetLastRcvdHostFrame(0);


   return err_status;
}




// ================================================
// waitUntilBeginningOfFrame
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
#ifdef WIN32
void waitUntilBeginningOfFrame( void ) {
   static DWORD t1 = 0;
   static DWORD t2 = 0;
	static bool firsttimethrough = true;

   if(firsttimethrough)
   {
      t1 = GetTickCount();
		firsttimethrough = false;
	}

   do {
      t2 = GetTickCount();  // number of milliseconds
   } while((t2 - t1) < timeDelayLimit);

	t1 = t2;
}
#else
void waitUntilBeginningOfFrame( void ) {
	static struct timeval t1;
	static struct timeval t2;
	static bool firsttimethrough = true;
	float diff;
	float busy_wait_time = 0.0f;

	gettimeofday( &t2, NULL );

	if( firsttimethrough ) {
		gettimeofday( &t1, NULL );

		firsttimethrough = false;
	}

	while( (diff = timevaldiff( &t1, &t2 )) < timeDelayLimit ) {
		if(busy_wait_time != 0.0f &&
			timeDelayLimit - diff > busy_wait_time)
		{
			float sleep_time =
				timeDelayLimit - diff - busy_wait_time;
			struct timespec req;
			req.tv_sec = (time_t)sleep_time;
			req.tv_nsec = (long)((sleep_time-req.tv_sec)*1e9);
			if(pselect(0, NULL, NULL, NULL, &req, NULL)==-1)
			{
				printf("Error calling pselect");
				busy_wait_time = 0.0f;
			}
		}
		gettimeofday( &t2, NULL );
	}
	//printf("over frame by %f ms\n", diff - timeDelayLimit);

	t1 = t2;
}


// ================================================
// timevaldiff
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
float timevaldiff( struct timeval *t1, struct timeval *t2 ) {
	return (t2->tv_sec - t1->tv_sec) +
		(t2->tv_usec - t1->tv_usec)/1000000.0f;
}

#endif


