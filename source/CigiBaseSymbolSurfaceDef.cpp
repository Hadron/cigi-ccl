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
 *  FILENAME:   CigiBaseSymbolSurfaceDef.cpp
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
 *  01/17/2008 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.7.5
 */


#define _EXPORT_CCL_


#include "CigiBaseSymbolSurfaceDef.h"
#include "CigiExceptions.h"



// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolSurfaceDef::CigiBaseSymbolSurfaceDef(void)
{
}

// ================================================
// ~CigiBaseEntityCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseSymbolSurfaceDef::~CigiBaseSymbolSurfaceDef(void)
{
}


// ====================================================================
// Conversion Control
// ====================================================================


// ================================================
// GetCnvt
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::GetCnvt(CigiVersionID &CnvtVersion,
                                      CigiCnvtInfoType::Type &CnvtInfo)
{
   if(CnvtVersion.GetCombinedCigiVersion() < 0x303)
   {
      CnvtInfo.ProcID = CigiProcessType::ProcNone;
      CnvtInfo.CnvtPacketID = 0;
   }
   else
   {
      CnvtInfo.ProcID = CigiProcessType::ProcStd;
      CnvtInfo.CnvtPacketID = CIGI_SYMBOL_SURFACE_DEF_PACKET_ID_V3_3;
   }

   return(CIGI_SUCCESS);
}


// ====================================================================
// Accessors
// ====================================================================

// ================================================
// SetSurfaceState
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetSurfaceState(
   const StateGrp SurfaceStateIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((SurfaceStateIn < Active)||(SurfaceStateIn > Destroyed)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Surface State",
                                         (int)SurfaceStateIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   SurfaceState = SurfaceStateIn;

   return(CIGI_SUCCESS);

}

// ================================================
// SetAttached
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetAttached(
   const AttachStateGrp AttachedIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((AttachedIn < EntityAttached) ||
      (AttachedIn > ViewAttached)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Attached State",
                                         (int)AttachedIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Attached = AttachedIn;

   return(CIGI_SUCCESS);

}

// ================================================
// SetBillBoardState
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetBillboardState(
   const BillboardStateGrp BillboardStateIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((BillboardStateIn < NotBillboard) ||
      (BillboardStateIn > Billboard)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Billboard State",
                                         (int)BillboardStateIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   BillboardState = BillboardStateIn;

   return(CIGI_SUCCESS);

}

// ================================================
// SetPerspectiveGrowth
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetPerspectiveGrowth(
   const PerspectiveGrowthStateGrp PerspectiveGrowthIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((PerspectiveGrowthIn < Disable) ||
      (PerspectiveGrowthIn > Enable)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Perspective Growth",
                                         (int)PerspectiveGrowthIn,0,1);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   PerspectiveGrowth = PerspectiveGrowthIn;

   return(CIGI_SUCCESS);

}

// ================================================
// SetYaw
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetYaw(const float YawIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((YawIn < 0.0) ||
      (YawIn > 360.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Yaw",
                                         (float)YawIn,0.0,360.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   YawBottom = YawIn;

   return(CIGI_SUCCESS);

}

// ================================================
// SetPitch
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetPitch(const float PitchIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((PitchIn < -90.0) ||
      (PitchIn > 90.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Pitch",
                                         (float)PitchIn,-90.0,90.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Pitch = PitchIn;

   return(CIGI_SUCCESS);

}

// ================================================
// SetRoll
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetRoll(const float RollIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((RollIn < -180.0) ||
      (RollIn > 180.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Roll",
                                         (float)RollIn,-180.0,180.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Roll = RollIn;

   return(CIGI_SUCCESS);

}

// ================================================
// SetLeftHalfAngle
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetLeftHalfAngle(
   const float LeftHalfAngle, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((LeftHalfAngle < -90.0) ||
      (LeftHalfAngle > 90.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Left Half Angle",
                                         (float)LeftHalfAngle,-90.0,90.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   XLeft = LeftHalfAngle;

   return(CIGI_SUCCESS);

}

// ================================================
// SetRightHalfAngle
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetRightHalfAngle(
   const float RightHalfAngle, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((RightHalfAngle < -90.0) ||
      (RightHalfAngle > 90.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Right Half Angle",
                                         (float)RightHalfAngle,-90.0,90.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   YRight = RightHalfAngle;

   return(CIGI_SUCCESS);

}

// ================================================
// SetTopHalfAngle
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetTopHalfAngle(
   const float TopHalfAngle, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((TopHalfAngle < -90.0) ||
      (TopHalfAngle > 90.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Top Half Angle",
                                         (float)TopHalfAngle,-90.0,90.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   ZTop = TopHalfAngle;

   return(CIGI_SUCCESS);

}

// ================================================
// SetBottomHalfAngle
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseSymbolSurfaceDef::SetBottomHalfAngle(
   const float BottomHalfAngle, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((BottomHalfAngle < -90.0) ||
      (BottomHalfAngle > 90.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Bottom Half Angle",
                                         (float)BottomHalfAngle,-90.0,90.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   YawBottom = BottomHalfAngle;

   return(CIGI_SUCCESS);

}




