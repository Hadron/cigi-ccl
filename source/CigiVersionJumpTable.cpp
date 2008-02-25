/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2005 The Boeing Company
 *  
 *  This library is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU Lesser General Public License as published by 
 *  the Free Software Foundation; either version 2.1 of the License, or (at 
 *  your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more 
 *  details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License 
 *  along with this library; if not, write to the Free Software Foundation, 
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *  
 *  FILENAME:   CigiVersionJumpTable.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Common Image Generator Interface (CIGI) SDK
 *  
 *  PROGRAM DESCRIPTION: 
 *  ...
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  09/17/2003 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Defined _EXPORT_CCL_ for exporting the class in a Windows DLL.
 *  
 *  04/06/2005 Greg Basler                       Version 1.5.2
 *  Fixed an error in the RegisterUserPacket function to properly handle 
 *  user-defined packets when translating between different versions of CIGI.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Updated the class to support CIGI version 3.2.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the CIGI_IG_CONTROL_SIZE_V3_2 and CIGI_START_OF_FRAME_SIZE_V3_2 
 *  preprocessor definitions.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the class constructor to intialize the OutoingMsg member variable 
 *  to NULL. And to set the CIGI and CIGI reader versions to 3.2.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Implemented the overloaded SetCigiVersion and SetReaderCigiVersion methods 
 *  to accept a CigiMinorVersionIn parameter and handle minor version numbers.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Implemented the overloaded SetJmpTblV3 method for compatability with CIGI 
 *  version 3.2.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.4
 *  Removed redundant line in SetJmpTblV3 about CigiLosVectReqV3_2.  This was
 *  causing a memory leak over time.
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.7.5
 */

#define _EXPORT_CCL_

#include <memory.h>

#include "CigiExceptions.h"

#include "CigiVersionJumpTable.h"

#include "CigiOutgoingMsg.h"

// ===============================
// packets
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

// IG control
#include "CigiIGCtrlV1.h"
#include "CigiIGCtrlV2.h"
#include "CigiIGCtrlV3.h"
#include "CigiIGCtrlV3_2.h"

// Entity control
#include "CigiEntityCtrlV1.h"
#include "CigiEntityCtrlV2.h"
#include "CigiEntityCtrlV3.h"

// View Definition
#include "CigiViewDefV1.h"
#include "CigiViewDefV2.h"
#include "CigiViewDefV3.h"

// View Control
#include "CigiViewCtrlV1.h"
#include "CigiViewCtrlV2.h"
#include "CigiViewCtrlV3.h"

// Rate Control
#include "CigiRateCtrlV1.h"
#include "CigiRateCtrlV2.h"
#include "CigiRateCtrlV3.h"
#include "CigiRateCtrlV3_2.h"

// Sensor Control
#include "CigiSensorCtrlV1.h"
#include "CigiSensorCtrlV2.h"
#include "CigiSensorCtrlV3.h"

// Trajectory Definition
#include "CigiTrajectoryDefV1.h"
#include "CigiTrajectoryDefV2.h"
#include "CigiTrajectoryDefV3.h"

// Weather Control
#include "CigiWeatherCtrlV1.h"
#include "CigiWeatherCtrlV2.h"
#include "CigiWeatherCtrlV3.h"

// Collision Detection Segment Definition
#include "CigiCollDetSegDefV1.h"
#include "CigiCollDetSegDefV2.h"
#include "CigiCollDetSegDefV3.h"

// LOS Segment Request
#include "CigiLosSegReqV1.h"
#include "CigiLosSegReqV2.h"
#include "CigiLosSegReqV3.h"
#include "CigiLosSegReqV3_2.h"

// LOS Vector Request
#include "CigiLosVectReqV1.h"
#include "CigiLosVectReqV2.h"
#include "CigiLosVectReqV3.h"
#include "CigiLosVectReqV3_2.h"

// Hat Hot Request
#include "CigiHatReqV1.h"
#include "CigiHatReqV2.h"
#include "CigiHotReqV2.h"
#include "CigiHatHotReqV3.h"
#include "CigiHatHotReqV3_2.h"

// Environmental Control
#include "CigiEnvCtrlV1.h"
#include "CigiEnvCtrlV2.h"
#include "CigiAtmosCtrl.h"
#include "CigiCelestialCtrl.h"

// Special Effect Definision
#include "CigiSpecEffDefV1.h"
#include "CigiSpecEffDefV2.h"

// Articulated Part Control
#include "CigiArtPartCtrlV1.h"
#include "CigiArtPartCtrlV2.h"
#include "CigiArtPartCtrlV3.h"

// Collision Detection Volume Definition
#include "CigiCollDetVolDefV2.h"
#include "CigiCollDetVolDefV3.h"

// Short Articulated Part Control
#include "CigiShortArtPartCtrlV3.h"

// Conformal Clamped Entity Control
#include "CigiConfClampEntityCtrlV3.h"

// Maritime Surface Conditions Control
#include "CigiMaritimeSurfaceCtrlV3.h"

// Environmental Region Control
#include "CigiEnvRgnCtrlV3.h"

// Terrestrial Surface Control
#include "CigiTerrestrialSurfaceCtrlV3.h"

// Motion Tracker control
#include "CigiMotionTrackCtrlV3.h"

// Earth Model Definition
#include "CigiEarthModelDefV3.h"

// Positon Request
#include "CigiPositionReqV3.h"

// Environmental Conditions Request
#include "CigiEnvCondReqV3.h"

// Wave Control
#include "CigiWaveCtrlV3.h"

// Start Of Frame
#include "CigiSOFV1.h"
#include "CigiSOFV2.h"
#include "CigiSOFV3.h"
#include "CigiSOFV3_2.h"

// Collision Detection Segment Response
#include "CigiCollDetSegRespV1.h"
#include "CigiCollDetSegRespV2.h"
#include "CigiCollDetSegRespV3.h"

// Sensor Response
#include "CigiSensorRespV1.h"
#include "CigiSensorRespV2.h"
#include "CigiSensorRespV3.h"

// Sensor Extended Response
#include "CigiSensorXRespV3.h"

// Los Response
#include "CigiLosRespV1.h"
#include "CigiLosRespV2.h"
#include "CigiLosRespV3.h"
#include "CigiLosRespV3_2.h"

// Los Extended Response
#include "CigiLosXRespV3.h"
#include "CigiLosXRespV3_2.h"

// Hat Hot Response
#include "CigiHatRespV1.h"
#include "CigiHatRespV2.h"
#include "CigiHotRespV2.h"
#include "CigiHatHotRespV3.h"
#include "CigiHatHotXRespV3.h"
#include "CigiHatHotRespV3_2.h"
#include "CigiHatHotXRespV3_2.h"

// Collision Detection Volume Response
#include "CigiCollDetVolRespV2.h"
#include "CigiCollDetVolRespV3.h"

// Position Response
#include "CigiPositionRespV3.h"

// Weather Condition Response
#include "CigiWeatherCondRespV3.h"

// Aerosol Resp
#include "CigiAerosolRespV3.h"

// Maritime Surface Response
#include "CigiMaritimeSurfaceRespV3.h"

// Terrestrial Surface Response
#include "CigiTerrestrialSurfaceRespV3.h"

// Animation Stop Notification
#include "CigiAnimationStopV3.h"

// Event Notification
#include "CigiEventNotificationV3.h"

// IG Message
#include "CigiIGMsgV2.h"
#include "CigiIGMsgV3.h"

// Component Control
#include "CigiCompCtrlV1.h"
#include "CigiCompCtrlV2.h"
#include "CigiCompCtrlV3.h"
#include "CigiShortCompCtrlV3.h"



// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#define CIGI_IG_CONTROL_SIZE_V1 16
#define CIGI_IG_CONTROL_SIZE_V2 16
#define CIGI_IG_CONTROL_SIZE_V3 16
#define CIGI_IG_CONTROL_SIZE_V3_2 24

#define CIGI_START_OF_FRAME_SIZE_V1  12
#define CIGI_START_OF_FRAME_SIZE_V2  16
#define CIGI_START_OF_FRAME_SIZE_V3  16
#define CIGI_START_OF_FRAME_SIZE_V3_2  24

// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiVersionJumpTable
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiVersionJumpTable::CigiVersionJumpTable(JumpTableType JmpTblType)
{

   JTblType = JmpTblType;

   OutgoingMsg = NULL;

   CigiVersion = CIGI_MAX_VERSION + 1;

   for(int ndx=0;ndx<255;ndx++)
   {
      JmpTbl[ndx] = (CigiBasePacket *)&DefaultPacket;

      memset(PacketIDMap,0,sizeof(PacketIDMap));

      VldSnd[ndx] = false;
      VldRcv[ndx] = false;

      memset(TotalPacketIDMap,0,sizeof(TotalPacketIDMap));
   }

   InitPacketIDMaps();

   SOFSize = 0;
   IGCtrlSize = 0;

   FrameCnt = 0;

   Synchronous = true;

   // At this point the Frame counter is the same type
   //   and position in all the IG Ctrl and SOF messages
   OutFrameBufPos = 2;

   // default initialize Cigi Versions
   CigiVersion = 10;
   ReaderCigiVersion = 10;
   SetCigiVersion(3,2,false);
   SetReaderCigiVersion(3,2,false);

}

// ================================================
// ~CigiVersionJumpTable
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiVersionJumpTable::~CigiVersionJumpTable()
{

   ClearTbls();
   ClearReaderTbls();

}



// ====================================================================
// Accessors
// ====================================================================

// ================================================
// SetCigiVersion
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVersionJumpTable::SetCigiVersion(const int CigiVersionIn,
                                         const int CigiMinorVersionIn,
                                         bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((CigiVersionIn < 1)||(CigiVersionIn > CIGI_MAX_VERSION)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("CigiVersion",CigiVersionIn,1,CIGI_MAX_VERSION);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   if((CigiVersionIn != CigiVersion) ||
      (CigiMinorVersionIn != CigiMinorVersion))
   {
      CigiVersion = CigiVersionIn;
      CigiMinorVersion = CigiMinorVersionIn;

      switch(CigiVersion)
      {
      case 1:
         ClearTbls();
         SetJmpTblV1();
         SetPacketIDMapsV1();
         SetVldTblsV1();
         SetProcTypeV1();
         IGCtrlSize = CIGI_IG_CONTROL_SIZE_V1;
         SOFSize = CIGI_START_OF_FRAME_SIZE_V1;
         if(OutgoingMsg != NULL)
            OutgoingMsg->Reset();
         break;
      case 2:
         ClearTbls();
         SetJmpTblV2();
         SetPacketIDMapsV2();
         SetVldTblsV2();
         SetProcTypeV2();
         IGCtrlSize = CIGI_IG_CONTROL_SIZE_V2;
         SOFSize = CIGI_START_OF_FRAME_SIZE_V2;
         if(OutgoingMsg != NULL)
            OutgoingMsg->Reset();
         break;
      case 3:
         ClearTbls();
         SetJmpTblV3(CigiMinorVersionIn);
         SetPacketIDMapsV3();
         SetVldTblsV3();
         SetProcTypeV3();
         if(CigiMinorVersionIn >= 2)
         {
            IGCtrlSize = CIGI_IG_CONTROL_SIZE_V3_2;
            SOFSize = CIGI_START_OF_FRAME_SIZE_V3_2;
         }
         else
         {
            IGCtrlSize = CIGI_IG_CONTROL_SIZE_V3;
            SOFSize = CIGI_START_OF_FRAME_SIZE_V3;
         }
         if(OutgoingMsg != NULL)
            OutgoingMsg->Reset();
         break;
      default:
         #ifndef CIGI_NO_EXCEPT
            throw CigiWrongVersionException();
         #endif

         return(CIGI_ERROR_WRONG_VERSION);
         break;
      }

      SetReaderPacketIDMaps(CigiVersion,ReaderCigiVersion);

   }

   return(CIGI_SUCCESS);

}

// ================================================
// SetReaderCigiVersion
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVersionJumpTable::SetReaderCigiVersion(const int CigiVersionIn,
                                               const int CigiMinorVersionIn,
                                               bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((CigiVersionIn < 1)||(CigiVersionIn > CIGI_MAX_VERSION)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("CigiVersion",CigiVersionIn,1,CIGI_MAX_VERSION);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   if((CigiVersionIn != ReaderCigiVersion) ||
      (CigiMinorVersionIn != ReaderCigiMinorVersion))
   {
      ReaderCigiVersion = CigiVersionIn;
      ReaderCigiMinorVersion = CigiMinorVersionIn;

      ClearReaderTbls();

      SetReaderPacketIDMaps(CigiVersion,ReaderCigiVersion);

      switch(ReaderCigiVersion)
      {
      case 1:
         SetSignalMapV1();
         break;
      case 2:
         SetSignalMapV2();
         break;
      case 3:
         SetSignalMapV3();
         break;
      default:
         #ifndef CIGI_NO_EXCEPT
            throw CigiWrongVersionException();
         #endif

         return(CIGI_ERROR_WRONG_VERSION);
         break;
      }

      switch(CigiVersion)
      {
      case 1:
         SetProcTypeV1();
         break;
      case 2:
         SetProcTypeV2();
         break;
      case 3:
         SetProcTypeV3();
         break;
      default:
         #ifndef CIGI_NO_EXCEPT
            throw CigiWrongVersionException();
         #endif

         return(CIGI_ERROR_WRONG_VERSION);
         break;
      }

   }

   return(CIGI_SUCCESS);

}


// ================================================
// ClearTbls
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::ClearTbls()
{

   for(int ndx=0;ndx<200;ndx++)
   {
      if(JmpTbl[ndx] != (CigiBasePacket *)&DefaultPacket)
      {
         delete JmpTbl[ndx];
         JmpTbl[ndx] = (CigiBasePacket *)&DefaultPacket;
         PacketIDMap[1][ndx] = 0;
         PacketIDMap[2][ndx] = 0;
         PacketIDMap[3][ndx] = 0;
         VldSnd[ndx] = false;
         VldRcv[ndx] = false;
      }
   }

}

// ================================================
// ClearReaderTbls
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::ClearReaderTbls()
{

   for(int ndx=0;ndx<200;ndx++)
   {
      PacketIDMap[0][ndx] = 0;
      SignalMap[ndx] = SigNone;
   }

}

// ================================================
// GetDEnvPcktHndlr
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
bool CigiVersionJumpTable::GetDEnvPcktHndlr(CigiBasePacket ** CelestHnd, CigiBasePacket ** AtmosHnd)
{
   bool vld;
   if(CigiVersion = 3)
   {
      *CelestHnd = JmpTbl[CIGI_CELESTIAL_CTRL_PACKET_ID_V3];
      *AtmosHnd = JmpTbl[CIGI_ATMOS_CTRL_PACKET_ID_V3];
      vld = true;
   }
   else
   {
      *CelestHnd = NULL;
      *AtmosHnd = NULL;
      vld = false;
   }

   return(vld);
}


// ================================================
// SetJmpTblV1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetJmpTblV1()
{

   JmpTbl[CIGI_IG_CTRL_PACKET_ID_V1] = (CigiBasePacket *) new CigiIGCtrlV1;
   JmpTbl[CIGI_ENTITY_CTRL_PACKET_ID_V1] = (CigiBasePacket *) new CigiEntityCtrlV1;
   JmpTbl[CIGI_VIEW_DEF_PACKET_ID_V1] = (CigiBasePacket *) new CigiViewDefV1;
   JmpTbl[CIGI_VIEW_CTRL_PACKET_ID_V1] = (CigiBasePacket *) new CigiViewCtrlV1;
   JmpTbl[CIGI_RATE_CTRL_PACKET_ID_V1] = (CigiBasePacket *) new CigiRateCtrlV1;
   JmpTbl[CIGI_SENSOR_CTRL_PACKET_ID_V1] = (CigiBasePacket *) new CigiSensorCtrlV1;
   JmpTbl[CIGI_TRAJECTORY_DEF_PACKET_ID_V1] = (CigiBasePacket *) new CigiTrajectoryDefV1;
   JmpTbl[CIGI_WEATHER_CTRL_PACKET_ID_V1] = (CigiBasePacket *) new CigiWeatherCtrlV1;
   JmpTbl[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1] = (CigiBasePacket *) new CigiCollDetSegDefV1;
   JmpTbl[CIGI_LOS_SEG_REQ_PACKET_ID_V1] = (CigiBasePacket *) new CigiLosSegReqV1;
   JmpTbl[CIGI_LOS_VECT_REQ_PACKET_ID_V1] = (CigiBasePacket *) new CigiLosVectReqV1;
   JmpTbl[CIGI_HAT_REQ_PACKET_ID_V1] = (CigiBasePacket *) new CigiHatReqV1;
   JmpTbl[CIGI_ENV_CTRL_PACKET_ID_V1] = (CigiBasePacket *) new CigiEnvCtrlV1;
   JmpTbl[CIGI_SPEC_EFF_DEF_PACKET_ID_V1] = (CigiBasePacket *) new CigiSpecEffDefV1;
   JmpTbl[CIGI_ART_PART_CTRL_PACKET_ID_V1] = (CigiBasePacket *) new CigiArtPartCtrlV1;
   JmpTbl[CIGI_COMP_CTRL_PACKET_ID_V1] = (CigiBasePacket *) new CigiCompCtrlV1;

   JmpTbl[CIGI_SOF_PACKET_ID_V1] = (CigiBasePacket *) new CigiSOFV1;
   JmpTbl[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1] = (CigiBasePacket *) new CigiCollDetSegRespV1;
   JmpTbl[CIGI_SENSOR_RESP_PACKET_ID_V1] = (CigiBasePacket *) new CigiSensorRespV1;
   JmpTbl[CIGI_LOS_RESP_PACKET_ID_V1] = (CigiBasePacket *) new CigiLosRespV1;
   JmpTbl[CIGI_HAT_RESP_PACKET_ID_V1] = (CigiBasePacket *) new CigiHatRespV1;

}

// ================================================
// SetJmpTblV2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetJmpTblV2()
{

   JmpTbl[CIGI_IG_CTRL_PACKET_ID_V2] = (CigiBasePacket *) new CigiIGCtrlV2;
   JmpTbl[CIGI_ENTITY_CTRL_PACKET_ID_V2] = (CigiBasePacket *) new CigiEntityCtrlV2;
   JmpTbl[CIGI_VIEW_DEF_PACKET_ID_V2] = (CigiBasePacket *) new CigiViewDefV2;
   JmpTbl[CIGI_VIEW_CTRL_PACKET_ID_V2] = (CigiBasePacket *) new CigiViewCtrlV2;
   JmpTbl[CIGI_RATE_CTRL_PACKET_ID_V2] = (CigiBasePacket *) new CigiRateCtrlV2;
   JmpTbl[CIGI_SENSOR_CTRL_PACKET_ID_V2] = (CigiBasePacket *) new CigiSensorCtrlV2;
   JmpTbl[CIGI_TRAJECTORY_DEF_PACKET_ID_V2] = (CigiBasePacket *) new CigiTrajectoryDefV2;
   JmpTbl[CIGI_WEATHER_CTRL_PACKET_ID_V2] = (CigiBasePacket *) new CigiWeatherCtrlV2;
   JmpTbl[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2] = (CigiBasePacket *) new CigiCollDetSegDefV2;
   JmpTbl[CIGI_LOS_SEG_REQ_PACKET_ID_V2] = (CigiBasePacket *) new CigiLosSegReqV2;
   JmpTbl[CIGI_LOS_VECT_REQ_PACKET_ID_V2] = (CigiBasePacket *) new CigiLosVectReqV2;
   JmpTbl[CIGI_HAT_REQ_PACKET_ID_V2] = (CigiBasePacket *) new CigiHatReqV2;
   JmpTbl[CIGI_HOT_REQ_PACKET_ID_V2] = (CigiBasePacket *) new CigiHotReqV2;
   JmpTbl[CIGI_ENV_CTRL_PACKET_ID_V2] = (CigiBasePacket *) new CigiEnvCtrlV2;
   JmpTbl[CIGI_SPEC_EFF_DEF_PACKET_ID_V2] = (CigiBasePacket *) new CigiSpecEffDefV2;
   JmpTbl[CIGI_ART_PART_CTRL_PACKET_ID_V2] = (CigiBasePacket *) new CigiArtPartCtrlV2;
   JmpTbl[CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2] = (CigiBasePacket *) new CigiCollDetVolDefV2;
   JmpTbl[CIGI_COMP_CTRL_PACKET_ID_V2] = (CigiBasePacket *) new CigiCompCtrlV2;

   JmpTbl[CIGI_SOF_PACKET_ID_V2] = (CigiBasePacket *) new CigiSOFV2;
   JmpTbl[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2] = (CigiBasePacket *) new CigiCollDetSegRespV2;
   JmpTbl[CIGI_SENSOR_RESP_PACKET_ID_V2] = (CigiBasePacket *) new CigiSensorRespV2;
   JmpTbl[CIGI_LOS_RESP_PACKET_ID_V2] = (CigiBasePacket *) new CigiLosRespV2;
   JmpTbl[CIGI_HAT_RESP_PACKET_ID_V2] = (CigiBasePacket *) new CigiHatRespV2;
   JmpTbl[CIGI_HOT_RESP_PACKET_ID_V2] = (CigiBasePacket *) new CigiHotRespV2;
   JmpTbl[CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2] = (CigiBasePacket *) new CigiCollDetVolRespV2;
   JmpTbl[CIGI_IG_MSG_PACKET_ID_V2] = (CigiBasePacket *) new CigiIGMsgV2;

}

// ================================================
// SetJmpTblV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetJmpTblV3(const int CigiMinorVersionIn)
{

   if(CigiMinorVersionIn >= 2)
   {
      JmpTbl[CIGI_IG_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiIGCtrlV3_2;
      JmpTbl[CIGI_RATE_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiRateCtrlV3_2;
      JmpTbl[CIGI_HAT_HOT_REQ_PACKET_ID_V3] = (CigiBasePacket *) new CigiHatHotReqV3_2;
      JmpTbl[CIGI_LOS_SEG_REQ_PACKET_ID_V3] = (CigiBasePacket *) new CigiLosSegReqV3_2;
      JmpTbl[CIGI_LOS_VECT_REQ_PACKET_ID_V3] = (CigiBasePacket *) new CigiLosVectReqV3_2;
      
      JmpTbl[CIGI_SOF_PACKET_ID_V3] = (CigiBasePacket *) new CigiSOFV3_2;
      JmpTbl[CIGI_LOS_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiLosRespV3_2;
      JmpTbl[CIGI_LOS_XRESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiLosXRespV3_2;
      JmpTbl[CIGI_HAT_HOT_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiHatHotRespV3_2;
      JmpTbl[CIGI_HAT_HOT_XRESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiHatHotXRespV3_2;
   }
   else
   {
      JmpTbl[CIGI_IG_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiIGCtrlV3;
      JmpTbl[CIGI_RATE_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiRateCtrlV3;
      JmpTbl[CIGI_HAT_HOT_REQ_PACKET_ID_V3] = (CigiBasePacket *) new CigiHatHotReqV3;
      JmpTbl[CIGI_LOS_SEG_REQ_PACKET_ID_V3] = (CigiBasePacket *) new CigiLosSegReqV3;
      JmpTbl[CIGI_LOS_VECT_REQ_PACKET_ID_V3] = (CigiBasePacket *) new CigiLosVectReqV3;
      
      JmpTbl[CIGI_SOF_PACKET_ID_V3] = (CigiBasePacket *) new CigiSOFV3;
      JmpTbl[CIGI_LOS_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiLosRespV3;
      JmpTbl[CIGI_LOS_XRESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiLosXRespV3;
      JmpTbl[CIGI_HAT_HOT_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiHatHotRespV3;
      JmpTbl[CIGI_HAT_HOT_XRESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiHatHotXRespV3;
   }

   JmpTbl[CIGI_ENTITY_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiEntityCtrlV3;
   JmpTbl[CIGI_VIEW_DEF_PACKET_ID_V3] = (CigiBasePacket *) new CigiViewDefV3;
   JmpTbl[CIGI_VIEW_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiViewCtrlV3;
   JmpTbl[CIGI_SENSOR_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiSensorCtrlV3;
   JmpTbl[CIGI_TRAJECTORY_DEF_PACKET_ID_V3] = (CigiBasePacket *) new CigiTrajectoryDefV3;
   JmpTbl[CIGI_WEATHER_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiWeatherCtrlV3;
   JmpTbl[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3] = (CigiBasePacket *) new CigiCollDetSegDefV3;
   JmpTbl[CIGI_ATMOS_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiAtmosCtrlV3;
   JmpTbl[CIGI_CELESTIAL_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiCelestialCtrlV3;
   JmpTbl[CIGI_ART_PART_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiArtPartCtrlV3;
   JmpTbl[CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3] = (CigiBasePacket *) new CigiCollDetVolDefV3;
   JmpTbl[CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiShortArtPartCtrlV3;
   JmpTbl[CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiConfClampEntityCtrlV3;
   JmpTbl[CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiMaritimeSurfaceCtrlV3;
   JmpTbl[CIGI_ENV_RGN_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiEnvRgnCtrlV3;
   JmpTbl[CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiTerrestrialSurfaceCtrlV3;
   JmpTbl[CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiMotionTrackCtrlV3;
   JmpTbl[CIGI_EARTH_MODEL_DEF_PACKET_ID_V3] = (CigiBasePacket *) new CigiEarthModelDefV3;
   JmpTbl[CIGI_POSITION_REQ_PACKET_ID_V3] = (CigiBasePacket *) new CigiPositionReqV3;
   JmpTbl[CIGI_ENV_COND_REQ_PACKET_ID_V3] = (CigiBasePacket *) new CigiEnvCondReqV3;
   JmpTbl[CIGI_WAVE_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiWaveCtrlV3;
   JmpTbl[CIGI_COMP_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiCompCtrlV3;
   JmpTbl[CIGI_SHORT_COMP_CTRL_PACKET_ID_V3] = (CigiBasePacket *) new CigiShortCompCtrlV3;

   JmpTbl[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiCollDetSegRespV3;
   JmpTbl[CIGI_SENSOR_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiSensorRespV3;
   JmpTbl[CIGI_SENSOR_XRESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiSensorXRespV3;
   JmpTbl[CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiCollDetVolRespV3;
   JmpTbl[CIGI_POSITION_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiPositionRespV3;
   JmpTbl[CIGI_WEATHER_COND_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiWeatherCondRespV3;
   JmpTbl[CIGI_AEROSOL_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiAerosolRespV3;
   JmpTbl[CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiMaritimeSurfaceRespV3;
   JmpTbl[CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3] = (CigiBasePacket *) new CigiTerrestrialSurfaceRespV3;
   JmpTbl[CIGI_ANIMATION_STOP_PACKET_ID_V3] = (CigiBasePacket *) new CigiAnimationStopV3;
   JmpTbl[CIGI_EVENT_NOTIFICATION_PACKET_ID_V3] = (CigiBasePacket *) new CigiEventNotificationV3;
   JmpTbl[CIGI_IG_MSG_PACKET_ID_V3] = (CigiBasePacket *) new CigiIGMsgV3;

}


// ================================================
// InitPacketIDMaps
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::InitPacketIDMaps()
{

   // IG control Packet
   TotalPacketIDMap[1][1][CIGI_IG_CTRL_PACKET_ID_V1] = CIGI_IG_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_IG_CTRL_PACKET_ID_V2] = CIGI_IG_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_IG_CTRL_PACKET_ID_V3] = CIGI_IG_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_IG_CTRL_PACKET_ID_V1] = CIGI_IG_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_IG_CTRL_PACKET_ID_V2] = CIGI_IG_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_IG_CTRL_PACKET_ID_V3] = CIGI_IG_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_IG_CTRL_PACKET_ID_V1] = CIGI_IG_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_IG_CTRL_PACKET_ID_V2] = CIGI_IG_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_IG_CTRL_PACKET_ID_V3] = CIGI_IG_CTRL_PACKET_ID_V3;

   // Entity control Packet
   TotalPacketIDMap[1][1][CIGI_ENTITY_CTRL_PACKET_ID_V1] = CIGI_ENTITY_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_ENTITY_CTRL_PACKET_ID_V2] = CIGI_ENTITY_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_ENTITY_CTRL_PACKET_ID_V3] = CIGI_ENTITY_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_ENTITY_CTRL_PACKET_ID_V1] = CIGI_ENTITY_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_ENTITY_CTRL_PACKET_ID_V2] = CIGI_ENTITY_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_ENTITY_CTRL_PACKET_ID_V3] = CIGI_ENTITY_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_ENTITY_CTRL_PACKET_ID_V1] = CIGI_ENTITY_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_ENTITY_CTRL_PACKET_ID_V2] = CIGI_ENTITY_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_ENTITY_CTRL_PACKET_ID_V3] = CIGI_ENTITY_CTRL_PACKET_ID_V3;

   // View Definition Packet
   TotalPacketIDMap[1][1][CIGI_VIEW_DEF_PACKET_ID_V1] = CIGI_VIEW_DEF_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_VIEW_DEF_PACKET_ID_V2] = CIGI_VIEW_DEF_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_VIEW_DEF_PACKET_ID_V3] = CIGI_VIEW_DEF_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_VIEW_DEF_PACKET_ID_V1] = CIGI_VIEW_DEF_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_VIEW_DEF_PACKET_ID_V2] = CIGI_VIEW_DEF_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_VIEW_DEF_PACKET_ID_V3] = CIGI_VIEW_DEF_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_VIEW_DEF_PACKET_ID_V1] = CIGI_VIEW_DEF_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_VIEW_DEF_PACKET_ID_V2] = CIGI_VIEW_DEF_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_VIEW_DEF_PACKET_ID_V3] = CIGI_VIEW_DEF_PACKET_ID_V3;

   // View Control Packet
   TotalPacketIDMap[1][1][CIGI_VIEW_CTRL_PACKET_ID_V1] = CIGI_VIEW_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_VIEW_CTRL_PACKET_ID_V2] = CIGI_VIEW_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_VIEW_CTRL_PACKET_ID_V3] = CIGI_VIEW_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_VIEW_CTRL_PACKET_ID_V1] = CIGI_VIEW_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_VIEW_CTRL_PACKET_ID_V2] = CIGI_VIEW_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_VIEW_CTRL_PACKET_ID_V3] = CIGI_VIEW_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_VIEW_CTRL_PACKET_ID_V1] = CIGI_VIEW_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_VIEW_CTRL_PACKET_ID_V2] = CIGI_VIEW_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_VIEW_CTRL_PACKET_ID_V3] = CIGI_VIEW_CTRL_PACKET_ID_V3;

   // Rate Control Packet
   TotalPacketIDMap[1][1][CIGI_RATE_CTRL_PACKET_ID_V1] = CIGI_RATE_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_RATE_CTRL_PACKET_ID_V2] = CIGI_RATE_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_RATE_CTRL_PACKET_ID_V3] = CIGI_RATE_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_RATE_CTRL_PACKET_ID_V1] = CIGI_RATE_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_RATE_CTRL_PACKET_ID_V2] = CIGI_RATE_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_RATE_CTRL_PACKET_ID_V3] = CIGI_RATE_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_RATE_CTRL_PACKET_ID_V1] = CIGI_RATE_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_RATE_CTRL_PACKET_ID_V2] = CIGI_RATE_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_RATE_CTRL_PACKET_ID_V3] = CIGI_RATE_CTRL_PACKET_ID_V3;

   // Sensor Control Packet
   TotalPacketIDMap[1][1][CIGI_SENSOR_CTRL_PACKET_ID_V1] = CIGI_SENSOR_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_SENSOR_CTRL_PACKET_ID_V2] = CIGI_SENSOR_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_SENSOR_CTRL_PACKET_ID_V3] = CIGI_SENSOR_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_SENSOR_CTRL_PACKET_ID_V1] = CIGI_SENSOR_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_SENSOR_CTRL_PACKET_ID_V2] = CIGI_SENSOR_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_SENSOR_CTRL_PACKET_ID_V3] = CIGI_SENSOR_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_SENSOR_CTRL_PACKET_ID_V1] = CIGI_SENSOR_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_SENSOR_CTRL_PACKET_ID_V2] = CIGI_SENSOR_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_SENSOR_CTRL_PACKET_ID_V3] = CIGI_SENSOR_CTRL_PACKET_ID_V3;

   // Trajectory Definition Packet
   TotalPacketIDMap[1][1][CIGI_TRAJECTORY_DEF_PACKET_ID_V1] = CIGI_TRAJECTORY_DEF_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_TRAJECTORY_DEF_PACKET_ID_V2] = CIGI_TRAJECTORY_DEF_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_TRAJECTORY_DEF_PACKET_ID_V3] = CIGI_TRAJECTORY_DEF_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_TRAJECTORY_DEF_PACKET_ID_V1] = CIGI_TRAJECTORY_DEF_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_TRAJECTORY_DEF_PACKET_ID_V2] = CIGI_TRAJECTORY_DEF_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_TRAJECTORY_DEF_PACKET_ID_V3] = CIGI_TRAJECTORY_DEF_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_TRAJECTORY_DEF_PACKET_ID_V1] = CIGI_TRAJECTORY_DEF_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_TRAJECTORY_DEF_PACKET_ID_V2] = CIGI_TRAJECTORY_DEF_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_TRAJECTORY_DEF_PACKET_ID_V3] = CIGI_TRAJECTORY_DEF_PACKET_ID_V3;

   // Weather Control Packet
   TotalPacketIDMap[1][1][CIGI_WEATHER_CTRL_PACKET_ID_V1] = CIGI_WEATHER_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_WEATHER_CTRL_PACKET_ID_V2] = CIGI_WEATHER_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_WEATHER_CTRL_PACKET_ID_V3] = CIGI_WEATHER_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_WEATHER_CTRL_PACKET_ID_V1] = CIGI_WEATHER_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_WEATHER_CTRL_PACKET_ID_V2] = CIGI_WEATHER_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_WEATHER_CTRL_PACKET_ID_V3] = CIGI_WEATHER_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_WEATHER_CTRL_PACKET_ID_V1] = CIGI_WEATHER_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_WEATHER_CTRL_PACKET_ID_V2] = CIGI_WEATHER_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_WEATHER_CTRL_PACKET_ID_V3] = CIGI_WEATHER_CTRL_PACKET_ID_V3;

   // Collision Detection Segment Definition Packet
   TotalPacketIDMap[1][1][CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1] = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2] = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3] = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1] = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2] = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3] = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1] = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2] = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3] = CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3;

   // LOS Segment Request Packet
   TotalPacketIDMap[1][1][CIGI_LOS_SEG_REQ_PACKET_ID_V1] = CIGI_LOS_SEG_REQ_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_LOS_SEG_REQ_PACKET_ID_V2] = CIGI_LOS_SEG_REQ_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_LOS_SEG_REQ_PACKET_ID_V3] = CIGI_LOS_SEG_REQ_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_LOS_SEG_REQ_PACKET_ID_V1] = CIGI_LOS_SEG_REQ_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_LOS_SEG_REQ_PACKET_ID_V2] = CIGI_LOS_SEG_REQ_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_LOS_SEG_REQ_PACKET_ID_V3] = CIGI_LOS_SEG_REQ_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_LOS_SEG_REQ_PACKET_ID_V1] = CIGI_LOS_SEG_REQ_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_LOS_SEG_REQ_PACKET_ID_V2] = CIGI_LOS_SEG_REQ_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_LOS_SEG_REQ_PACKET_ID_V3] = CIGI_LOS_SEG_REQ_PACKET_ID_V3;

   // LOS Vector Request Packet
   TotalPacketIDMap[1][1][CIGI_LOS_VECT_REQ_PACKET_ID_V1] = CIGI_LOS_VECT_REQ_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_LOS_VECT_REQ_PACKET_ID_V2] = CIGI_LOS_VECT_REQ_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_LOS_VECT_REQ_PACKET_ID_V3] = CIGI_LOS_VECT_REQ_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_LOS_VECT_REQ_PACKET_ID_V1] = CIGI_LOS_VECT_REQ_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_LOS_VECT_REQ_PACKET_ID_V2] = CIGI_LOS_VECT_REQ_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_LOS_VECT_REQ_PACKET_ID_V3] = CIGI_LOS_VECT_REQ_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_LOS_VECT_REQ_PACKET_ID_V1] = CIGI_LOS_VECT_REQ_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_LOS_VECT_REQ_PACKET_ID_V2] = CIGI_LOS_VECT_REQ_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_LOS_VECT_REQ_PACKET_ID_V3] = CIGI_LOS_VECT_REQ_PACKET_ID_V3;

   // Hat Hot Request Packet
   TotalPacketIDMap[1][1][CIGI_HAT_REQ_PACKET_ID_V1] = CIGI_HAT_REQ_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_HAT_REQ_PACKET_ID_V1] = CIGI_HAT_REQ_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_HAT_REQ_PACKET_ID_V1] = CIGI_HAT_HOT_REQ_PACKET_ID_V3;
   TotalPacketIDMap[2][1][CIGI_HAT_REQ_PACKET_ID_V2] = CIGI_HAT_REQ_PACKET_ID_V1;
   TotalPacketIDMap[2][2][CIGI_HAT_REQ_PACKET_ID_V2] = CIGI_HAT_REQ_PACKET_ID_V2;
   TotalPacketIDMap[2][3][CIGI_HAT_REQ_PACKET_ID_V2] = CIGI_HAT_HOT_REQ_PACKET_ID_V3;
   TotalPacketIDMap[2][1][CIGI_HOT_REQ_PACKET_ID_V2] = CIGI_HAT_REQ_PACKET_ID_V1;
   TotalPacketIDMap[2][2][CIGI_HOT_REQ_PACKET_ID_V2] = CIGI_HOT_REQ_PACKET_ID_V2;
   TotalPacketIDMap[2][3][CIGI_HOT_REQ_PACKET_ID_V2] = CIGI_HAT_HOT_REQ_PACKET_ID_V3;
   TotalPacketIDMap[3][1][CIGI_HAT_HOT_REQ_PACKET_ID_V3] = CIGI_HAT_REQ_PACKET_ID_V1;
   TotalPacketIDMap[3][2][CIGI_HAT_HOT_REQ_PACKET_ID_V3] = CIGI_HAT_REQ_PACKET_ID_V2;
   TotalPacketIDMap[3][3][CIGI_HAT_HOT_REQ_PACKET_ID_V3] = CIGI_HAT_HOT_REQ_PACKET_ID_V3;

   // Environmental Control Packet  -  This has a special jump package   ZZZ
   TotalPacketIDMap[1][1][CIGI_ENV_CTRL_PACKET_ID_V1] = CIGI_ENV_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_ENV_CTRL_PACKET_ID_V2] = CIGI_ENV_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_ENV_CTRL_PACKET_ID_V1] = CIGI_ENV_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_ENV_CTRL_PACKET_ID_V2] = CIGI_ENV_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_ENV_CTRL_PACKET_ID_V1] = CIGI_ATMOS_CTRL_PACKET_ID_V3; // special
   TotalPacketIDMap[2][3][CIGI_ENV_CTRL_PACKET_ID_V2] = CIGI_ATMOS_CTRL_PACKET_ID_V3; // special
   TotalPacketIDMap[3][1][CIGI_ATMOS_CTRL_PACKET_ID_V3] = CIGI_ENV_CTRL_PACKET_ID_V1; // special
   TotalPacketIDMap[3][2][CIGI_ATMOS_CTRL_PACKET_ID_V3] = CIGI_ENV_CTRL_PACKET_ID_V2; // special
   TotalPacketIDMap[3][1][CIGI_CELESTIAL_CTRL_PACKET_ID_V3] = CIGI_ENV_CTRL_PACKET_ID_V1; // special
   TotalPacketIDMap[3][2][CIGI_CELESTIAL_CTRL_PACKET_ID_V3] = CIGI_ENV_CTRL_PACKET_ID_V2; // special
   TotalPacketIDMap[3][3][CIGI_ATMOS_CTRL_PACKET_ID_V3] = CIGI_ATMOS_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_CELESTIAL_CTRL_PACKET_ID_V3] = CIGI_CELESTIAL_CTRL_PACKET_ID_V3;

   // Special Effect Definision Packet
   TotalPacketIDMap[1][1][CIGI_SPEC_EFF_DEF_PACKET_ID_V1] = CIGI_SPEC_EFF_DEF_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_SPEC_EFF_DEF_PACKET_ID_V2] = CIGI_SPEC_EFF_DEF_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_SPEC_EFF_DEF_PACKET_ID_V1] = CIGI_SPEC_EFF_DEF_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_SPEC_EFF_DEF_PACKET_ID_V2] = CIGI_SPEC_EFF_DEF_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_SPEC_EFF_DEF_PACKET_ID_V1] = 0;
   TotalPacketIDMap[2][3][CIGI_SPEC_EFF_DEF_PACKET_ID_V2] = 0;

   // Articulated Part Control Packet
   TotalPacketIDMap[1][1][CIGI_ART_PART_CTRL_PACKET_ID_V1] = CIGI_ART_PART_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_ART_PART_CTRL_PACKET_ID_V2] = CIGI_ART_PART_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_ART_PART_CTRL_PACKET_ID_V3] = CIGI_ART_PART_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_ART_PART_CTRL_PACKET_ID_V1] = CIGI_ART_PART_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_ART_PART_CTRL_PACKET_ID_V2] = CIGI_ART_PART_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_ART_PART_CTRL_PACKET_ID_V3] = CIGI_ART_PART_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_ART_PART_CTRL_PACKET_ID_V1] = CIGI_ART_PART_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_ART_PART_CTRL_PACKET_ID_V2] = CIGI_ART_PART_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_ART_PART_CTRL_PACKET_ID_V3] = CIGI_ART_PART_CTRL_PACKET_ID_V3;

   // Collision Detection Volume Definition Packet
   TotalPacketIDMap[2][1][CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2] = 0;
   TotalPacketIDMap[3][1][CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3] = 0;
   TotalPacketIDMap[2][2][CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2] = CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3] = CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2;
   TotalPacketIDMap[2][3][CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2] = CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3] = CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3;

   // Short Articulated Part Control Packet
   TotalPacketIDMap[3][1][CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3] = CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3;

   // Conformal Clamped Entity Control Packet
   TotalPacketIDMap[3][1][CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3] = CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3;

   // Maritime Surface Conditions Control Packet
   TotalPacketIDMap[3][1][CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3] = CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3;

   // Environmental Region Control Packet
   TotalPacketIDMap[3][1][CIGI_ENV_RGN_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_ENV_RGN_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_ENV_RGN_CTRL_PACKET_ID_V3] = CIGI_ENV_RGN_CTRL_PACKET_ID_V3;

   // Terrestrial Surface Control Packet
   TotalPacketIDMap[3][1][CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3] = CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3;

   // Motion Tracker control Packet
   TotalPacketIDMap[3][1][CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3] = CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3;

   // Earth Model Definition Packet
   TotalPacketIDMap[3][1][CIGI_EARTH_MODEL_DEF_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_EARTH_MODEL_DEF_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_EARTH_MODEL_DEF_PACKET_ID_V3] = CIGI_EARTH_MODEL_DEF_PACKET_ID_V3;

   // Positon Request Packet
   TotalPacketIDMap[3][1][CIGI_POSITION_REQ_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_POSITION_REQ_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_POSITION_REQ_PACKET_ID_V3] = CIGI_POSITION_REQ_PACKET_ID_V3;

   // Environmental Conditions Request Packet
   TotalPacketIDMap[3][1][CIGI_ENV_COND_REQ_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_ENV_COND_REQ_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_ENV_COND_REQ_PACKET_ID_V3] = CIGI_ENV_COND_REQ_PACKET_ID_V3;

   // Wave Control Packet
   TotalPacketIDMap[3][1][CIGI_WAVE_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_WAVE_CTRL_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_WAVE_CTRL_PACKET_ID_V3] = CIGI_WAVE_CTRL_PACKET_ID_V3;

   // Start Of Frame Packet
   TotalPacketIDMap[1][1][CIGI_SOF_PACKET_ID_V1] = CIGI_SOF_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_SOF_PACKET_ID_V2] = CIGI_SOF_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_SOF_PACKET_ID_V3] = CIGI_SOF_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_SOF_PACKET_ID_V1] = CIGI_SOF_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_SOF_PACKET_ID_V2] = CIGI_SOF_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_SOF_PACKET_ID_V3] = CIGI_SOF_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_SOF_PACKET_ID_V1] = CIGI_SOF_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_SOF_PACKET_ID_V2] = CIGI_SOF_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_SOF_PACKET_ID_V3] = CIGI_SOF_PACKET_ID_V3;

   // Collision Detection Segment Response Packet
   TotalPacketIDMap[1][1][CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1] = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2] = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3] = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1] = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2] = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3] = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1] = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2] = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3] = CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3;

   // Sensor Response Packet
   TotalPacketIDMap[1][1][CIGI_SENSOR_RESP_PACKET_ID_V1] = CIGI_SENSOR_RESP_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_SENSOR_RESP_PACKET_ID_V2] = CIGI_SENSOR_RESP_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_SENSOR_RESP_PACKET_ID_V3] = CIGI_SENSOR_RESP_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_SENSOR_RESP_PACKET_ID_V1] = CIGI_SENSOR_RESP_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_SENSOR_RESP_PACKET_ID_V2] = CIGI_SENSOR_RESP_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_SENSOR_RESP_PACKET_ID_V3] = CIGI_SENSOR_RESP_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_SENSOR_RESP_PACKET_ID_V1] = CIGI_SENSOR_RESP_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_SENSOR_RESP_PACKET_ID_V2] = CIGI_SENSOR_RESP_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_SENSOR_RESP_PACKET_ID_V3] = CIGI_SENSOR_RESP_PACKET_ID_V3;

   // Sensor Extended Response Packet
   TotalPacketIDMap[3][1][CIGI_SENSOR_XRESP_PACKET_ID_V3] = CIGI_SENSOR_RESP_PACKET_ID_V1;
   TotalPacketIDMap[3][2][CIGI_SENSOR_XRESP_PACKET_ID_V3] = CIGI_SENSOR_RESP_PACKET_ID_V2;
   TotalPacketIDMap[3][3][CIGI_SENSOR_XRESP_PACKET_ID_V3] = CIGI_SENSOR_XRESP_PACKET_ID_V3;

   // Los Response Packet
   TotalPacketIDMap[1][1][CIGI_LOS_RESP_PACKET_ID_V1] = CIGI_LOS_RESP_PACKET_ID_V1;
   TotalPacketIDMap[2][1][CIGI_LOS_RESP_PACKET_ID_V2] = CIGI_LOS_RESP_PACKET_ID_V1;
   TotalPacketIDMap[3][1][CIGI_LOS_RESP_PACKET_ID_V3] = CIGI_LOS_RESP_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_LOS_RESP_PACKET_ID_V1] = CIGI_LOS_RESP_PACKET_ID_V2;
   TotalPacketIDMap[2][2][CIGI_LOS_RESP_PACKET_ID_V2] = CIGI_LOS_RESP_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_LOS_RESP_PACKET_ID_V3] = CIGI_LOS_RESP_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_LOS_RESP_PACKET_ID_V1] = CIGI_LOS_RESP_PACKET_ID_V3;
   TotalPacketIDMap[2][3][CIGI_LOS_RESP_PACKET_ID_V2] = CIGI_LOS_RESP_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_LOS_RESP_PACKET_ID_V3] = CIGI_LOS_RESP_PACKET_ID_V3;

   // Los Extended Response Packet
   TotalPacketIDMap[3][1][CIGI_LOS_XRESP_PACKET_ID_V3] = CIGI_LOS_RESP_PACKET_ID_V1;
   TotalPacketIDMap[3][2][CIGI_LOS_XRESP_PACKET_ID_V3] = CIGI_LOS_RESP_PACKET_ID_V2;
   TotalPacketIDMap[3][3][CIGI_LOS_XRESP_PACKET_ID_V3] = CIGI_LOS_XRESP_PACKET_ID_V3;

   // Hat Hot Response Packet
   TotalPacketIDMap[1][1][CIGI_HAT_RESP_PACKET_ID_V1] = CIGI_HAT_RESP_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_HAT_RESP_PACKET_ID_V1] = CIGI_HAT_RESP_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_HAT_RESP_PACKET_ID_V1] = CIGI_HAT_HOT_RESP_PACKET_ID_V3;
   TotalPacketIDMap[2][1][CIGI_HAT_RESP_PACKET_ID_V2] = CIGI_HAT_RESP_PACKET_ID_V1;
   TotalPacketIDMap[2][2][CIGI_HAT_RESP_PACKET_ID_V2] = CIGI_HAT_RESP_PACKET_ID_V2;
   TotalPacketIDMap[2][3][CIGI_HAT_RESP_PACKET_ID_V2] = CIGI_HAT_HOT_RESP_PACKET_ID_V3;
   TotalPacketIDMap[2][1][CIGI_HOT_RESP_PACKET_ID_V2] = CIGI_HAT_RESP_PACKET_ID_V1;
   TotalPacketIDMap[2][2][CIGI_HOT_RESP_PACKET_ID_V2] = CIGI_HOT_RESP_PACKET_ID_V2;
   TotalPacketIDMap[2][3][CIGI_HOT_RESP_PACKET_ID_V2] = CIGI_HAT_HOT_RESP_PACKET_ID_V3;
   TotalPacketIDMap[3][1][CIGI_HAT_HOT_RESP_PACKET_ID_V3] = CIGI_HAT_RESP_PACKET_ID_V1;
   TotalPacketIDMap[3][2][CIGI_HAT_HOT_RESP_PACKET_ID_V3] = CIGI_HAT_RESP_PACKET_ID_V2;
   TotalPacketIDMap[3][3][CIGI_HAT_HOT_RESP_PACKET_ID_V3] = CIGI_HAT_HOT_RESP_PACKET_ID_V3;
   TotalPacketIDMap[3][1][CIGI_HAT_HOT_XRESP_PACKET_ID_V3] = CIGI_HAT_RESP_PACKET_ID_V1;
   TotalPacketIDMap[3][2][CIGI_HAT_HOT_XRESP_PACKET_ID_V3] = CIGI_HAT_RESP_PACKET_ID_V2;
   TotalPacketIDMap[3][3][CIGI_HAT_HOT_XRESP_PACKET_ID_V3] = CIGI_HAT_HOT_XRESP_PACKET_ID_V3;

   // Collision Detection Volume Response Packet
   TotalPacketIDMap[2][1][CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2] = 0;
   TotalPacketIDMap[3][1][CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[2][2][CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2] = CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3] = CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2;
   TotalPacketIDMap[2][3][CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2] = CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3] = CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3;

   // Position Response Packet
   TotalPacketIDMap[3][1][CIGI_POSITION_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_POSITION_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_POSITION_RESP_PACKET_ID_V3] = CIGI_POSITION_RESP_PACKET_ID_V3;

   // Weather Condition Response Packet
   TotalPacketIDMap[3][1][CIGI_WEATHER_COND_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_WEATHER_COND_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_WEATHER_COND_RESP_PACKET_ID_V3] = CIGI_WEATHER_COND_RESP_PACKET_ID_V3;

   // Aerosol Resp Packet
   TotalPacketIDMap[3][1][CIGI_AEROSOL_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_AEROSOL_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_AEROSOL_RESP_PACKET_ID_V3] = CIGI_AEROSOL_RESP_PACKET_ID_V3;

   // Maritime Surface Response Packet
   TotalPacketIDMap[3][1][CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3] = CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3;

   // Terrestrial Surface Response Packet
   TotalPacketIDMap[3][1][CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3] = CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3;

   // Animation Stop Notification Packet
   TotalPacketIDMap[3][1][CIGI_ANIMATION_STOP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_ANIMATION_STOP_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_ANIMATION_STOP_PACKET_ID_V3] = CIGI_ANIMATION_STOP_PACKET_ID_V3;

   // Event Notification Packet
   TotalPacketIDMap[3][1][CIGI_EVENT_NOTIFICATION_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][2][CIGI_EVENT_NOTIFICATION_PACKET_ID_V3] = 0;
   TotalPacketIDMap[3][3][CIGI_EVENT_NOTIFICATION_PACKET_ID_V3] = CIGI_EVENT_NOTIFICATION_PACKET_ID_V3;

   // IG Msg Packet
   TotalPacketIDMap[2][1][CIGI_IG_MSG_PACKET_ID_V2] = 0;
   TotalPacketIDMap[3][1][CIGI_IG_MSG_PACKET_ID_V3] = 0;
   TotalPacketIDMap[2][2][CIGI_IG_MSG_PACKET_ID_V2] = CIGI_IG_MSG_PACKET_ID_V2;
   TotalPacketIDMap[3][2][CIGI_IG_MSG_PACKET_ID_V3] = CIGI_IG_MSG_PACKET_ID_V2;
   TotalPacketIDMap[2][3][CIGI_IG_MSG_PACKET_ID_V2] = CIGI_IG_MSG_PACKET_ID_V3;
   TotalPacketIDMap[3][3][CIGI_IG_MSG_PACKET_ID_V3] = CIGI_IG_MSG_PACKET_ID_V3;

   // Component control Packet
   TotalPacketIDMap[1][1][CIGI_COMP_CTRL_PACKET_ID_V1] = CIGI_COMP_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[1][2][CIGI_COMP_CTRL_PACKET_ID_V1] = CIGI_COMP_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[1][3][CIGI_COMP_CTRL_PACKET_ID_V1] = CIGI_SHORT_COMP_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[2][1][CIGI_COMP_CTRL_PACKET_ID_V2] = CIGI_COMP_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[2][2][CIGI_COMP_CTRL_PACKET_ID_V2] = CIGI_COMP_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[2][3][CIGI_COMP_CTRL_PACKET_ID_V2] = CIGI_SHORT_COMP_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][1][CIGI_COMP_CTRL_PACKET_ID_V3] = CIGI_COMP_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[3][2][CIGI_COMP_CTRL_PACKET_ID_V3] = CIGI_COMP_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[3][3][CIGI_COMP_CTRL_PACKET_ID_V3] = CIGI_COMP_CTRL_PACKET_ID_V3;
   TotalPacketIDMap[3][1][CIGI_SHORT_COMP_CTRL_PACKET_ID_V3] = CIGI_COMP_CTRL_PACKET_ID_V1;
   TotalPacketIDMap[3][2][CIGI_SHORT_COMP_CTRL_PACKET_ID_V3] = CIGI_COMP_CTRL_PACKET_ID_V2;
   TotalPacketIDMap[3][3][CIGI_SHORT_COMP_CTRL_PACKET_ID_V3] = CIGI_SHORT_COMP_CTRL_PACKET_ID_V3;


}

