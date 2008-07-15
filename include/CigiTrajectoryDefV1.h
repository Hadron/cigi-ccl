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
 *  FILENAME:   CigiTrajectoryDefV1.h
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


#if !defined(_CIGI_TRAJECTORY_DEF_V1_INCLUDED_)
#define _CIGI_TRAJECTORY_DEF_V1_INCLUDED_

#include "CigiBaseTrajectoryDef.h"


class CIGI_SPEC CigiTrajectoryDefV1 : public CigiBaseTrajectoryDef
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiTrajectoryDefV1();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiTrajectoryDefV1();


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

   //+> Accel

   //=========================================================
   //! Sets the Accel with bound checking control
   //! \param AccelIn - Acceleration value.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAccel(const float AccelIn, bool bndchk=true)
   {
      Accel = AccelIn;
      AccelZ = Accel;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Accel value.
   //! \return the current Accel.
   float GetAccel(void) const { return(Accel); }


   //+> Xoff

   //=========================================================
   //! Sets the Xoff with bound checking control
   //! \param XoffIn - The offset along the entity's X axis from 
   //!   the entity's reference point from which the trajectory is started.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetXoff(const float XoffIn, bool bndchk=true)
   {
      Xoff = XoffIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Xoff value.
   //! \return the current Xoff.
   float GetXoff(void) const { return(Xoff); }


   //+> Yoff

   //=========================================================
   //! Sets the Yoff with bound checking control
   //! \param YoffIn - The offset along the entity's Y axis from 
   //!   the entity's reference point from which the trajectory is started.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetYoff(const float YoffIn, bool bndchk=true)
   {
      Yoff = YoffIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Yoff value.
   //! \return the current Yoff.
   float GetYoff(void) const { return(Yoff); }


   //+> Zoff

   //=========================================================
   //! Sets the Zoff with bound checking control
   //! \param ZoffIn - The offset along the entity's Z axis from 
   //!   the entity's reference point from which the trajectory is started.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetZoff(const float ZoffIn, bool bndchk=true)
   {
      Zoff = ZoffIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Zoff value.
   //! \return the current Zoff.
   float GetZoff(void) const { return(Zoff); }



};

#endif // #if !defined(_CIGI_TRAJECTORY_DEF_V1_INCLUDED_)
