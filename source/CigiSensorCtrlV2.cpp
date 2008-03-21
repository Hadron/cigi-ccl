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
 *  FILENAME:   CigiSensorCtrlV2.cpp
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
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Removed the inline defnitions for the PackedPointer union.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Changed native C++ types to use CCL-defined types instead where appropriate.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the class constructor to initialize the MinorVersion member 
 *  variable.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 * </pre>
 *  Author: The Boeing Company
 *  Version: 2.0.0
 */

#define _EXPORT_CCL_

#include "CigiSensorCtrlV2.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"

#include <memory.h>


#ifdef CIGI_LITTLE_ENDIAN
   #define CIGI_SCOPY2 CigiSwap2
   #define CIGI_SCOPY4 CigiSwap4
   #define CIGI_SCOPY8 CigiSwap8
#else
   #define CIGI_SCOPY2 CigiCopy2
   #define CIGI_SCOPY4 CigiCopy4
   #define CIGI_SCOPY8 CigiCopy8
#endif




// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiSensorCtrlV2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSensorCtrlV2::CigiSensorCtrlV2()
{

   PacketID = CIGI_SENSOR_CTRL_PACKET_ID_V2;
   PacketSize = CIGI_SENSOR_CTRL_PACKET_SIZE_V2;
   Version = 2;
   MinorVersion = 0;

   ViewID = 0;
   SensorID = 0;
   SensorOn = false;
   Polarity = WhiteHot;
   LineDropEn = false;
   TrackMode = TrackOff;
   AutoGainEn = false;
   TrackPolarity = TrackWhite;
   ResponseType = GatePos;
   Gain = 0.0;
   Level = 0.0;
   ACCoupling = 0.0;
   Noise = 0.0;

}

// ================================================
// ~CigiSensorCtrlV2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiSensorCtrlV2::~CigiSensorCtrlV2()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSensorCtrlV2::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   double DBuf[6];
   Cigi_uint16 tViewID;

   Cigi_uint8 *tBuf = (Cigi_uint8 *)DBuf;

   PackPointer CDta;

   CigiBaseSensorCtrl * Data = ( CigiBaseSensorCtrl *)Base;

   CDta.d = DBuf;

   *CDta.c++ = PacketID;
   *CDta.c++ = PacketSize;

   tViewID = Data->ViewID;

   if(tViewID > 31)
      tViewID = 31;

   Cigi_uint8 HDta = (Cigi_uint8)tViewID << 3;

   if(Data->SensorOn)
      HDta |= 0x04;

   if(Data->Polarity == BlackHot)
      HDta |= 0x02;

   if(Data->LineDropEn)
      HDta |= 0x01;

   *CDta.c++ = HDta;

   *CDta.c++ = Data->SensorID;

   HDta = (Cigi_uint8)(Data->TrackMode << 4);

   if(Data->AutoGainEn)
      HDta |= 0x08;

   if(Data->TrackPolarity == TrackBlack)
      HDta |= 0x04;

   *CDta.c++ = HDta;

   *CDta.c++ = 0;
   *CDta.s++ = 0;

   CIGI_SCOPY4(CDta.f++, &Data->Gain);
   CIGI_SCOPY4(CDta.f++, &Data->Level);
   CIGI_SCOPY4(CDta.f++, &Data->ACCoupling);
   CIGI_SCOPY4(CDta.f++, &Data->Noise);

   memcpy(Buff,tBuf,CIGI_SENSOR_CTRL_PACKET_SIZE_V2);

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSensorCtrlV2::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   double DBuf[6];

   Cigi_uint8 *tBuf = (Cigi_uint8 *)DBuf;

   PackPointer CDta;

   memcpy(tBuf,Buff,CIGI_SENSOR_CTRL_PACKET_SIZE_V2);

   CDta.d = DBuf;

   CDta.c += 2;  // Step over packet id and size

   Cigi_uint8 HDta = *CDta.c++;

   ViewID = (Cigi_uint8)((HDta >> 3) & 0x1f);
   SensorOn = ((HDta & 0x04) != 0);
   Polarity = (PolarityGrp)((HDta >> 1) & 0x01);
   LineDropEn = ((HDta & 0x01) != 0);

   SensorID = *CDta.c++;

   HDta = *CDta.c++;
   TrackMode = (TrackModeGrp)((HDta >> 4) & 0x0f);
   AutoGainEn = ((HDta & 0x08) != 0);
   TrackPolarity = (TrackPolarityGrp)((HDta >> 2) & 0x01);

   CDta.c += 3;

   CIGI_SCOPY4(&Gain, CDta.f++);

   CIGI_SCOPY4(&Level, CDta.f++);
   CIGI_SCOPY4(&ACCoupling, CDta.f++);
   CIGI_SCOPY4(&Noise, CDta.f++);

   ResponseType = GatePos;

   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================


// ================================================
// SetViewID
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSensorCtrlV2::SetViewID(const Cigi_uint16 ViewIDIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((ViewIDIn < 0)||(ViewIDIn > 31)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("ViewID",(Cigi_uint16)ViewIDIn,0,31);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   ViewID = ViewIDIn;
   return(CIGI_SUCCESS);

}


// ================================================
// Gain
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiSensorCtrlV2::SetGain(const float GainIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((GainIn < 0.0)||(GainIn > 1.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Gain",(float)GainIn,0.0,1.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Gain = GainIn;
   return(CIGI_SUCCESS);

}