// ================================================
// SetPacketIDMapsV1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetPacketIDMapsV1()
{

   memcpy(PacketIDMap[1],TotalPacketIDMap[1][1],255);
   memcpy(PacketIDMap[2],TotalPacketIDMap[2][1],255);
   memcpy(PacketIDMap[3],TotalPacketIDMap[3][1],255);

}

// ================================================
// SetPacketIDMapsV2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetPacketIDMapsV2()
{

   memcpy(PacketIDMap[1],TotalPacketIDMap[1][2],255);
   memcpy(PacketIDMap[2],TotalPacketIDMap[2][2],255);
   memcpy(PacketIDMap[3],TotalPacketIDMap[3][2],255);

}

// ================================================
// SetPacketIDMapsV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetPacketIDMapsV3()
{

   memcpy(PacketIDMap[1],TotalPacketIDMap[1][3],255);
   memcpy(PacketIDMap[2],TotalPacketIDMap[2][3],255);
   memcpy(PacketIDMap[3],TotalPacketIDMap[3][3],255);

}

// ================================================
// SetReaderPacketIDMaps
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetReaderPacketIDMaps(int from, int to)
{

   memcpy(PacketIDMap[0],TotalPacketIDMap[from][to],255);

}

// ================================================
// SetVldTblsV1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetVldTblsV1()
{

   if(JTblType == Host)
   {
      VldSnd[CIGI_IG_CTRL_PACKET_ID_V1] = true;
      VldSnd[CIGI_ENTITY_CTRL_PACKET_ID_V1] = true;
      VldSnd[CIGI_VIEW_DEF_PACKET_ID_V1] = true;
      VldSnd[CIGI_VIEW_CTRL_PACKET_ID_V1] = true;
      VldSnd[CIGI_RATE_CTRL_PACKET_ID_V1] = true;
      VldSnd[CIGI_SENSOR_CTRL_PACKET_ID_V1] = true;
      VldSnd[CIGI_TRAJECTORY_DEF_PACKET_ID_V1] = true;
      VldSnd[CIGI_WEATHER_CTRL_PACKET_ID_V1] = true;
      VldSnd[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1] = true;
      VldSnd[CIGI_LOS_SEG_REQ_PACKET_ID_V1] = true;
      VldSnd[CIGI_LOS_VECT_REQ_PACKET_ID_V1] = true;
      VldSnd[CIGI_HAT_REQ_PACKET_ID_V1] = true;
      VldSnd[CIGI_ENV_CTRL_PACKET_ID_V1] = true;
      VldSnd[CIGI_SPEC_EFF_DEF_PACKET_ID_V1] = true;
      VldSnd[CIGI_ART_PART_CTRL_PACKET_ID_V1] = true;
      VldSnd[CIGI_COMP_CTRL_PACKET_ID_V1] = true;

      VldRcv[CIGI_SOF_PACKET_ID_V1] = true;
      VldRcv[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1] = true;
      VldRcv[CIGI_SENSOR_RESP_PACKET_ID_V1] = true;
      VldRcv[CIGI_LOS_RESP_PACKET_ID_V1] = true;
      VldRcv[CIGI_HAT_RESP_PACKET_ID_V1] = true;
   }
   else
   {
      VldRcv[CIGI_IG_CTRL_PACKET_ID_V1] = true;
      VldRcv[CIGI_ENTITY_CTRL_PACKET_ID_V1] = true;
      VldRcv[CIGI_VIEW_DEF_PACKET_ID_V1] = true;
      VldRcv[CIGI_VIEW_CTRL_PACKET_ID_V1] = true;
      VldRcv[CIGI_RATE_CTRL_PACKET_ID_V1] = true;
      VldRcv[CIGI_SENSOR_CTRL_PACKET_ID_V1] = true;
      VldRcv[CIGI_TRAJECTORY_DEF_PACKET_ID_V1] = true;
      VldRcv[CIGI_WEATHER_CTRL_PACKET_ID_V1] = true;
      VldRcv[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1] = true;
      VldRcv[CIGI_LOS_SEG_REQ_PACKET_ID_V1] = true;
      VldRcv[CIGI_LOS_VECT_REQ_PACKET_ID_V1] = true;
      VldRcv[CIGI_HAT_REQ_PACKET_ID_V1] = true;
      VldRcv[CIGI_ENV_CTRL_PACKET_ID_V1] = true;
      VldRcv[CIGI_SPEC_EFF_DEF_PACKET_ID_V1] = true;
      VldRcv[CIGI_ART_PART_CTRL_PACKET_ID_V1] = true;
      VldRcv[CIGI_COMP_CTRL_PACKET_ID_V1] = true;

      VldSnd[CIGI_SOF_PACKET_ID_V1] = true;
      VldSnd[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1] = true;
      VldSnd[CIGI_SENSOR_RESP_PACKET_ID_V1] = true;
      VldSnd[CIGI_LOS_RESP_PACKET_ID_V1] = true;
      VldSnd[CIGI_HAT_RESP_PACKET_ID_V1] = true;
   }

}

