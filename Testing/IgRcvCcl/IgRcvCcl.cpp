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
 *  FILENAME:   IgRcvCcl.cpp
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
#include <CigiIGCtrlV3_2.h>
#include <CigiSOFV3_2.h>

// Handling routines
#include "DefaultProc.h"

#include "XArtPartCtrlV1.h"
#include "XArtPartCtrlV2.h"
#include "XArtPartCtrlV3.h"
#include "XAtmosCtrlV3.h"
#include "XCelestialCtrlV3.h"
#include "XCollDetSegDefV1.h"
#include "XCollDetSegDefV2.h"
#include "XCollDetSegDefV3.h"
#include "XCollDetVolDefV2.h"
#include "XCollDetVolDefV3.h"
#include "XCompCtrlV1.h"
#include "XCompCtrlV2.h"
#include "XCompCtrlV3.h"
#include "XConfClampEntityCtrlV3.h"
#include "XEarthModelDefV3.h"
#include "XEntityCtrlV1.h"
#include "XEntityCtrlV2.h"
#include "XEntityCtrlV3.h"
#include "XEntityCtrlV3_3.h"
#include "XEnvCondReqV3.h"
#include "XEnvRgnCtrlV3.h"
#include "XEventNotificationV3.h"
#include "XHatHotReqV3.h"
#include "XHatHotReqV3_2.h"
#include "XIGCtrl.h"
#include "XIGCtrlV1.h"
#include "XIGCtrlV2.h"
#include "XIGCtrlV3.h"
#include "XIGCtrlV3_2.h"
#include "XIGCtrlV3_3.h"
#include "XLosSegReqV1.h"
#include "XLosSegReqV2.h"
#include "XLosSegReqV3.h"
#include "XLosSegReqV3_2.h"
#include "XLosVectReqV1.h"
#include "XLosVectReqV2.h"
#include "XLosVectReqV3.h"
#include "XLosVectReqV3_2.h"
#include "XMaritimeSurfaceCtrlV3.h"
#include "XMotionTrackCtrlV3.h"
#include "XPositionReqV3.h"
#include "XRateCtrlV1.h"
#include "XRateCtrlV2.h"
#include "XRateCtrlV3.h"
#include "XRateCtrlV3_2.h"
#include "XSensorCtrlV1.h"
#include "XSensorCtrlV2.h"
#include "XSensorCtrlV3.h"
#include "XShortArtPartCtrlV3.h"
#include "XShortCompCtrlV3.h"
#include "XTerrestrialSurfaceCtrlV3.h"
#include "XTrajectoryV1.h"
#include "XTrajectoryV2.h"
#include "XTrajectoryV3.h"
#include "XViewCtrlV1.h"
#include "XViewCtrlV2.h"
#include "XViewCtrlV3.h"
#include "XViewDefV1.h"
#include "XViewDefV2.h"
#include "XViewDefV3.h"
#include "XWaveCtrlV3.h"
#include "XWeatherCtrlV1.h"
#include "XWeatherCtrlV2.h"
#include "XWeatherCtrlV3.h"

#include "XEnvCtrlV1.h"
#include "XEnvCtrlV2.h"
#include "XSpecEffDefV1.h"
#include "XSpecEffDefV2.h"
#include "XHatReqV1.h"
#include "XHatReqV2.h"
#include "XHotReqV2.h"

#include "XCompCtrlV3_3.h"
#include "XShortCompCtrlV3_3.h"
#include "XSymbolSurfaceDefV3_3.h"
#include "XSymbolCtrlV3_3.h"
#include "XShortSymbolCtrlV3_3.h"
#include "XSymbolTextDefV3_3.h"
#include "XSymbolCircleDefV3_3.h"
#include "XSymbolLineDefV3_3.h"
#include "XSymbolCloneV3_3.h"


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
static CigiSOFV3_2 CSOF;



