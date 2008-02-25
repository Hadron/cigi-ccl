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
 *  FILENAME:   CigiBaseShortArtPartCtrl.cpp
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

#include "CigiBaseShortArtPartCtrl.h"
#include "CigiSwapping.h"
#include "CigiExceptions.h"


// ====================================================================
// Construction/Destruction
// ====================================================================


// ================================================
// CigiBaseShortArtPartCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseShortArtPartCtrl::CigiBaseShortArtPartCtrl()
{

}



// ================================================
// ~CigiBaseShortArtPartCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBaseShortArtPartCtrl::~CigiBaseShortArtPartCtrl()
{

}

// ====================================================================
// Accessors
// ====================================================================


// ================================================
// DofSelect1
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseShortArtPartCtrl::SetDofSelect1(const DofSelectGrp DofSelect1In, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((DofSelect1In < 0)||(DofSelect1In > 6)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("DofSelect1",(DofSelectGrp)DofSelect1In,0,6);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   DofSelect1 = DofSelect1In;
   return(CIGI_SUCCESS);

}


// ================================================
// DofSelect2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiBaseShortArtPartCtrl::SetDofSelect2(const DofSelectGrp DofSelect2In, bool bndchk)
{

#ifndef CIGI_NO_BND_CHK
   if(bndchk && ((DofSelect2In < 0)||(DofSelect2In > 6)))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("DofSelect2",(DofSelectGrp)DofSelect2In,0,6);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }
#endif

   DofSelect2 = DofSelect2In;
   return(CIGI_SUCCESS);

}