// ================================================
// SetVldTblsV2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetVldTblsV2()
{

   if(JTblType == Host)
   {
      VldSnd[CIGI_IG_CTRL_PACKET_ID_V2] = true;
      VldSnd[CIGI_ENTITY_CTRL_PACKET_ID_V2] = true;
      VldSnd[CIGI_VIEW_DEF_PACKET_ID_V2] = true;
      VldSnd[CIGI_VIEW_CTRL_PACKET_ID_V2] = true;
      VldSnd[CIGI_RATE_CTRL_PACKET_ID_V2] = true;
      VldSnd[CIGI_SENSOR_CTRL_PACKET_ID_V2] = true;
      VldSnd[CIGI_TRAJECTORY_DEF_PACKET_ID_V2] = true;
      VldSnd[CIGI_WEATHER_CTRL_PACKET_ID_V2] = true;
      VldSnd[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2] = true;
      VldSnd[CIGI_LOS_SEG_REQ_PACKET_ID_V2] = true;
      VldSnd[CIGI_LOS_VECT_REQ_PACKET_ID_V2] = true;
      VldSnd[CIGI_HAT_REQ_PACKET_ID_V2] = true;
      VldSnd[CIGI_HOT_REQ_PACKET_ID_V2] = true;
      VldSnd[CIGI_ENV_CTRL_PACKET_ID_V2] = true;
      VldSnd[CIGI_SPEC_EFF_DEF_PACKET_ID_V2] = true;
      VldSnd[CIGI_ART_PART_CTRL_PACKET_ID_V2] = true;
      VldSnd[CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2] = true;
      VldSnd[CIGI_COMP_CTRL_PACKET_ID_V2] = true;

      VldRcv[CIGI_SOF_PACKET_ID_V2] = true;
      VldRcv[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2] = true;
      VldRcv[CIGI_SENSOR_RESP_PACKET_ID_V2] = true;
      VldRcv[CIGI_LOS_RESP_PACKET_ID_V2] = true;
      VldRcv[CIGI_HAT_RESP_PACKET_ID_V2] = true;
      VldRcv[CIGI_HOT_RESP_PACKET_ID_V2] = true;
      VldRcv[CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2] = true;
      VldRcv[CIGI_IG_MSG_PACKET_ID_V2] = true;
   }
   else
   {
      VldRcv[CIGI_IG_CTRL_PACKET_ID_V2] = true;
      VldRcv[CIGI_ENTITY_CTRL_PACKET_ID_V2] = true;
      VldRcv[CIGI_VIEW_DEF_PACKET_ID_V2] = true;
      VldRcv[CIGI_VIEW_CTRL_PACKET_ID_V2] = true;
      VldRcv[CIGI_RATE_CTRL_PACKET_ID_V2] = true;
      VldRcv[CIGI_SENSOR_CTRL_PACKET_ID_V2] = true;
      VldRcv[CIGI_TRAJECTORY_DEF_PACKET_ID_V2] = true;
      VldRcv[CIGI_WEATHER_CTRL_PACKET_ID_V2] = true;
      VldRcv[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2] = true;
      VldRcv[CIGI_LOS_SEG_REQ_PACKET_ID_V2] = true;
      VldRcv[CIGI_LOS_VECT_REQ_PACKET_ID_V2] = true;
      VldRcv[CIGI_HAT_REQ_PACKET_ID_V2] = true;
      VldRcv[CIGI_HOT_REQ_PACKET_ID_V2] = true;
      VldRcv[CIGI_ENV_CTRL_PACKET_ID_V2] = true;
      VldRcv[CIGI_SPEC_EFF_DEF_PACKET_ID_V2] = true;
      VldRcv[CIGI_ART_PART_CTRL_PACKET_ID_V2] = true;
      VldRcv[CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2] = true;
      VldRcv[CIGI_COMP_CTRL_PACKET_ID_V2] = true;

      VldSnd[CIGI_SOF_PACKET_ID_V2] = true;
      VldSnd[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2] = true;
      VldSnd[CIGI_SENSOR_RESP_PACKET_ID_V2] = true;
      VldSnd[CIGI_LOS_RESP_PACKET_ID_V2] = true;
      VldSnd[CIGI_HAT_RESP_PACKET_ID_V2] = true;
      VldSnd[CIGI_HOT_RESP_PACKET_ID_V2] = true;
      VldSnd[CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2] = true;
      VldSnd[CIGI_IG_MSG_PACKET_ID_V2] = true;
   }

}

