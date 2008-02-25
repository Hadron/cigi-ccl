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
 *  FILENAME:   CigiBaseWaveCtrl.cpp
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
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.7.5
 */

#define _EXPORT_CCL_

#include "CigiBaseWaveCtrl.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiBaseWaveCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseWaveCtrl::CigiBaseWaveCtrl()
{

}



// ================================================
// ~CigiBaseWaveCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseWaveCtrl::~CigiBaseWaveCtrl()
{

}

// ====================================================================
// Accessors
// ====================================================================


// ================================================
// Scope
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseWaveCtrl::SetScope(const ScopeGrp ScopeIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((ScopeIn < 0)||(ScopeIn > 2)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Scope",(ScopeGrp)ScopeIn,0,2);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Scope = ScopeIn;
   return(CIGI_SUCCESS);

}


// ================================================
// Breaker
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseWaveCtrl::SetBreaker(const BreakerGrp BreakerIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((BreakerIn < 0)||(BreakerIn > 2)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Breaker",(BreakerGrp)BreakerIn,0,2);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Breaker = BreakerIn;
   return(CIGI_SUCCESS);

}


// ================================================
// WaveHt
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseWaveCtrl::SetWaveHt(const float WaveHtIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && (WaveHtIn < 0.0))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("WaveHt",(float)WaveHtIn,">",0.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   WaveHt = WaveHtIn;
   return(CIGI_SUCCESS);

}


// ================================================
// WaveLen
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseWaveCtrl::SetWaveLen(const float WaveLenIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && (WaveLenIn < 0.0))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("WaveLen",(float)WaveLenIn,">",0.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   WaveLen = WaveLenIn;
   return(CIGI_SUCCESS);

}


// ================================================
// Period
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseWaveCtrl::SetPeriod(const float PeriodIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && (PeriodIn < 0.0))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Period",(float)PeriodIn,">",0.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Period = PeriodIn;
   return(CIGI_SUCCESS);

}


// ================================================
// Direction
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseWaveCtrl::SetDirection(const float DirectionIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((DirectionIn < 0.0)||(DirectionIn > 360.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Direction",(float)DirectionIn,0.0,360.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Direction = DirectionIn;
   return(CIGI_SUCCESS);

}


// ================================================
// PhaseOff
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseWaveCtrl::SetPhaseOff(const float PhaseOffIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((PhaseOffIn < -360.0)||(PhaseOffIn > 360.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("PhaseOff",(float)PhaseOffIn,-360.0,360.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   PhaseOff = PhaseOffIn;
   return(CIGI_SUCCESS);

}


// ================================================
// Leading
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseWaveCtrl::SetLeading(const float LeadingIn, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((LeadingIn < -180.0)||(LeadingIn > 180.0)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("Leading",(float)LeadingIn,-180.0,180.0);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   Leading = LeadingIn;
   return(CIGI_SUCCESS);

}


