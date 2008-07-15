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
 *  FILENAME:   CigiHatHotXRespV3.h
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
 *  Added the CIGI_SPEC modifier to the class declaration for exporting the 
 *  class in a Windows DLL.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Changed native C++ types in function declarations to CCL-defined types.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  01/22/2007 Greg Basler                       Version 1.7.5
 *  Removed the accessors for ReqType.  Request Type or Response Type is
 *  not availible for the HAT/HOT Extended Response Packet.
 *  
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Added new version conversion method.
 *  Moved Packet information to base packet.
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_HAT_HOT_XRESP_V3_INCLUDED_)
#define _CIGI_HAT_HOT_XRESP_V3_INCLUDED_

#include "CigiBaseHatHotResp.h"



class CIGI_SPEC CigiHatHotXRespV3 : public CigiBaseHatHotResp
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiHatHotXRespV3();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiHatHotXRespV3();


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! The virtual Pack function for CIGI 3
   //! \param Base - A pointer to the instance of the packet 
   //!          to be packed. (Downcast to CigiBasePacket)
   //! \param Buff - A pointer to the current pack point.
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const;

   //=========================================================
   //! The virtual Unpack function for CIGI 3
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec);

   //=========================================================
   //! A virtual Conversion Information function.
   //! This function provides conversion information for this
   //!  packet.
   //! \param CnvtVersion - The CIGI version to which this packet
   //!    is being converted.
   //! \param CnvtInfo - The information needed for conversion
   //!    
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	virtual int GetCnvt(CigiVersionID &CnvtVersion,
                       CigiCnvtInfoType::Type &CnvtInfo);



   //==> Accessing Member Variable Values functions

   //+> Hat

   //=========================================================
   //! Sets the Hat with bound checking control
   //! \param HatIn - Height above terrain result
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetHat(const double HatIn, bool bndchk=true)
   {
      Hat = HatIn;
      VldHat = true;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Hat value.
   //! \return the current Hat.
   double GetHat(void) const { return(Hat); }


   //+> Hot

   //=========================================================
   //! Sets the Hot with bound checking control
   //! \param HotIn - Height of terrain result
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetHot(const double HotIn, bool bndchk=true)
   {
      Hot = HotIn;
      VldHot = true;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Hot value.
   //! \return the current Hot.
   double GetHot(void) const { return(Hot); }


   //+> Material

   //=========================================================
   //! Sets the Material with bound checking control
   //! \param MaterialIn - Material Code of the test point
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetMaterial(const Cigi_uint32 MaterialIn, bool bndchk=true)
   {
      Material = MaterialIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Material value.
   //! \return the current Material.
   Cigi_uint32 GetMaterial(void) const { return(Material); }


   //+> NormAz

   //=========================================================
   //! Sets the NormAz with bound checking control
   //! \param NormAzIn - The Azimuth from true north of the normal 
   //!   vector of the polygon which contains the test point.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetNormAz(const float NormAzIn, bool bndchk=true);

   //=========================================================
   //! Gets the NormAz value.
   //! \return the current NormAz.
   float GetNormAz(void) const { return(NormAz); }


   //+> NormEl

   //=========================================================
   //! Sets the NormEl with bound checking control
   //! \param NormElIn - The Elevation of the normal vector of the polygon
   //!   which contains the test point.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetNormEl(const float NormElIn, bool bndchk=true);

   //=========================================================
   //! Gets the NormEl value.
   //! \return the current NormEl.
   float GetNormEl(void) const { return(NormEl); }



};

#endif // #if !defined(_CIGI_HAT_HOT_XRESP_V3_INCLUDED_)
