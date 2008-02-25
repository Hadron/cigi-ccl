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
 *  FILENAME:   CigiIGMsgV2.h
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
 *  06/12/2006 Greg Basler                       Version 1.7.1
 *  Changed native char type to Cigi type Cigi_Ascii.
 * </pre>
 *  The Boeing Company
 *  Version: 1.7.5
 */


#if !defined(_CIGI_IG_MSG_V2_INCLUDED_)
#define _CIGI_IG_MSG_V2_INCLUDED_

#include "CigiBaseIGMsg.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_IG_MSG_PACKET_ID_V2 108

class CIGI_SPEC CigiIGMsgV2 : public CigiBaseIGMsg
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiIGMsgV2();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiIGMsgV2();


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! The virtual Pack function for CIGI 2
   //! \param Base - A pointer to the instance of the packet
   //!          to be packed. (Downcast to CigiBasePacket)
   //! \param Buff - A pointer to the current pack point.
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBasePacket * Base, unsigned char * Buff, void *Spec) const;
   //=========================================================
   //! The virtual Unpack function for CIGI 2
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //! \param Spec - A pointer to special data -
   //!          This is not used in this class.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(unsigned char * Buff, bool Swap, void *Spec);



   //==> Accessing Member Variable Values functions

   //+> Msg

   //=========================================================
   //! Sets the Msg with bound checking control
   //! \param MsgIn - Message string
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetMsg(const Cigi_Ascii *MsgIn, bool bndchk=true);


};

#endif // #if !defined(_CIGI_IG_MSG_V2_INCLUDED_)
