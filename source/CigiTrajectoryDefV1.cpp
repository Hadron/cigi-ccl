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
 *  FILENAME:   CigiTrajectoryDefV1.cpp
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
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the class constructor to initialize the MinorVersion member 
 *  variable.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.7.5
 */

#define _EXPORT_CCL_

#include "CigiTrajectoryDefV1.h"
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
// CigiTrajectoryDefV1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiTrajectoryDefV1::CigiTrajectoryDefV1()
{

   PacketID = CIGI_TRAJECTORY_DEF_PACKET_ID_V1;
   PacketSize = CIGI_TRAJECTORY_DEF_PACKET_SIZE_V1;
   Version = 1;
   MinorVersion = 0;

   EntityID = 0;
   Accel = 0.0;
   RetardationRate = 0.0;
   TermVel = 0.0;
   Xoff = 0.0;
   Yoff = 0.0;
   Zoff = 0.0;
   AccelX = 0.0;
   AccelY = 0.0;
   AccelZ = 0.0;

}

// ================================================
// ~CigiTrajectoryDefV1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiTrajectoryDefV1::~CigiTrajectoryDefV1()
{

}

// ====================================================================
// Pack and Unpack
// ====================================================================

// ================================================
// Pack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiTrajectoryDefV1::Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const
{
   double DBuf[6];

   Cigi_uint8 *tBuf = (Cigi_uint8 *)DBuf;

   PackPointer CDta;

   CigiBaseTrajectoryDef * Data = ( CigiBaseTrajectoryDef *)Base;

   CDta.d = DBuf;

   *CDta.c++ = PacketID;
   *CDta.c++ = PacketSize;

   CIGI_SCOPY2(CDta.s++, &Data->EntityID);
   CIGI_SCOPY4(CDta.f++, &Data->Accel);
   CIGI_SCOPY4(CDta.f++, &Data->RetardationRate);
   CIGI_SCOPY4(CDta.f++, &Data->TermVel);
   CIGI_SCOPY4(CDta.f++, &Data->Xoff);
   CIGI_SCOPY4(CDta.f++, &Data->Yoff);
   CIGI_SCOPY4(CDta.f++, &Data->Zoff);

   memcpy(Buff,tBuf,CIGI_TRAJECTORY_DEF_PACKET_SIZE_V1);

   return(PacketSize);

}

// ================================================
// Unpack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiTrajectoryDefV1::Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec)
{
   double DBuf[6];

   Cigi_uint8 *tBuf = (Cigi_uint8 *)DBuf;

   PackPointer CDta;

   memcpy(tBuf,Buff,CIGI_TRAJECTORY_DEF_PACKET_SIZE_V1);

   CDta.d = DBuf;

   CDta.c += 2;  // Step over packet id and size

   CIGI_SCOPY2(&EntityID, CDta.s++);
   CIGI_SCOPY4(&Accel, CDta.f++);
   CIGI_SCOPY4(&RetardationRate, CDta.f++);
   CIGI_SCOPY4(&TermVel, CDta.f++);
   CIGI_SCOPY4(&Xoff, CDta.f++);
   CIGI_SCOPY4(&Yoff, CDta.f++);
   CIGI_SCOPY4(&Zoff, CDta.f++);

   AccelX = 0.0f;
   AccelY = 0.0f;
   AccelZ = Accel;

   return(PacketSize);

}



// ====================================================================
// Accessors
// ====================================================================