// ================================================
// SetVldTblsV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetVldTblsV3()
{

   // All packet ID for version 3.2 are the same as version 3.

   if(JTblType == Host)
   {
      VldSnd[CIGI_IG_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_ENTITY_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_VIEW_DEF_PACKET_ID_V3] = true;
      VldSnd[CIGI_VIEW_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_RATE_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_SENSOR_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_TRAJECTORY_DEF_PACKET_ID_V3] = true;
      VldSnd[CIGI_WEATHER_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3] = true;
      VldSnd[CIGI_LOS_SEG_REQ_PACKET_ID_V3] = true;
      VldSnd[CIGI_LOS_VECT_REQ_PACKET_ID_V3] = true;
      VldSnd[CIGI_HAT_HOT_REQ_PACKET_ID_V3] = true;
      VldSnd[CIGI_ATMOS_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_CELESTIAL_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_ART_PART_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3] = true;
      VldSnd[CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_ENV_RGN_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_EARTH_MODEL_DEF_PACKET_ID_V3] = true;
      VldSnd[CIGI_POSITION_REQ_PACKET_ID_V3] = true;
      VldSnd[CIGI_ENV_COND_REQ_PACKET_ID_V3] = true;
      VldSnd[CIGI_WAVE_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_COMP_CTRL_PACKET_ID_V3] = true;
      VldSnd[CIGI_SHORT_COMP_CTRL_PACKET_ID_V3] = true;

      VldRcv[CIGI_SOF_PACKET_ID_V3] = true;
      VldRcv[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_SENSOR_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_SENSOR_XRESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_LOS_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_LOS_XRESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_HAT_HOT_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_HAT_HOT_XRESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_POSITION_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_WEATHER_COND_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_AEROSOL_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3] = true;
      VldRcv[CIGI_ANIMATION_STOP_PACKET_ID_V3] = true;
      VldRcv[CIGI_EVENT_NOTIFICATION_PACKET_ID_V3] = true;
      VldRcv[CIGI_IG_MSG_PACKET_ID_V3] = true;
   }
   else
   {
      VldRcv[CIGI_IG_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_ENTITY_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_VIEW_DEF_PACKET_ID_V3] = true;
      VldRcv[CIGI_VIEW_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_RATE_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_SENSOR_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_TRAJECTORY_DEF_PACKET_ID_V3] = true;
      VldRcv[CIGI_WEATHER_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3] = true;
      VldRcv[CIGI_LOS_SEG_REQ_PACKET_ID_V3] = true;
      VldRcv[CIGI_LOS_VECT_REQ_PACKET_ID_V3] = true;
      VldRcv[CIGI_HAT_HOT_REQ_PACKET_ID_V3] = true;
      VldRcv[CIGI_ATMOS_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_CELESTIAL_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_ART_PART_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3] = true;
      VldRcv[CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_ENV_RGN_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_EARTH_MODEL_DEF_PACKET_ID_V3] = true;
      VldRcv[CIGI_POSITION_REQ_PACKET_ID_V3] = true;
      VldRcv[CIGI_ENV_COND_REQ_PACKET_ID_V3] = true;
      VldRcv[CIGI_WAVE_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_COMP_CTRL_PACKET_ID_V3] = true;
      VldRcv[CIGI_SHORT_COMP_CTRL_PACKET_ID_V3] = true;

      VldSnd[CIGI_SOF_PACKET_ID_V3] = true;
      VldSnd[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_SENSOR_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_SENSOR_XRESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_LOS_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_LOS_XRESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_HAT_HOT_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_HAT_HOT_XRESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_POSITION_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_WEATHER_COND_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_AEROSOL_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3] = true;
      VldSnd[CIGI_ANIMATION_STOP_PACKET_ID_V3] = true;
      VldSnd[CIGI_EVENT_NOTIFICATION_PACKET_ID_V3] = true;
      VldSnd[CIGI_IG_MSG_PACKET_ID_V3] = true;
   }

}


