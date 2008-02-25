/** <pre>
 *  The CIGI Dummy IG
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
 *  FILENAME:   DummyIG.cpp
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
#include <CigiIGSession.h>
#include <CigiExceptions.h>
#include <CigiIGCtrlV3_2.h>
#include <CigiSOFV3_2.h>

// Handling routines
#include "DefaultProc.h"

#include "XIGCtrl.h"
#include "XEntityCtrl.h"
#include "XConfClampEntityCtrl.h"
#include "XCompCtrl.h"
#include "XShortCompCtrl.h"
#include "XArtPartCtrl.h"
#include "XShortArtPartCtrl.h"
#include "XRateCtrl.h"
#include "XCelestialCtrl.h"
#include "XAtmosCtrl.h"
#include "XEnvRgnCtrl.h"
#include "XWeatherCtrl.h"
#include "XMaritimeSurfaceCtrl.h"
#include "XWaveCtrl.h"
#include "XTerrestrialSurfaceCtrl.h"
#include "XViewCtrl.h"
#include "XSensorCtrl.h"
#include "XMotionTrackCtrl.h"
#include "XEarthModelDef.h"
#include "XTrajectory.h"
#include "XViewDef.h"
#include "XCollDetSegDef.h"
#include "XCollDetVolDef.h"
#include "XHatHotReq.h"
#include "XLosSegReq.h"
#include "XLosVectReq.h"
#include "XPostionReq.h"
#include "XEnvCondReq.h"


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
static CigiVersionJumpTable *pVJmp;
static CigiOutgoingMsg *OmsgPtr;
static CigiIncomingMsg *ImsgPtr;
static DefaultProc DefaultPckt;
static CigiSOFV3_2 CSOF;

static XIGCtrl Pr_IGCtrl;
static XEntityCtrl Pr_EntityCtrl;
static XConfClampEntityCtrl Pr_ConfClampEntityCtrl;
static XCompCtrl Pr_CompCtrl;
static XShortCompCtrl Pr_ShortCompCtrl;
static XArtPartCtrl Pr_ArtPartCtrl;
static XShortArtPartCtrl Pr_ShortArtPartCtrl;
static XRateCtrl Pr_RateCtrl;
static XCelestialCtrl Pr_CelestialCtrl;
static XAtmosCtrl Pr_AtmosCtrl;
static XEnvRgnCtrl Pr_EnvRgnCtrl;
static XWeatherCtrl Pr_WeatherCtrl;
static XMaritimeSurfaceCtrl Pr_MaritimeSurfaceCtrl;
static XWaveCtrl Pr_WaveCtrl;
static XTerrestrialSurfaceCtrl Pr_TerrestrialSurfaceCtrl;
static XViewCtrl Pr_ViewCtrl;
static XSensorCtrl Pr_SensorCtrl;
static XMotionTrackCtrl Pr_MotionTrackCtrl;
static XEarthModelDef Pr_EarthModelDef;
static XTrajectory Pr_Trajectory;
static XViewDef Pr_ViewDef;
static XCollDetSegDef Pr_CollDetSegDef;
static XCollDetVolDef Pr_CollDetVolDef;
static XHatHotReq Pr_HatHotReq;
static XLosSegReq Pr_LosSegReq;
static XLosVectReq Pr_LosVectReq;
static XPositionReq Pr_PositionReq;
static XEnvCondReq Pr_EnvCondReq;







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
      cout << "Frame: " << pVJmp->GetFrameCnt() << endl;
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
   
   TiXmlText *Port_To_IG = NULL;
   TiXmlText *Port_To_Host = NULL;
   TiXmlText *Host_Addr = NULL;
   TiXmlText *Hertz_rate = NULL;
   
   TiXmlHandle *hConfig = NULL; // pointer to a Config handle
   
   TiXmlElement *Config = NULL;
   
   TiXmlText *DbDta = NULL;
   
   
   
   
   TiXmlDocument doc("CigiDummyIG.def");
   bool stat = doc.LoadFile();
   
   //set default values
   Port_H2IG = 8000;
   Port_IG2H = 8001;
   HostAddr = "127.0.0.1";
  
   
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
         
         
         Host_Addr = hConfig->FirstChildElement("Host_Addr").Child(0).Text();
         if(Host_Addr)
            HostAddr = Host_Addr->Value();
         
         Port_To_IG = hConfig->FirstChildElement("Port_To_IG").Child(0).Text();
         Port_H2IG = (Port_To_IG) ? atoi(Port_To_IG->Value()) : 8000;
         
         Port_To_Host = hConfig->FirstChildElement("Port_To_Host").Child(0).Text();
         Port_IG2H = (Port_To_Host) ? atoi(Port_To_Host->Value()) : 8001;

         Hertz_rate = hConfig->FirstChildElement("Hertz_rate").Child(0).Text();
         Hz = (Hertz_rate) ? atoi(Hertz_rate->Value()) : 60;
         timeDelayLimit = 1.0/((float)Hz);

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
 
   CigiVersionJumpTable &VJmp = IGSn->GetVersionJumpTableMgr();
	pVJmp = &VJmp;
 
   CigiOutgoingMsg &Omsg = IGSn->GetOutgoingMsgMgr();
   CigiIncomingMsg &Imsg = IGSn->GetIncomingMsgMgr();
   OmsgPtr = &Omsg;
   ImsgPtr = &Imsg;
   
   IGSn->SetCigiVersion(3,2);
   IGSn->SetSynchronous(true);
   
   Imsg.SetReaderCigiVersion(3,2);
   Imsg.UsingIteration(false);
   
   // set up a default handler for unhandled packets
   Imsg.RegisterEventProcessor(0, (CigiBaseEventProcessor *) &DefaultPckt);

   // Register all the Event processors
   Imsg.RegisterEventProcessor(CIGI_IG_CTRL_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) &Pr_IGCtrl);
   Imsg.RegisterEventProcessor(CIGI_ENTITY_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_EntityCtrl);
   Imsg.RegisterEventProcessor(CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ConfClampEntityCtrl);
   Imsg.RegisterEventProcessor(CIGI_COMP_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CompCtrl);
   Imsg.RegisterEventProcessor(CIGI_SHORT_COMP_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ShortCompCtrl);
   Imsg.RegisterEventProcessor(CIGI_ART_PART_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ArtPartCtrl);
   Imsg.RegisterEventProcessor(CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ShortArtPartCtrl);
   Imsg.RegisterEventProcessor(CIGI_RATE_CTRL_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) &Pr_RateCtrl);
   Imsg.RegisterEventProcessor(CIGI_CELESTIAL_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CelestialCtrl);
   Imsg.RegisterEventProcessor(CIGI_ATMOS_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_AtmosCtrl);
   Imsg.RegisterEventProcessor(CIGI_ENV_RGN_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_EnvRgnCtrl);
   Imsg.RegisterEventProcessor(CIGI_WEATHER_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_WeatherCtrl);
   Imsg.RegisterEventProcessor(CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_MaritimeSurfaceCtrl);
   Imsg.RegisterEventProcessor(CIGI_WAVE_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_WaveCtrl);
   Imsg.RegisterEventProcessor(CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_TerrestrialSurfaceCtrl);
   Imsg.RegisterEventProcessor(CIGI_VIEW_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ViewCtrl);
   Imsg.RegisterEventProcessor(CIGI_SENSOR_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_SensorCtrl);
   Imsg.RegisterEventProcessor(CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_MotionTrackCtrl);
   Imsg.RegisterEventProcessor(CIGI_EARTH_MODEL_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_EarthModelDef);
   Imsg.RegisterEventProcessor(CIGI_TRAJECTORY_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_Trajectory);
   Imsg.RegisterEventProcessor(CIGI_VIEW_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_ViewDef);
   Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CollDetSegDef);
   Imsg.RegisterEventProcessor(CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_CollDetVolDef);
   Imsg.RegisterEventProcessor(CIGI_HAT_HOT_REQ_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) &Pr_HatHotReq);
   Imsg.RegisterEventProcessor(CIGI_LOS_SEG_REQ_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) &Pr_LosSegReq);
   Imsg.RegisterEventProcessor(CIGI_LOS_VECT_REQ_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) &Pr_LosVectReq);
   Imsg.RegisterEventProcessor(CIGI_POSITION_REQ_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_PositionReq);
   Imsg.RegisterEventProcessor(CIGI_ENV_COND_REQ_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) &Pr_EnvCondReq);




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






