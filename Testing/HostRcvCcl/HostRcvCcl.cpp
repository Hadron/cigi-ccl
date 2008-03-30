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
 *  FILENAME:   HostRcvCcl.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Multi-Purpose Viewer
 *  
 *  PROGRAM DESCRIPTION: 
 *  This contains the code needed to run the Host Receive side
 *   CIGI communications tester.
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
#include <CigiHostSession.h>
#include <CigiExceptions.h>
#include <CigiIGCtrlV3_2.h>
#include <CigiIGCtrlV3.h>
#include <CigiIGCtrlV2.h>
#include <CigiIGCtrlV1.h>

// Handling routines
#include "DefaultProc.h"

#include "XSOF.h"

#include "XSOFV1.h"
#include "XHatRespV1.h"
#include "XLosRespV1.h"
#include "XCollDetSegRespV1.h"
#include "XSensorRespV1.h"

#include "XSOFV2.h"
#include "XHatRespV2.h"
#include "XLosRespV2.h"
#include "XCollDetSegRespV2.h"
#include "XSensorRespV2.h"
#include "XHotRespV2.h"
#include "XCollDetVolRespV2.h"
#include "XIGMsgV2.h"

#include "XSOFV3.h"
#include "XHatHotRespV3.h"
#include "XHatHotXRespV3.h"
#include "XLosRespV3.h"
#include "XLosXRespV3.h"
#include "XSensorRespV3.h"
#include "XSensorXRespV3.h"
#include "XPositionRespV3.h"
#include "XWeatherCondRespV3.h"
#include "XAerosolRespV3.h"
#include "XMaritimeSurfaceRespV3.h"
#include "XTerrestrialSurfaceRespV3.h"
#include "XCollDetSegRespV3.h"
#include "XCollDetVolRespV3.h"
#include "XAnimationStopV3.h"
#include "XEventNotificationV3.h"
#include "XIGMsgV3.h"

#include "XSOFV3_2.h"
#include "XHatHotRespV3_2.h"
#include "XHatHotXRespV3_2.h"
#include "XLosRespV3_2.h"
#include "XLosXRespV3_2.h"


// System includes
#include <stdio.h>

#include <iostream>
#include <list>

#ifdef WIN32
#include <Windows.h>
#include <conio.h>
#endif

#include <time.h>


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
static DefaultProc DefaultPckt;

static CigiIGCtrlV3_2 CIGC3_2;
static CigiIGCtrlV3 CIGC3;
static CigiIGCtrlV2 CIGC2;
static CigiIGCtrlV1 CIGC1;
static CigiBaseIGCtrl *pCIGC;


static XSOF Pr_SOF;

static XSOFV1 Pr_SOFV1;
static XHatRespV1 Pr_HatRespV1;
static XLosRespV1 Pr_LosRespV1;
static XCollDetSegRespV1 Pr_CollDetSegRespV1;
static XSensorRespV1 Pr_SensorRespV1;

static XSOFV2 Pr_SOFV2;
static XHatRespV2 Pr_HatRespV2;
static XLosRespV2 Pr_LosRespV2;
static XCollDetSegRespV2 Pr_CollDetSegRespV2;
static XSensorRespV2 Pr_SensorRespV2;
static XHotRespV2 Pr_HotRespV2;
static XCollDetVolRespV2 Pr_CollDetVolRespV2;
static XIGMsgV2 Pr_IGMsgV2;

static XSOFV3 Pr_SOFV3;
static XHatHotRespV3 Pr_HatHotRespV3;
static XHatHotXRespV3 Pr_HatHotXRespV3;
static XLosRespV3 Pr_LosRespV3;
static XLosXRespV3 Pr_LosXRespV3;
static XSensorRespV3 Pr_SensorRespV3;
static XSensorXRespV3 Pr_SensorXRespV3;
static XPositionRespV3 Pr_PositionRespV3;
static XWeatherCondRespV3 Pr_WeatherCondRespV3;
static XAerosolRespV3 Pr_AerosolRespV3;
static XMaritimeSurfaceRespV3 Pr_MaritimeSurfaceRespV3;
static XTerrestrialSurfaceRespV3 Pr_TerrestrialSurfaceRespV3;
static XCollDetSegRespV3 Pr_CollDetSegRespV3;
static XCollDetVolRespV3 Pr_CollDetVolRespV3;
static XAnimationStopV3 Pr_AnimationStopV3;
static XEventNotificationV3 Pr_EventNotificationV3;
static XIGMsgV3 Pr_IGMsgV3;

static XSOFV3_2 Pr_SOFV3_2;
static XHatHotRespV3_2 Pr_HatHotRespV3_2;
static XHatHotXRespV3_2 Pr_HatHotXRespV3_2;
static XLosRespV3_2 Pr_LosRespV3_2;
static XLosXRespV3_2 Pr_LosXRespV3_2;






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

static int MajorVer;
static int MinorVer;
static bool PrtSOF;