// ================================================
// RegisterUserPacket
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiVersionJumpTable::RegisterUserPacket(CigiBasePacket *Packet,
                                             Cigi_uint8 PacketID,
                                             bool HostSend, bool IGSend)
{

   if(PacketID < 200)
   {

#ifndef CIGI_NO_EXCEPT
      throw CigiInvalidUserPacketException((Cigi_uint8)PacketID);
#endif
      return(CIGI_ERROR_INVALID_USER_PACKET);

   }

   JmpTbl[PacketID] = Packet;

   for(int fromx=0;fromx<4;fromx++)
   {
      PacketIDMap[fromx][PacketID] = PacketID;

      for(int tox=0;tox<4;tox++)
      {
         TotalPacketIDMap[fromx][tox][PacketID] = PacketID;
      }
   }

   if(JTblType == Host)
   {
      VldSnd[PacketID] = HostSend;
      VldRcv[PacketID] = IGSend;
   }
   else
   {
      VldSnd[PacketID] = IGSend;
      VldRcv[PacketID] = HostSend;
   }

   return(CIGI_SUCCESS);

}


// ================================================
// SetSignalMapV1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetSignalMapV1()
{
   SignalMap[CIGI_IG_CTRL_PACKET_ID_V1] = SigIGCtrl;
   SignalMap[CIGI_ENTITY_CTRL_PACKET_ID_V1] = SigEntityCtrl;
   SignalMap[CIGI_VIEW_DEF_PACKET_ID_V1] = SigViewDef;
   SignalMap[CIGI_VIEW_CTRL_PACKET_ID_V1] = SigViewCtrl;
   SignalMap[CIGI_RATE_CTRL_PACKET_ID_V1] = SigRateCtrl;
   SignalMap[CIGI_SENSOR_CTRL_PACKET_ID_V1] = SigSensorCtrl;
   SignalMap[CIGI_TRAJECTORY_DEF_PACKET_ID_V1] = SigTrajectory;
   SignalMap[CIGI_WEATHER_CTRL_PACKET_ID_V1] = SigWeatherCtrl;
   SignalMap[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V1] = SigCollDetSegDef;
   SignalMap[CIGI_LOS_SEG_REQ_PACKET_ID_V1] = SigLosSegReq;
   SignalMap[CIGI_LOS_VECT_REQ_PACKET_ID_V1] = SigLosVectReq;
   SignalMap[CIGI_HAT_REQ_PACKET_ID_V1] = SigHatReq;
   SignalMap[CIGI_ENV_CTRL_PACKET_ID_V1] = SigEnvCtrl;
   SignalMap[CIGI_SPEC_EFF_DEF_PACKET_ID_V1] = SigSpecEffDef;
   SignalMap[CIGI_ART_PART_CTRL_PACKET_ID_V1] = SigArtPartCtrl;
   SignalMap[CIGI_COMP_CTRL_PACKET_ID_V1] = SigCompCtrl;

   SignalMap[CIGI_SOF_PACKET_ID_V1] = SigSOF;
   SignalMap[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V1] = SigCollDetSegResp;
   SignalMap[CIGI_SENSOR_RESP_PACKET_ID_V1] = SigSensorResp;
   SignalMap[CIGI_LOS_RESP_PACKET_ID_V1] = SigLosResp;
   SignalMap[CIGI_HAT_RESP_PACKET_ID_V1] = SigHatResp;
}