static XArtPartCtrlV1 Pr_ArtPartCtrlV1;
static XArtPartCtrlV2 Pr_ArtPartCtrlV2;
static XArtPartCtrlV3 Pr_ArtPartCtrlV3;
static XAtmosCtrlV3 Pr_AtmosCtrlV3;
static XCelestialCtrlV3 Pr_CelestialCtrlV3;
static XCollDetSegDefV1 Pr_CollDetSegDefV1;
static XCollDetSegDefV2 Pr_CollDetSegDefV2;
static XCollDetSegDefV3 Pr_CollDetSegDefV3;
static XCollDetVolDefV2 Pr_CollDetVolDefV2;
static XCollDetVolDefV3 Pr_CollDetVolDefV3;
static XCompCtrlV1 Pr_CompCtrlV1;
static XCompCtrlV2 Pr_CompCtrlV2;
static XCompCtrlV3 Pr_CompCtrlV3;
static XConfClampEntityCtrlV3 Pr_ConfClampEntityCtrlV3;
static XEarthModelDefV3 Pr_EarthModelDefV3;
static XEntityCtrlV1 Pr_EntityCtrlV1;
static XEntityCtrlV2 Pr_EntityCtrlV2;
static XEntityCtrlV3 Pr_EntityCtrlV3;
static XEntityCtrlV3_3 Pr_EntityCtrlV3_3;
static XEnvCondReqV3 Pr_EnvCondReqV3;
static XEnvRgnCtrlV3 Pr_EnvRgnCtrlV3;
static XEventNotificationV3 Pr_EventNotificationV3;
static XHatHotReqV3 Pr_HatHotReqV3;
static XHatHotReqV3_2 Pr_HatHotReqV3_2;
static XIGCtrl Pr_IGCtrl;
static XIGCtrlV1 Pr_IGCtrlV1;
static XIGCtrlV2 Pr_IGCtrlV2;
static XIGCtrlV3 Pr_IGCtrlV3;
static XIGCtrlV3_2 Pr_IGCtrlV3_2;
static XIGCtrlV3_3 Pr_IGCtrlV3_3;
static XLosSegReqV1 Pr_LosSegReqV1;
static XLosSegReqV2 Pr_LosSegReqV2;
static XLosSegReqV3 Pr_LosSegReqV3;
static XLosSegReqV3_2 Pr_LosSegReqV3_2;
static XLosVectReqV1 Pr_LosVectReqV1;
static XLosVectReqV2 Pr_LosVectReqV2;
static XLosVectReqV3 Pr_LosVectReqV3;
static XLosVectReqV3_2 Pr_LosVectReqV3_2;
static XMaritimeSurfaceCtrlV3 Pr_MaritimeSurfaceCtrlV3;
static XMotionTrackCtrlV3 Pr_MotionTrackCtrlV3;
static XPositionReqV3 Pr_PositionReqV3;
static XRateCtrlV1 Pr_RateCtrlV1;
static XRateCtrlV2 Pr_RateCtrlV2;
static XRateCtrlV3 Pr_RateCtrlV3;
static XRateCtrlV3_2 Pr_RateCtrlV3_2;
static XSensorCtrlV1 Pr_SensorCtrlV1;
static XSensorCtrlV2 Pr_SensorCtrlV2;
static XSensorCtrlV3 Pr_SensorCtrlV3;
static XShortArtPartCtrlV3 Pr_ShortArtPartCtrlV3;
static XShortCompCtrlV3 Pr_ShortCompCtrlV3;
static XTerrestrialSurfaceCtrlV3 Pr_TerrestrialSurfaceCtrlV3;
static XTrajectoryV1 Pr_TrajectoryV1;
static XTrajectoryV2 Pr_TrajectoryV2;
static XTrajectoryV3 Pr_TrajectoryV3;
static XViewCtrlV1 Pr_ViewCtrlV1;
static XViewCtrlV2 Pr_ViewCtrlV2;
static XViewCtrlV3 Pr_ViewCtrlV3;
static XViewDefV1 Pr_ViewDefV1;
static XViewDefV2 Pr_ViewDefV2;
static XViewDefV3 Pr_ViewDefV3;
static XWaveCtrlV3 Pr_WaveCtrlV3;
static XWeatherCtrlV1 Pr_WeatherCtrlV1;
static XWeatherCtrlV2 Pr_WeatherCtrlV2;
static XWeatherCtrlV3 Pr_WeatherCtrlV3;


static XEnvCtrlV1 Pr_EnvCtrlV1;
static XEnvCtrlV2 Pr_EnvCtrlV2;
static XSpecEffDefV1 Pr_SpecEffDefV1;
static XSpecEffDefV2 Pr_SpecEffDefV2;
static XHatReqV1 Pr_HatReqV1;
static XHatReqV2 Pr_HatReqV2;
static XHotReqV2 Pr_HotReqV2;