static float timeDelayLimit;


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
   
   init_cigi_if();
   
   /* CIGI messaging */
   CigiOutgoingMsg &Omsg = *OmsgPtr;



   Omsg.BeginMsg();


   while(1)
   {
      cout << "================================\n";
      cout << "Frame: " << Omsg.GetFrameCnt() << endl;
      cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n";

      // load the IG Control
      Omsg << *pCIGC;


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

      /* process incoming CIGI message - this could be long */
      if( CigiInSz > 0 ) {
         try {
            ImsgPtr->ProcessIncomingMsg((unsigned char *)CInBuf,CigiInSz);
         }
         catch( CigiException &theException ){
            std::cout << "getNetMessages - Exception: " << theException.what() << std::endl;
         }
      }

      cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n";

   }


   // shut down the network
   network.closeSocket();
   
   delete HostSn;
   
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
   
   
   
   
   TiXmlDocument doc("HostRcvCcl.def");
   bool stat = doc.LoadFile();
   
   //set default values
   Port_H2IG = 8000;
   Port_IG2H = 8001;
   IGAddr = "127.0.0.1";
  
   MajorVer = 3;
   MinorVer = 3;

   PrtSOF = false;


   
   if(stat)
   {
      bnode = doc.FirstChild("HostCclReceiverInitialization");
      
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
         

         CfgDta = hConfig->FirstChildElement("IG_Addr").Child(0).Text();
         if(CfgDta)
            IGAddr = CfgDta->Value();

         CfgDta = hConfig->FirstChildElement("Port_To_IG").Child(0).Text();
         Port_H2IG = (CfgDta) ? atoi(CfgDta->Value()) : 8000;
         
         CfgDta = hConfig->FirstChildElement("Port_To_Host").Child(0).Text();
         Port_IG2H = (CfgDta) ? atoi(CfgDta->Value()) : 8001;

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


         CfgDta = hConfig->FirstChildElement("Print_SOF").Child(0).Text();
         PrtSOF = (memcmp((void *)CfgDta->Value(),"true",4) == 0) ? true : false;


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
   if(MajorVer == 3)
   {
      if(MinorVer < 2)
         pCIGC = &CIGC3;
      else
         pCIGC = &CIGC3_2;
   }
   else if(MajorVer == 2)
      pCIGC = &CIGC2;
   else if(MajorVer == 1)
      pCIGC = &CIGC1;

   
   // set up a default handler for unhandled packets
	Imsg.RegisterEventProcessor(0, (CigiBaseEventProcessor *) &DefaultPckt);

   // Register all the Event processors
   if(MajorVer == 1)
   {
      if(PrtSOF)
         Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_SOFV1);
      else
         Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_SOF);

      Imsg.RegisterEventProcessor(CIGI_HAT_RESP_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_HatRespV1);
      Imsg.RegisterEventProcessor(CIGI_LOS_RESP_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_LosRespV1);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_CollDetSegRespV1);
      Imsg.RegisterEventProcessor(CIGI_SENSOR_RESP_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_SensorRespV1);
   }
   else if(MajorVer == 2)
   {
      if(PrtSOF)
         Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_SOFV2);
      else
         Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_SOF);

      Imsg.RegisterEventProcessor(CIGI_HAT_RESP_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_HatRespV2);
      Imsg.RegisterEventProcessor(CIGI_LOS_RESP_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_LosRespV2);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_CollDetSegRespV2);
      Imsg.RegisterEventProcessor(CIGI_SENSOR_RESP_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_SensorRespV2);
      Imsg.RegisterEventProcessor(CIGI_HOT_RESP_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_HotRespV2);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_CollDetVolRespV2);
      Imsg.RegisterEventProcessor(CIGI_IG_MSG_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_IGMsgV2);
   }
   else
   {
      if(MajorVer != 3)
      {
         MajorVer = 3;
         MinorVer = 3;
      }
      else
      {
         if(MinorVer < 2)
            MinorVer = 0;
         else if(MinorVer > 3)
            MinorVer = 3;
      }

      if(MinorVer < 2)
      {
         if(PrtSOF)
            Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_SOFV3);
         else
            Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_SOF);

         Imsg.RegisterEventProcessor(CIGI_HAT_HOT_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_HatHotRespV3);
         Imsg.RegisterEventProcessor(CIGI_HAT_HOT_XRESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_HatHotXRespV3);
         Imsg.RegisterEventProcessor(CIGI_LOS_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_LosRespV3);
         Imsg.RegisterEventProcessor(CIGI_LOS_XRESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_LosXRespV3);
      }
      else
      {
         if(PrtSOF)
            Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_SOFV3_2);
         else
            Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_SOF);

         Imsg.RegisterEventProcessor(CIGI_HAT_HOT_RESP_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_HatHotRespV3_2);
         Imsg.RegisterEventProcessor(CIGI_HAT_HOT_XRESP_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_HatHotXRespV3_2);
         Imsg.RegisterEventProcessor(CIGI_LOS_RESP_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_LosRespV3_2);
         Imsg.RegisterEventProcessor(CIGI_LOS_XRESP_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_LosXRespV3_2);
      }

      Imsg.RegisterEventProcessor(CIGI_SENSOR_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_SensorRespV3);
      Imsg.RegisterEventProcessor(CIGI_SENSOR_XRESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_SensorXRespV3);
      Imsg.RegisterEventProcessor(CIGI_POSITION_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_PositionRespV3);
      Imsg.RegisterEventProcessor(CIGI_WEATHER_COND_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_WeatherCondRespV3);
      Imsg.RegisterEventProcessor(CIGI_AEROSOL_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_AerosolRespV3);
      Imsg.RegisterEventProcessor(CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_MaritimeSurfaceRespV3);
      Imsg.RegisterEventProcessor(CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_TerrestrialSurfaceRespV3);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_CollDetSegRespV3);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_CollDetVolRespV3);
      Imsg.RegisterEventProcessor(CIGI_ANIMATION_STOP_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_AnimationStopV3);
      Imsg.RegisterEventProcessor(CIGI_EVENT_NOTIFICATION_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_EventNotificationV3);
      Imsg.RegisterEventProcessor(CIGI_IG_MSG_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_IGMsgV3);


   }


   // initialize the IG Control
   pCIGC->SetDatabaseID(0,false);
   pCIGC->SetIGMode(CigiBaseIGCtrl::Operate);
   CIGC3.SetTimeStampValid(false);
   CIGC3_2.SetTimeStampValid(false);


   return err_status;
}