// ================================================
// SetSignalMapV2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetSignalMapV2()
{
   SignalMap[CIGI_IG_CTRL_PACKET_ID_V2] = SigIGCtrl;
   SignalMap[CIGI_ENTITY_CTRL_PACKET_ID_V2] = SigEntityCtrl;
   SignalMap[CIGI_VIEW_DEF_PACKET_ID_V2] = SigViewDef;
   SignalMap[CIGI_VIEW_CTRL_PACKET_ID_V2] = SigViewCtrl;
   SignalMap[CIGI_RATE_CTRL_PACKET_ID_V2] = SigRateCtrl;
   SignalMap[CIGI_SENSOR_CTRL_PACKET_ID_V2] = SigSensorCtrl;
   SignalMap[CIGI_TRAJECTORY_DEF_PACKET_ID_V2] = SigTrajectory;
   SignalMap[CIGI_WEATHER_CTRL_PACKET_ID_V2] = SigWeatherCtrl;
   SignalMap[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V2] = SigCollDetSegDef;
   SignalMap[CIGI_LOS_SEG_REQ_PACKET_ID_V2] = SigLosSegReq;
   SignalMap[CIGI_LOS_VECT_REQ_PACKET_ID_V2] = SigLosVectReq;
   SignalMap[CIGI_HAT_REQ_PACKET_ID_V2] = SigHatReq;
   SignalMap[CIGI_HOT_REQ_PACKET_ID_V2] = SigHotReq;
   SignalMap[CIGI_ENV_CTRL_PACKET_ID_V2] = SigEnvCtrl;
   SignalMap[CIGI_SPEC_EFF_DEF_PACKET_ID_V2] = SigSpecEffDef;
   SignalMap[CIGI_ART_PART_CTRL_PACKET_ID_V2] = SigArtPartCtrl;
   SignalMap[CIGI_COLL_DET_VOL_DEF_PACKET_ID_V2] = SigCollDetVolDef;
   SignalMap[CIGI_COMP_CTRL_PACKET_ID_V2] = SigCompCtrl;

   SignalMap[CIGI_SOF_PACKET_ID_V2] = SigSOF;
   SignalMap[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V2] = SigCollDetSegResp;
   SignalMap[CIGI_SENSOR_RESP_PACKET_ID_V2] = SigSensorResp;
   SignalMap[CIGI_LOS_RESP_PACKET_ID_V2] = SigLosResp;
   SignalMap[CIGI_HAT_RESP_PACKET_ID_V2] = SigHatResp;
   SignalMap[CIGI_HOT_RESP_PACKET_ID_V2] = SigHotResp;
   SignalMap[CIGI_COLL_DET_VOL_RESP_PACKET_ID_V2] = SigCollDetVolResp;
   SignalMap[CIGI_IG_MSG_PACKET_ID_V2] = SigIGMsg;
}