static XCompCtrlV3_3 Pr_CompCtrlV3_3;
static XShortCompCtrlV3_3 Pr_ShortCompCtrlV3_3;
static XSymbolSurfaceDefV3_3 Pr_SymbolSurfaceDefV3_3;
static XSymbolCtrlV3_3 Pr_SymbolCtrlV3_3;
static XShortSymbolCtrlV3_3 Pr_ShortSymbolCtrlV3_3;
static XSymbolTextDefV3_3 Pr_SymbolTextDefV3_3;
static XSymbolCircleDefV3_3 Pr_SymbolCircleDefV3_3;
static XSymbolLineDefV3_3 Pr_SymbolLineDefV3_3;
static XSymbolCloneV3_3 Pr_SymbolCloneV3_3;




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
static bool PrtIgCtrl;

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


      // load the IG Control
      Omsg << CSOF;



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
		cout << check_SOF.GetFrameCntr() << endl;


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

   PrtIgCtrl = false;


   
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


         CfgDta = hConfig->FirstChildElement("Print_IGCtrl").Child(0).Text();
         PrtIgCtrl = (memcmp((void *)CfgDta->Value(),"true",4) == 0) ? true : false;


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

   IGSn->SetCigiVersion(MajorVer,MinorVer);
   IGSn->SetSynchronous(true);
   
   Imsg.SetReaderCigiVersion(MajorVer,MinorVer);
   Imsg.UsingIteration(false);
   
   // set up a default handler for unhandled packets
   Imsg.RegisterEventProcessor(0, (CigiBaseEventProcessor *) &DefaultPckt);

   // Register all the Event processors
   if(MajorVer == 1)
   {
      if(PrtIgCtrl)
         Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_IGCtrlV1);
      else
         Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_IGCtrl);
      Imsg.RegisterEventProcessor(CIGI_ENTITY_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_EntityCtrlV1);
      Imsg.RegisterEventProcessor(CIGI_COMP_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_CompCtrlV1);
      Imsg.RegisterEventProcessor(CIGI_ART_PART_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_ArtPartCtrlV1);
      Imsg.RegisterEventProcessor(CIGI_RATE_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_RateCtrlV1);
      Imsg.RegisterEventProcessor(CIGI_ENV_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_EnvCtrlV1);
      Imsg.RegisterEventProcessor(CIGI_WEATHER_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_WeatherCtrlV1);
      Imsg.RegisterEventProcessor(CIGI_VIEW_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_ViewCtrlV1);
      Imsg.RegisterEventProcessor(CIGI_SENSOR_CTRL_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_SensorCtrlV1);
      Imsg.RegisterEventProcessor(CIGI_TRAJECTORY_DEF_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_TrajectoryV1);
      Imsg.RegisterEventProcessor(CIGI_SPEC_EFF_DEF_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_SpecEffDefV1);
      Imsg.RegisterEventProcessor(CIGI_VIEW_DEF_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_ViewDefV1);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_CollDetSegDefV1);
      Imsg.RegisterEventProcessor(CIGI_HAT_REQ_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_HatReqV1);
      Imsg.RegisterEventProcessor(CIGI_LOS_SEG_REQ_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_LosSegReqV1);
      Imsg.RegisterEventProcessor(CIGI_LOS_VECT_REQ_PACKET_ID_V1,(CigiBaseEventProcessor *) &Pr_LosVectReqV1);
   }
   else if(MajorVer == 2)
   {
      if(PrtIgCtrl)
         Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_IGCtrlV2);
      else
         Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_IGCtrl);
      Imsg.RegisterEventProcessor(CIGI_ENTITY_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_EntityCtrlV2);
      Imsg.RegisterEventProcessor(CIGI_COMP_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_CompCtrlV2);
      Imsg.RegisterEventProcessor(CIGI_ART_PART_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_ArtPartCtrlV2);
      Imsg.RegisterEventProcessor(CIGI_RATE_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_RateCtrlV2);
      Imsg.RegisterEventProcessor(CIGI_ENV_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_EnvCtrlV2);
      Imsg.RegisterEventProcessor(CIGI_WEATHER_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_WeatherCtrlV2);
      Imsg.RegisterEventProcessor(CIGI_VIEW_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_ViewCtrlV2);
      Imsg.RegisterEventProcessor(CIGI_SENSOR_CTRL_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_SensorCtrlV2);
      Imsg.RegisterEventProcessor(CIGI_TRAJECTORY_DEF_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_TrajectoryV2);
      Imsg.RegisterEventProcessor(CIGI_SPEC_EFF_DEF_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_SpecEffDefV2);
      Imsg.RegisterEventProcessor(CIGI_VIEW_DEF_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_ViewDefV2);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_CollDetSegDefV2);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_CollDetVolDefV2);
      Imsg.RegisterEventProcessor(CIGI_HAT_REQ_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_HatReqV2);
      Imsg.RegisterEventProcessor(CIGI_HOT_REQ_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_HotReqV2);
      Imsg.RegisterEventProcessor(CIGI_LOS_SEG_REQ_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_LosSegReqV2);
      Imsg.RegisterEventProcessor(CIGI_LOS_VECT_REQ_PACKET_ID_V2,(CigiBaseEventProcessor *) &Pr_LosVectReqV2);
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
         if(PrtIgCtrl)
            Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_IGCtrlV3);
         else
            Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_IGCtrl);
         Imsg.RegisterEventProcessor(CIGI_ENTITY_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_EntityCtrlV3);
         Imsg.RegisterEventProcessor(CIGI_RATE_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_RateCtrlV3);
         Imsg.RegisterEventProcessor(CIGI_HAT_HOT_REQ_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_HatHotReqV3);
         Imsg.RegisterEventProcessor(CIGI_LOS_SEG_REQ_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_LosSegReqV3);
         Imsg.RegisterEventProcessor(CIGI_LOS_VECT_REQ_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_LosVectReqV3);
         Imsg.RegisterEventProcessor(CIGI_COMP_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_CompCtrlV3);
         Imsg.RegisterEventProcessor(CIGI_SHORT_COMP_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_ShortCompCtrlV3);
      }
      else
      {
         if(PrtIgCtrl)
         {
            if(MinorVer < 3)
               Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_IGCtrlV3_2);
            else
               Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_IGCtrlV3_3);
         }
         else
            Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_IGCtrl);

         Imsg.RegisterEventProcessor(CIGI_RATE_CTRL_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_RateCtrlV3_2);
         Imsg.RegisterEventProcessor(CIGI_HAT_HOT_REQ_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_HatHotReqV3_2);
         Imsg.RegisterEventProcessor(CIGI_LOS_SEG_REQ_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_LosSegReqV3_2);
         Imsg.RegisterEventProcessor(CIGI_LOS_VECT_REQ_PACKET_ID_V3_2,(CigiBaseEventProcessor *) &Pr_LosVectReqV3_2);
         if(MinorVer < 3)
         {
            Imsg.RegisterEventProcessor(CIGI_ENTITY_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_EntityCtrlV3);
            Imsg.RegisterEventProcessor(CIGI_COMP_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_CompCtrlV3);
            Imsg.RegisterEventProcessor(CIGI_SHORT_COMP_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_ShortCompCtrlV3);
         }
         else
         {
            Imsg.RegisterEventProcessor(CIGI_ENTITY_CTRL_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_EntityCtrlV3_3);
            Imsg.RegisterEventProcessor(CIGI_COMP_CTRL_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_CompCtrlV3_3);
            Imsg.RegisterEventProcessor(CIGI_SHORT_COMP_CTRL_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_ShortCompCtrlV3_3);
            Imsg.RegisterEventProcessor(CIGI_SYMBOL_SURFACE_DEF_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_SymbolSurfaceDefV3_3);
            Imsg.RegisterEventProcessor(CIGI_SYMBOL_CONTROL_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_SymbolCtrlV3_3);
            Imsg.RegisterEventProcessor(CIGI_SHORT_SYMBOL_CONTROL_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_ShortSymbolCtrlV3_3);
            Imsg.RegisterEventProcessor(CIGI_SYMBOL_TEXT_DEFINITION_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_SymbolTextDefV3_3);
            Imsg.RegisterEventProcessor(CIGI_SYMBOL_CIRCLE_DEFINITION_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_SymbolCircleDefV3_3);
            Imsg.RegisterEventProcessor(CIGI_SYMBOL_LINE_DEFINITION_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_SymbolLineDefV3_3);
            Imsg.RegisterEventProcessor(CIGI_SYMBOL_CLONE_PACKET_ID_V3_3,(CigiBaseEventProcessor *) &Pr_SymbolCloneV3_3);
         }
      }




      Imsg.RegisterEventProcessor(CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_ConfClampEntityCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_ART_PART_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_ArtPartCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_ShortArtPartCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_CELESTIAL_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_CelestialCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_ATMOS_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_AtmosCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_ENV_RGN_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_EnvRgnCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_WEATHER_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_WeatherCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_MaritimeSurfaceCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_WAVE_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_WaveCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_TerrestrialSurfaceCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_VIEW_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_ViewCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_SENSOR_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_SensorCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_MotionTrackCtrlV3);
      Imsg.RegisterEventProcessor(CIGI_EARTH_MODEL_DEF_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_EarthModelDefV3);
      Imsg.RegisterEventProcessor(CIGI_TRAJECTORY_DEF_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_TrajectoryV3);
      Imsg.RegisterEventProcessor(CIGI_VIEW_DEF_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_ViewDefV3);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_CollDetSegDefV3);
      Imsg.RegisterEventProcessor(CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_CollDetVolDefV3);
      Imsg.RegisterEventProcessor(CIGI_POSITION_REQ_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_PositionReqV3);
      Imsg.RegisterEventProcessor(CIGI_ENV_COND_REQ_PACKET_ID_V3,(CigiBaseEventProcessor *) &Pr_EnvCondReqV3);
   }


   // initialize the SOF
   CSOF.SetDatabaseID(1);
   CSOF.SetIGStatus(0);
   CSOF.SetIGMode(CigiBaseSOF::Operate);
   CSOF.SetTimeStampValid(false);
   CSOF.SetEarthRefModel(CigiBaseSOF::WGS84);
   CSOF.SetTimeStamp(0);
   CSOF.SetFrameCntr(0);
   
   
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


