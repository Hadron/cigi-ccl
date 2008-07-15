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
 *  FILENAME:   CigiViewDefV3.h
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
 *  11/20/2007 Greg Basler                       Version 2.0.0
 *  Moved Packet information to base packet.
 *  
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if !defined(_CIGI_VIEW_DEF_V3_INCLUDED_)
#define _CIGI_VIEW_DEF_V3_INCLUDED_

#include "CigiBaseViewDef.h"



class CIGI_SPEC CigiViewDefV3 : public CigiBaseViewDef
{

public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiViewDefV3();

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiViewDefV3();


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



   //==> Accessing Member Variable Values functions

   //+> ViewID

   //=========================================================
   //! Sets the ViewID with bound checking control
   //! \param ViewIDIn - The View this packet to which this packet is applied.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetViewID(const Cigi_uint16 ViewIDIn, bool bndchk=true)
   {
      ViewID = ViewIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the ViewID value.
   //! \return the current ViewID.
   Cigi_uint16 GetViewID(void) const { return(ViewID); }


   //+> GroupID

   //=========================================================
   //! Sets the GroupID with bound checking control
   //! \param GroupIDIn - The group in which this view is place.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetGroupID(const Cigi_uint8 GroupIDIn, bool bndchk=true)
   {
      GroupID = GroupIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the GroupID value.
   //! \return the current GroupID.
   Cigi_uint8 GetGroupID(void) const { return(GroupID); }


   //+> FOVNearEn

   //=========================================================
   //! Sets the FOVNearEn with bound checking control
   //! \param FOVNearEnIn - States the validity of the FOVNear parameter<br>
   //!   true - valid data : false - data is not valid
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFOVNearEn(const bool FOVNearEnIn, bool bndchk=true)
   {
      FOVNearEn = FOVNearEnIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the FOVNearEn value.
   //! \return the current FOVNearEn.
   bool GetFOVNearEn(void) const { return(FOVNearEn); }


   //+> FOVFarEn

   //=========================================================
   //! Sets the FOVFarEn with bound checking control
   //! \param FOVFarEnIn - States the validity of the FOVFar parameter<br>
   //!   true - valid data : false - data is not valid
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFOVFarEn(const bool FOVFarEnIn, bool bndchk=true)
   {
      FOVFarEn = FOVFarEnIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the FOVFarEn value.
   //! \return the current FOVFarEn.
   bool GetFOVFarEn(void) const { return(FOVFarEn); }


   //+> FOVLeftEn

   //=========================================================
   //! Sets the FOVLeftEn with bound checking control
   //! \param FOVLeftEnIn - States the validity of the FOVLeft parameter<br>
   //!   true - valid data : false - data is not valid
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFOVLeftEn(const bool FOVLeftEnIn, bool bndchk=true)
   {
      FOVLeftEn = FOVLeftEnIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the FOVLeftEn value.
   //! \return the current FOVLeftEn.
   bool GetFOVLeftEn(void) const { return(FOVLeftEn); }


   //+> FOVRightEn

   //=========================================================
   //! Sets the FOVRightEn with bound checking control
   //! \param FOVRightEnIn - States the validity of the FOVRight parameter<br>
   //!   true - valid data : false - data is not valid
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFOVRightEn(const bool FOVRightEnIn, bool bndchk=true)
   {
      FOVRightEn = FOVRightEnIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the FOVRightEn value.
   //! \return the current FOVRightEn.
   bool GetFOVRightEn(void) const { return(FOVRightEn); }


   //+> FOVTopEn

   //=========================================================
   //! Sets the FOVTopEn with bound checking control
   //! \param FOVTopEnIn - States the validity of the FOVTop parameter<br>
   //!   true - valid data : false - data is not valid
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFOVTopEn(const bool FOVTopEnIn, bool bndchk=true)
   {
      FOVTopEn = FOVTopEnIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the FOVTopEn value.
   //! \return the current FOVTopEn.
   bool GetFOVTopEn(void) const { return(FOVTopEn); }


   //+> FOVBottomEn

   //=========================================================
   //! Sets the FOVBottomEn with bound checking control
   //! \param FOVBottomEnIn - States the validity of the FOVBottom parameter<br>
   //!   true - valid data : false - data is not valid
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFOVBottomEn(const bool FOVBottomEnIn, bool bndchk=true)
   {
      FOVBottomEn = FOVBottomEnIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the FOVBottomEn value.
   //! \return the current FOVBottomEn.
   bool GetFOVBottomEn(void) const { return(FOVBottomEn); }


   //+> ProjectionType

   //=========================================================
   //! Sets the ProjectionType with bound checking control
   //! \param ProjectionTypeIn - The projection type (OpenGL compatible)<br>
   //!   Perspective=0<br>
   //!   Orthographic=1<br>
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetProjectionType(const ProjectionTypeGrp ProjectionTypeIn, bool bndchk=true);

   //=========================================================
   //! Gets the ProjectionType value.
   //! \return the current ProjectionType.
   ProjectionTypeGrp GetProjectionType(void) const { return(ProjectionType); }


   //+> Reorder

   //=========================================================
   //! Sets the Reorder with bound checking control
   //! \param ReorderIn - Specifies whether the views should be reordered
   //!   false - No Reordering : true - bring to front
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetReorder(const bool ReorderIn, bool bndchk=true)
   {
      Reorder = ReorderIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Reorder value.
   //! \return the current Reorder.
   bool GetReorder(void) const { return(Reorder); }

};

#endif // #if !defined(_CIGI_VIEW_DEF_V3_INCLUDED_)