// ================================================
// SetSignalMapV3
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetSignalMapV3()
{
   SignalMap[CIGI_IG_CTRL_PACKET_ID_V3] = SigIGCtrl;
   SignalMap[CIGI_ENTITY_CTRL_PACKET_ID_V3] = SigEntityCtrl;
   SignalMap[CIGI_VIEW_DEF_PACKET_ID_V3] = SigViewDef;
   SignalMap[CIGI_VIEW_CTRL_PACKET_ID_V3] = SigViewCtrl;
   SignalMap[CIGI_RATE_CTRL_PACKET_ID_V3] = SigRateCtrl;
   SignalMap[CIGI_SENSOR_CTRL_PACKET_ID_V3] = SigSensorCtrl;
   SignalMap[CIGI_TRAJECTORY_DEF_PACKET_ID_V3] = SigTrajectory;
   SignalMap[CIGI_WEATHER_CTRL_PACKET_ID_V3] = SigWeatherCtrl;
   SignalMap[CIGI_COLL_DET_SEG_DEF_PACKET_ID_V3] = SigCollDetSegDef;
   SignalMap[CIGI_LOS_SEG_REQ_PACKET_ID_V3] = SigLosSegReq;
   SignalMap[CIGI_LOS_VECT_REQ_PACKET_ID_V3] = SigLosVectReq;
   SignalMap[CIGI_HAT_HOT_REQ_PACKET_ID_V3] = SigHatHotReq;
   SignalMap[CIGI_ATMOS_CTRL_PACKET_ID_V3] = SigAtmosCtrl;
   SignalMap[CIGI_CELESTIAL_CTRL_PACKET_ID_V3] = SigCelestialCtrl;
   SignalMap[CIGI_ART_PART_CTRL_PACKET_ID_V3] = SigArtPartCtrl;
   SignalMap[CIGI_COLL_DET_VOL_DEF_PACKET_ID_V3] = SigCollDetVolDef;
   SignalMap[CIGI_SHORT_ART_PART_CTRL_PACKET_ID_V3] = SigShortArtPartCtrl;
   SignalMap[CIGI_CONF_CLAMP_ENTITY_CTRL_PACKET_ID_V3] = SigConfClampEntityCtrl;
   SignalMap[CIGI_MARITIME_SURFACE_CTRL_PACKET_ID_V3] = SigMaritimeSurfaceCtrl;
   SignalMap[CIGI_ENV_RGN_CTRL_PACKET_ID_V3] = SigEnvRgnCtrl;
   SignalMap[CIGI_TERRESTRIAL_SURFACE_CTRL_PACKET_ID_V3] = SigTerrestrialSurfaceCtrl;
   SignalMap[CIGI_MOTION_TRACK_CTRL_PACKET_ID_V3] = SigMotionTrackCtrl;
   SignalMap[CIGI_EARTH_MODEL_DEF_PACKET_ID_V3] = SigEarthModelDef;
   SignalMap[CIGI_POSITION_REQ_PACKET_ID_V3] = SigPostionReq;
   SignalMap[CIGI_ENV_COND_REQ_PACKET_ID_V3] = SigEnvCondReq;
   SignalMap[CIGI_WAVE_CTRL_PACKET_ID_V3] = SigWaveCtrl;
   SignalMap[CIGI_COMP_CTRL_PACKET_ID_V3] = SigCompCtrl;
   SignalMap[CIGI_SHORT_COMP_CTRL_PACKET_ID_V3] = SigShortCompCtrl;

   SignalMap[CIGI_SOF_PACKET_ID_V3] = SigSOF;
   SignalMap[CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3] = SigCollDetSegResp;
   SignalMap[CIGI_SENSOR_RESP_PACKET_ID_V3] = SigSensorResp;
   SignalMap[CIGI_SENSOR_XRESP_PACKET_ID_V3] = SigSensorXResp;
   SignalMap[CIGI_LOS_RESP_PACKET_ID_V3] = SigLosResp;
   SignalMap[CIGI_LOS_XRESP_PACKET_ID_V3] = SigLosXResp;
   SignalMap[CIGI_HAT_HOT_RESP_PACKET_ID_V3] = SigHatHotResp;
   SignalMap[CIGI_HAT_HOT_XRESP_PACKET_ID_V3] = SigHatHotXResp;
   SignalMap[CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3] = SigCollDetVolResp;
   SignalMap[CIGI_POSITION_RESP_PACKET_ID_V3] = SigPositionResp;
   SignalMap[CIGI_WEATHER_COND_RESP_PACKET_ID_V3] = SigWeatherCondResp;
   SignalMap[CIGI_AEROSOL_RESP_PACKET_ID_V3] = SigAerosolResp;
   SignalMap[CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3] = SigMaritimeSurfaceResp;
   SignalMap[CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3] = SigTerrestrialSurfaceResp;
   SignalMap[CIGI_ANIMATION_STOP_PACKET_ID_V3] = SigAnimationStop;
   SignalMap[CIGI_EVENT_NOTIFICATION_PACKET_ID_V3] = SigEventNotification;
   SignalMap[CIGI_IG_MSG_PACKET_ID_V3] = SigIGMsg;
}

