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
 *  FILENAME:   CigiCollDetSegRespV1.h
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
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Moved Packet information to base packet.
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_COLL_DET_SEG_RESP_V1_INCLUDED_)
#define _CIGI_COLL_DET_SEG_RESP_V1_INCLUDED_

#include "CigiBaseCollDetSegResp.h"


class CIGI_SPEC CigiCollDetSegRespV1 : public CigiBaseCollDetSegResp
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiCollDetSegRespV1();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiCollDetSegRespV1();


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! The virtual Pack function for CIGI 1
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
   //! The virtual Unpack function for CIGI 1
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec);



   //==> Accessing Member Variable Values functions

   //+> SegID

   //=========================================================
   //! Sets the SegID with bound checking control
   //! \param SegIDIn - Segment ID
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetSegID(const Cigi_uint8 SegIDIn, bool bndchk=true);

   //=========================================================
   //! Gets the SegID value.
   //! \return the current SegID.
   Cigi_uint8 GetSegID(void) const { return(SegID); }


   //+> X

   //=========================================================
   //! Sets the X with bound checking control
   //! \param XIn - The collision point along the X axis of the
   //!    originating entity.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetX(const float XIn, bool bndchk=true)
   {
      X = XIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the X value.
   //! \return the current X.
   float GetX(void) const { return(X); }


   //+> Y

   //=========================================================
   //! Sets the Y with bound checking control
   //! \param YIn - The collision point along the Y axis of the
   //!    originating entity.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetY(const float YIn, bool bndchk=true)
   {
      Y = YIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Y value.
   //! \return the current Y.
   float GetY(void) const { return(Y); }


   //+> Z

   //=========================================================
   //! Sets the Z with bound checking control
   //! \param ZIn - The collision point along the Z axis of the
   //!    originating entity.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetZ(const float ZIn, bool bndchk=true)
   {
      Z = ZIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Z value.
   //! \return the current Z.
   float GetZ(void) const { return(Z); }



};

#endif // #if !defined(_CIGI_COLL_DET_SEG_RESP_V1_INCLUDED_)
