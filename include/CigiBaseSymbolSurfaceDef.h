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
 *  FILENAME:   CigiBaseSymbolSurfaceDef.h
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
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.7.5
 */

#if !defined(_CIGI_BASE_SYMBOL_SURFACE_DEF_INCLUDED_)
#define _CIGI_BASE_SYMBOL_SURFACE_DEF_INCLUDED_


#include "CigiBasePacket.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_SYMBOL_SURFACE_DEF_PACKET_ID_V3_3 240  // FIXME
#define CIGI_SYMBOL_SURFACE_DEF_PACKET_SIZE_V3_3 56


class CigiSymbolSurfaceDefV3_3;


//=========================================================
//! The base class for all packets.
//!
class CIGI_SPEC CigiBaseSymbolSurfaceDef :
   public CigiBasePacket
{

   friend class CigiSymbolSurfaceDefV3_3;

public:

   //=========================================================
   //! The enumeration for the CigiBaseSymbolSurfaceDef State Group
   //!
   enum StateGrp
   {
      Active=0,
      Destroyed=1
   };

   //=========================================================
   //! The enumeration for the Enitity/View Attached flag
   //!
   enum AttachStateGrp
   {
      EntityAttached=0,
      ViewAttached=1
   };

   //=========================================================
   //! The enumeration for the Billboard State flag
   //!
   enum BillboardStateGrp
   {
      NotBillboard=0,
      Billboard=1
   };

   //=========================================================
   //! The enumeration for the Perspective Growth flag
   //!
   enum PerspectiveGrowthStateGrp
   {
      Disable=0,
      Enable=1
   };


   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiBaseSymbolSurfaceDef(void);

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiBaseSymbolSurfaceDef(void);


   //==> Buffer Packing/Unpacking

   //=========================================================
   //! A pure virtual Pack function.
   //! This function is not implemented in this class.
   //! \param Base - A pointer to the instance of the packet
   //!          to be packed. (Downcast to CigiBasePacket)
   //! \param Buff - A pointer to the current pack point.
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Pack(CigiBasePacket * Base, Cigi_uint8 * Buff, void *Spec) const=0;

   //=========================================================
   //! A pure virtual Unpack function.
   //! This function is not implemented in this class.
   //! \param Buff - A pointer to the current pack point.
   //! \param Swap - N/A for V1 & V2
   //! \param Spec - A pointer to special data.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   //!
   virtual int Unpack(Cigi_uint8 * Buff, bool Swap, void *Spec) =0;

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

   //+> SurfaceID

   //=========================================================
   //! Sets the Surface ID with bound checking control
   //! \param SurfaceIDIn - The ID of this surface
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetSurfaceID(const Cigi_uint16 SurfaceIDIn, bool bndchk=true)
   {
      SurfaceID = SurfaceIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Surface ID value
   //! \return The Surface ID uniquely identifying the specific surface
   //!
   Cigi_uint16 GetSurfaceID(void) const { return(SurfaceID); }


   //+> SurfaceState

   //=========================================================
   //! Sets the Surface State with bound checking control
   //! \param SurfaceStateIn - The commanded state of this
   //!   surface (Active/Destroyed)
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetSurfaceState(const StateGrp SurfaceStateIn, bool bndchk=true);

   //=========================================================
   //! Gets the Surface State value
   //! \return The current state (Active/Destroyed) of the this
   //!   surface.
   //!
   StateGrp GetSurfaceState(void) const { return(SurfaceState); }


   //+> Attached

   //=========================================================
   //! Sets the Attached State with bound checking control
   //! \param AttachedIn - The commanded Attachment or independance
   //!   of this surface (Entity Attached/View Attached)
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAttached(const AttachStateGrp AttachedIn, bool bndchk=true);

   //=========================================================
   //! Gets the Attached State value
   //! \return The current state (Active/Destroyed) of the this
   //!   surface.
   //!
   AttachStateGrp GetAttached(void) const { return(Attached); }


   //+> BillBoardState

   //=========================================================
   //! Sets the Billboard State with bound checking control
   //! \param BillboardStateIn - The commanded "Billboard" or
   //!    "NotBillboard" state of this surface
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetBillboardState(const BillboardStateGrp BillboardStateIn, bool bndchk=true);

   //=========================================================
   //! Gets the Surface State value
   //! \return The whether this surface is a billboard or not.
   //!
   BillboardStateGrp GetBillboardState(void) const { return(BillboardState); }


   //+> PerspectiveGrowth

   //=========================================================
   //! Sets the Perspective Growth with bound checking control
   //! \param PerspectiveGrowthIn - Enables or Disables the
   //!    Perspective Growth of this surface, if the surface
   //!    is a Billboard.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetPerspectiveGrowth(const PerspectiveGrowthStateGrp PerspectiveGrowthIn, bool bndchk=true);

   //=========================================================
   //! Gets the Perspective Growth value
   //! \return The whether this surface has Perspective Growth
   //!   Enabled or Disabled.
   //!
   PerspectiveGrowthStateGrp GetPerspectiveGrowth(void) const { return(PerspectiveGrowth); }


   //+> Attach

   //=========================================================
   //! Sets the Entity ID with bound checking control
   //! \param EntityIDIn - The ID of the Entity to which this
   //!   surface is attached.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetEntityID(const Cigi_uint16 EntityIDIn, bool bndchk=true)
   {
      EntityViewID = EntityIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Entity ID value to which this surface is attached.
   //! \return The Attached Entity ID.
   //!
   Cigi_uint16 GetEntityID(void) const { return(EntityViewID); }

   //=========================================================
   //! Sets the View ID with bound checking control
   //! \param ViewIDIn - The ID of the View to which this
   //!   surface is attached.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetViewID(const Cigi_uint16 ViewIDIn, bool bndchk=true)
   {
      EntityViewID = ViewIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the View ID value to which this surface is attached.
   //! \return The Attached View ID.
   //!
   Cigi_uint16 GetViewID(void) const { return(EntityViewID); }


   //+> Offsets

   //=========================================================
   //! Sets the Offset along the Entity's body X axis from the
   //!   Entity to the attached surface with bound checking control
   //! \param XOffsetIn - The X Offset.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetXOffset(const float XOffsetIn, bool bndchk=true)
   {
      XLeft = XOffsetIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Offset along the Entity's body X axis from the
   //!   Entity to the attached surface.
   //!
   float GetXOffset(void) const { return(XLeft); }

   //=========================================================
   //! Sets the Offset along the Entity's body Y axis from the
   //!   Entity to the attached surface with bound checking control
   //! \param YOffsetIn - The Y Offset.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetYOffset(const float YOffsetIn, bool bndchk=true)
   {
      YRight = YOffsetIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Offset along the Entity's body Y axis from the
   //!   Entity to the attached surface.
   //!
   float GetYOffset(void) const { return(YRight); }

   //=========================================================
   //! Sets the Offset along the Entity's body Z axis from the
   //!   Entity to the attached surface with bound checking control
   //! \param XOffsetIn - The Z Offset.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetZOffset(const float ZOffsetIn, bool bndchk=true)
   {
      ZTop = ZOffsetIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Offset along the Entity's body Z axis from the
   //!   Entity to the attached surface.
   //!
   float GetZOffset(void) const { return(ZTop); }


   //+> Attitude

   //=========================================================
   //! Sets the Yaw of the surface with respect to the Entity's
   //!   body coordinate system with bound checking control
   //! \param YawIn - The Yaw of the surface.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetYaw(const float YawIn, bool bndchk=true);

   //=========================================================
   //! Gets the Yaw of the surface with respect to the Entity's
   //!   body coordinate system.
   //!
   float GetYaw(void) const { return(YawBottom); }

   //=========================================================
   //! Sets the Pitch of the surface with respect to the Entity's
   //!   body coordinate system with bound checking control
   //! \param PitchIn - The Pitch of the surface.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetPitch(const float PitchIn, bool bndchk=true);

   //=========================================================
   //! Gets the Pitch of the surface with respect to the Entity's
   //!   body coordinate system.
   //!
   float GetPitch(void) const { return(Pitch); }

   //=========================================================
   //! Sets the Roll of the surface with respect to the Entity's
   //!   body coordinate system with bound checking control
   //! \param RollIn - The Roll of the surface.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetRoll(const float RollIn, bool bndchk=true);

   //=========================================================
   //! Gets the Roll of the surface with respect to the Entity's
   //!   body coordinate system.
   //!
   float GetRoll(void) const { return(Roll); }


   //+> Size

   //=========================================================
   //! Sets the Width of the entity attached surface.
   //! \param RollIn - The width of the surface.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetWidth(const float WidthIn, bool bndchk=true)
   {
      Width = WidthIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Width of the entity attached surface.
   //!
   float GetWidth(void) const { return(Width); }

   //=========================================================
   //! Sets the Height of the entity attached surface.
   //! \param RollIn - The Height of the surface.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetHeight(const float HeightIn, bool bndchk=true)
   {
      Height = HeightIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Height of the entity attached surface.
   //!
   float GetHeight(void) const { return(Height); }



   //+> Half Angles

   //=========================================================
   //! Sets the Left Half Angle of the surface.
   //! \param LeftHalfAngle - The Left Half Angle.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetLeftHalfAngle(const float LeftHalfAngle, bool bndchk=true);

   //=========================================================
   //! Gets the Left Half Angle of the surface.
   //!
   float GetLeftHalfAngle(void) const { return(XLeft); }

   //=========================================================
   //! Sets the Right Half Angle of the surface.
   //! \param RightHalfAngle - The Right Half Angle.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetRightHalfAngle(const float RightHalfAngle, bool bndchk=true);

   //=========================================================
   //! Gets the Right Half Angle of the surface.
   //!
   float GetRightHalfAngle(void) const { return(YRight); }

   //=========================================================
   //! Sets the Top Half Angle of the surface.
   //! \param TopHalfAngle - The Top Half Angle.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetTopHalfAngle(const float TopHalfAngle, bool bndchk=true);

   //=========================================================
   //! Gets the Top Half Angle of the surface.
   //!
   float GetTopHalfAngle(void) const { return(ZTop); }

   //=========================================================
   //! Sets the Bottom Half Angle of the surface.
   //! \param BottomHalfAngle - The Bottom Half Angle.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetBottomHalfAngle(const float BottomHalfAngle, bool bndchk=true);

   //=========================================================
   //! Gets the Bottom Half Angle of the surface.
   //!
   float GetBottomHalfAngle(void) const { return(YawBottom); }


   //+> Edge Coordinates

   //=========================================================
   //! Sets the Left Edge Coordinate of the surface.
   //! This specifies the left most U coordinate contained
   //!   within the surface boundaries.
   //! \param LeftEdgeIn - The Left Edge U Coordinate.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetLeftEdge(const float LeftEdgeIn, bool bndchk=true)
   {
      LeftEdge = LeftEdgeIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Left Edge Coordinate of the surface.
   //! This is the left most U coordinate contained
   //!   within the surface boundaries.
   //!
   float GetLeftEdge(void) const { return(LeftEdge); }

   //=========================================================
   //! Sets the Right Edge Coordinate of the surface.
   //! This specifies the Right most U coordinate contained
   //!   within the surface boundaries.
   //! \param RightEdgeIn - The Right Edge U Coordinate.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetRightEdge(const float RightEdgeIn, bool bndchk=true)
   {
      RightEdge = RightEdgeIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Right Edge Coordinate of the surface.
   //! This is the Right most U coordinate contained
   //!   within the surface boundaries.
   //!
   float GetRightEdge(void) const { return(RightEdge); }

   //=========================================================
   //! Sets the Top Edge Coordinate of the surface.
   //! This specifies the Top most V coordinate contained
   //!   within the surface boundaries.
   //! \param TopEdgeIn - The Top Edge V Coordinate.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetTopEdge(const float TopEdgeIn, bool bndchk=true)
   {
      TopEdge = TopEdgeIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Top Edge Coordinate of the surface.
   //! This is the Top most V coordinate contained
   //!   within the surface boundaries.
   //!
   float GetTopEdge(void) const { return(TopEdge); }

   //=========================================================
   //! Sets the Bottom Edge Coordinate of the surface.
   //! This specifies the Bottom most V coordinate contained
   //!   within the surface boundaries.
   //! \param BottomEdgeIn - The Bottom Edge V Coordinate.
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetBottomEdge(const float BottomEdgeIn, bool bndchk=true)
   {
      BottomEdge = BottomEdgeIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Bottom Edge Coordinate of the surface.
   //! This is the Bottom most V coordinate contained
   //!   within the surface boundaries.
   //!
   float GetBottomEdge(void) const { return(BottomEdge); }



protected:

   //==> Member variables

   //=========================================================
   //! SurfaceID<br>
   //! This parameter specifies the symbol surface to which
   //!  this packet is applied.
   //!
   Cigi_uint16 SurfaceID;

   //=========================================================
   //! SurfaceState<br>
   //! This parameter specifies whether the symbol surface
   //! should be active or destroyed.
   //! Active - The surface is active and symbols may be drawn
   //!  on it.  It can be positioned, oriented, and sized.
   //!  It can also be attached to an entity or a view.
   //! Destroyed - The surface is removed from the system.
   //!  Any symbols drawn to it are also destroyed. All other
   //!  parameters in this packet are ignored.
   //!
   StateGrp SurfaceState;

   //=========================================================
   //! Attached<br>
   //! This parameter specifies whether the surface should be
   //!  attached to an entity or a view.
   //!
   AttachStateGrp Attached;

   //=========================================================
   //! BillBoardState<br>
   //! This parameter specifies whether the surface should be
   //!  oriented toward the eyepoint (BillBoard).  If the surface
   //!  is a billboard and is attached to a entity, a normal from
   //!  the center of the surface will intersect the eyepoint.
   //!
   BillboardStateGrp BillboardState;

   //=========================================================
   //! Attached<br>
   //! If the surface is an Entity attached billboarded surface,
   //!  This parameter specifies the Perspective Growth state.
   //!
   PerspectiveGrowthStateGrp PerspectiveGrowth;

   //=========================================================
   //! EntityViewID<br>
   //! This parameter specifies the entity or view to which
   //!  this surface is attached.
   //!
   Cigi_uint16 EntityViewID;

   //=========================================================
   //! XLeft<br>
   //! For a surface attached to an entity, this parameter
   //!  specifies an X offset position from the entity’s
   //!  reference point to the center of the surface.
   //! For a surface attached to a view, this parameter
   //!  specifies the position of the surface’s leftmost boundary
   //!  on the view frustum near clipping plane as a half-angle
   //!  from the view frustum's eyepoint intersecting normal.
   //!
   float XLeft;

   //=========================================================
   //! YRight<br>
   //! For a surface attached to an entity, this parameter
   //!  specifies an Y offset position from the entity’s
   //!  reference point to the center of the surface.
   //! For a surface attached to a view, this parameter
   //!  specifies the position of the surface’s rightmost boundary
   //!  on the view frustum near clipping plane as a half-angle
   //!  from the view frustum's eyepoint intersecting normal.
   //!
   float YRight;

   //=========================================================
   //! ZTop<br>
   //! For a surface attached to an entity, this parameter
   //!  specifies an Z offset position from the entity’s
   //!  reference point to the center of the surface.
   //! For a surface attached to a view, this parameter
   //!  specifies the position of the surface’s topmost boundary
   //!  on the view frustum near clipping plane as a half-angle
   //!  from the view frustum's eyepoint intersecting normal.
   //!
   float ZTop;

   //=========================================================
   //! YawBottom<br>
   //! For a surface attached to an entity, this parameter
   //!  specifies the yaw orientation or a rotation about the
   //!  surface’s Z axis when the surface’s X axis is parallel
   //!  to the entity’s X axis.
   //! For a surface attached to a view, this parameter
   //!  specifies the position of the surface’s bottommost boundary
   //!  on the view frustum near clipping plane as a half-angle
   //!  from the view frustum's eyepoint intersecting normal.
   //!
   float YawBottom;

   //=========================================================
   //! Pitch<br>
   //! For a surface attached to an entity, this parameter
   //!  specifies the surface’s pitch with respect to the
   //!  surface’s reference plane after the yaw rotation has
   //!  been applied.
   //!
   float Pitch;

   //=========================================================
   //! Roll<br>
   //! For a surface attached to an entity, this parameter
   //!  specifies the surface’s roll with respect to the
   //!  surface’s reference plane after yaw and pitch rotations
   //!  have been applied.
   //!
   float Roll;

   //=========================================================
   //! Width<br>
   //! If the surface is attached to an entity, this parameter
   //!  specifies the width of the surface.
   //! If the surface is not a billboard or a billboard with
   //!  perspective growth as determined by the Billboard and
   //!  Perspective Growth Enable parameters of this data packet,
   //!  this parameter specifies the width of the surface in
   //!  meters and the occupied view space is affected by perspective.
   //! If the surface is a billboard with perspective growth disabled,
   //!  this parameter specifies the width as a view arc and the
   //!  occupied view space remains constant and unaffected by
   //!  perspective.
   //!
   float Width;

   //=========================================================
   //! Height<br>
   //! If the surface is attached to an entity, this parameter
   //!  specifies the height of the surface.
   //! If the surface is not a billboard or a billboard with
   //!  perspective growth as determined by the Billboard and
   //!  Perspective Growth Enable parameters of this data packet,
   //!  this parameter specifies the height of the surface in
   //!  meters and the occupied view space is affected by perspective.
   //! If the surface is a billboard with perspective growth disabled,
   //!  this parameter specifies the height as a view arc and the
   //!  occupied view space remains constant and unaffected by
   //!  perspective.
   //!
   float Height;

   //=========================================================
   //! LeftEdge<br>
   //! This parameter specifies the left most U coordinate
   //!  contained within the surface boundaries.
   //!
   float LeftEdge;

   //=========================================================
   //! LeftEdge<br>
   //! This parameter specifies the right most U coordinate
   //!  contained within the surface boundaries.
   //!
   float RightEdge;

   //=========================================================
   //! LeftEdge<br>
   //! This parameter specifies the top most V coordinate
   //!  contained within the surface boundaries.
   //!
   float TopEdge;

   //=========================================================
   //! LeftEdge<br>
   //! This parameter specifies the bottom most V coordinate
   //!  contained within the surface boundaries.
   //!
   float BottomEdge;




};



#endif   //  #if !defined(_CIGI_BASE_SYMBOL_SURFACE_DEF_INCLUDED_)