// ================================================
// SetProcTypeV1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetProcTypeV1()
{

   for(int ndx=0;ndx<255;ndx++)
   {
      ProcType[ndx] = 0;
   }

   ProcType[CIGI_ENTITY_CTRL_PACKET_ID_V1] = 1;

   if(ReaderCigiVersion == 3)
      ProcType[CIGI_ENV_CTRL_PACKET_ID_V1] = 2;

}

// ================================================
// SetProcTypeV1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetProcTypeV2()
{

   for(int ndx=0;ndx<255;ndx++)
   {
      ProcType[ndx] = 0;
   }

   ProcType[CIGI_ENTITY_CTRL_PACKET_ID_V2] = 1;

   if(ReaderCigiVersion == 3)
      ProcType[CIGI_ENV_CTRL_PACKET_ID_V2] = 2;

}

// ================================================
// SetProcTypeV1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiVersionJumpTable::SetProcTypeV3()
{

   for(int ndx=0;ndx<255;ndx++)
   {
      ProcType[ndx] = 0;
   }

   ProcType[CIGI_ENTITY_CTRL_PACKET_ID_V3] = 1;

   if(ReaderCigiVersion < 3)
   {
      ProcType[CIGI_ATMOS_CTRL_PACKET_ID_V3] = 3;
      ProcType[CIGI_CELESTIAL_CTRL_PACKET_ID_V3] = 3;
   }

}


