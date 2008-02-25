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
 *  FILENAME:   CigiBaseSymbolCtrl.h
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

#if !defined(_CIGI_BASE_SYMBOL_CTRL_INCLUDED_)
#define _CIGI_BASE_SYMBOL_CTRL_INCLUDED_


#include "CigiBasePacket.h"

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_SYMBOL_CONTROL_PACKET_ID_V3_3 241  // FIXME
#define CIGI_SYMBOL_CONTROL_PACKET_SIZE_V3_3 40


class CigiSymbolCtrlV3_3;


//=========================================================
//! The base class for all packets.
//!
class CIGI_SPEC CigiBaseSymbolCtrl :
   public CigiBasePacket
{

   friend class CigiSymbolCtrlV3_3;

public:

   //=========================================================
   //! The enumeration for the Symbol State Group
   //!
   enum SymbolStateGrp
   {
      Hidden=0,
      Visible=1,
      Destroyed=2
   };

   //=========================================================
   //! The enumeration for the FIXME
   //!
   enum AttachStateGrp
   {
      Detach=0,
      Attach=1
   };

   //=========================================================
   //! The enumeration for the Flash Control flag
   //!
   enum FlashCtrlGrp
   {
      Continue=0,
      Reset=1
   };

   //=========================================================
   //! The enumeration for the Inherit Color flag
   //!
   enum InheritColorGrp
   {
      NotInherit=0,
      Inherit=1
   };



   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiBaseSymbolCtrl(void);

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiBaseSymbolCtrl(void);


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

   //+> SymbolID

   //=========================================================
   //! Sets the SymbolID with bound checking control
   //! \param SymbolIDIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetSymbolID(const Cigi_uint16 SymbolIDIn, bool bndchk=true)
   {
      SymbolID = SymbolIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the SymbolID with bound checking control
   //! \return SymbolID
   //!
   Cigi_uint16 GetSymbolID(void) const { return(SymbolID); }
   

   //+> SymbolState

   //=========================================================
   //! Sets the SymbolState with bound checking control
   //! \param SymbolStateIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetSymbolState(const SymbolStateGrp SymbolStateIn, bool bndchk=true);

   //=========================================================
   //! Gets the SymbolState with bound checking control
   //! \return SymbolState
   //!
   SymbolStateGrp GetSymbolState(void) const { return(SymbolState); }
   

   //+> AttachState

   //=========================================================
   //! Sets the AttachState with bound checking control
   //! \param AttachStateIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAttachState(const AttachStateGrp AttachStateIn, bool bndchk=true);

   //=========================================================
   //! Gets the AttachState with bound checking control
   //! \return AttachState
   //!
   AttachStateGrp GetAttachState(void) const { return(AttachState); }
   

   //+> FlashCtrl

   //=========================================================
   //! Sets the FlashCtrl with bound checking control
   //! \param FlashCtrlIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFlashCtrl(const FlashCtrlGrp FlashCtrlIn, bool bndchk=true);

   //=========================================================
   //! Gets the FlashCtrl with bound checking control
   //! \return FlashCtrl
   //!
   FlashCtrlGrp GetFlashCtrl(void) const { return(FlashCtrl); }
   

   //+> InheritColor

   //=========================================================
   //! Sets the InheritColor with bound checking control
   //! \param InheritColorIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetInheritColor(const InheritColorGrp InheritColorIn, bool bndchk=true);

   //=========================================================
   //! Gets the InheritColor with bound checking control
   //! \return InheritColor
   //!
   InheritColorGrp GetInheritColor(void) const { return(InheritColor); }
   

   //+> ParentSymbolID

   //=========================================================
   //! Sets the ParentSymbolID with bound checking control
   //! \param ParentSymbolIDIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetParentSymbolID(const Cigi_uint16 ParentSymbolIDIn, bool bndchk=true)
   {
      ParentSymbolID = ParentSymbolIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the ParentSymbolID with bound checking control
   //! \return ParentSymbolID
   //!
   Cigi_uint16 GetParentSymbolID(void) const { return(ParentSymbolID); }
   

   //+> SurfaceID

   //=========================================================
   //! Sets the SurfaceID with bound checking control
   //! \param SurfaceIDIn - FIXME
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
   //! Gets the SurfaceID with bound checking control
   //! \return SurfaceID
   //!
   Cigi_uint16 GetSurfaceID(void) const { return(SurfaceID); }
   

   //+> Layer

   //=========================================================
   //! Sets the Layer with bound checking control
   //! \param LayerIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetLayer(const Cigi_uint8 LayerIn, bool bndchk=true)
   {
      Layer = LayerIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Layer with bound checking control
   //! \return Layer
   //!
   Cigi_uint8 GetLayer(void) const { return(Layer); }
   

   //+> FlashDutyCycle

   //=========================================================
   //! Sets the FlashDutyCycle with bound checking control
   //! \param FlashDutyCycleIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFlashDutyCycle(const Cigi_uint8 FlashDutyCycleIn, bool bndchk=true);

   //=========================================================
   //! Gets the FlashDutyCycle with bound checking control
   //! \return FlashDutyCycle
   //!
   Cigi_uint8 GetFlashDutyCycle(void) const { return(FlashDutyCycle); }
   

   //+> FlashPeriod

   //=========================================================
   //! Sets the FlashPeriod with bound checking control
   //! \param FlashPeriodIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFlashPeriod(const float FlashPeriodIn, bool bndchk=true)
   {
      FlashPeriod = FlashPeriodIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the FlashPeriod with bound checking control
   //! \return FlashPeriod
   //!
   float GetFlashPeriod(void) const { return(FlashPeriod); }
   

   //+> UPosition

   //=========================================================
   //! Sets the UPosition with bound checking control
   //! \param UPositionIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetUPosition(const float UPositionIn, bool bndchk=true)
   {
      UPosition = UPositionIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the UPosition with bound checking control
   //! \return UPosition
   //!
   float GetUPosition(void) const { return(UPosition); }
   

   //+> VPosition

   //=========================================================
   //! Sets the VPosition with bound checking control
   //! \param VPositionIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetVPosition(const float VPositionIn, bool bndchk=true)
   {
      VPosition = VPositionIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the VPosition with bound checking control
   //! \return VPosition
   //!
   float GetVPosition(void) const { return(VPosition); }
   

   //+> Rotation

   //=========================================================
   //! Sets the Rotation with bound checking control
   //! \param RotationIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetRotation(const float RotationIn, bool bndchk=true)
   {
      Rotation = RotationIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Rotation with bound checking control
   //! \return Rotation
   //!
   float GetRotation(void) const { return(Rotation); }


   //+> Color

   //=========================================================
   //! Sets the color with bound checking control
   //! \param RedIn - FIXME
   //! \param GreenIn - FIXME
   //! \param BlueIn - FIXME
   //! \param AlphaIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetColor(const Cigi_uint8 RedIn,
                const Cigi_uint8 GreenIn,
                const Cigi_uint8 BlueIn,
                const Cigi_uint8 AlphaIn,
                bool bndchk=true)
   {
      Red = RedIn;
      Green = GreenIn;
      Blue = BlueIn;
      Alpha = AlphaIn;

      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the ParentSymbolID with bound checking control
   //! \param RedValue - The reference to the variable in which
   //!    the value of the red component will be placed
   //! \param GreenValue - The reference to the variable in which
   //!    the value of the Green component will be placed
   //! \param BlueValue - The reference to the variable in which
   //!    the value of the Blue component will be placed
   //! \param AlphaValue - The reference to the variable in which
   //!    the value of the Alpha component will be placed
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int GetColorDatum(Cigi_uint8 &RedValue,
                     Cigi_uint8 &GreenValue,
                     Cigi_uint8 &BlueValue,
                     Cigi_uint8 &AlphaValue,
                     bool bndchk=true)
   {
      RedValue = Red;
      GreenValue = Green;
      BlueValue = Blue;
      AlphaValue = Alpha;

      return(CIGI_SUCCESS);
   }


   //+> Red

   //=========================================================
   //! Sets the Red with bound checking control
   //! \param RedIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetRed(const Cigi_uint8 RedIn, bool bndchk=true)
   {
      Red = RedIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Red with bound checking control
   //! \return Red
   //!
   Cigi_uint8 GetRed(void) const { return(Red); }
   

   //+> Green

   //=========================================================
   //! Sets the Green with bound checking control
   //! \param GreenIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetGreen(const Cigi_uint8 GreenIn, bool bndchk=true)
   {
      Green = GreenIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Green with bound checking control
   //! \return Green
   //!
   Cigi_uint8 GetGreen(void) const { return(Green); }
   

   //+> Blue

   //=========================================================
   //! Sets the Blue with bound checking control
   //! \param BlueIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetBlue(const Cigi_uint8 BlueIn, bool bndchk=true)
   {
      Blue = BlueIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Blue with bound checking control
   //! \return Blue
   //!
   Cigi_uint8 GetBlue(void) const { return(Blue); }
   

   //+> Alpha

   //=========================================================
   //! Sets the Alpha with bound checking control
   //! \param AlphaIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAlpha(const Cigi_uint8 AlphaIn, bool bndchk=true)
   {
      Alpha = AlphaIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the Alpha with bound checking control
   //! \return Alpha
   //!
   Cigi_uint8 GetAlpha(void) const { return(Alpha); }
   

   //+> ScaleU

   //=========================================================
   //! Sets the ScaleU with bound checking control
   //! \param ScaleUIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetScaleU(const float ScaleUIn, bool bndchk=true)
   {
      ScaleU = ScaleUIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the ScaleU with bound checking control
   //! \return ScaleU
   //!
   float GetScaleU(void) const { return(ScaleU); }
   

   //+> ScaleV

   //=========================================================
   //! Sets the ScaleV with bound checking control
   //! \param ScaleVIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetScaleV(const float ScaleVIn, bool bndchk=true)
   {
      ScaleV = ScaleVIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the ScaleV with bound checking control
   //! \return ScaleV
   //!
   float GetScaleV(void) const { return(ScaleV); }



protected:

   //==> Member variables

   //=========================================================
   //! SymbolID<br>
   //! FIXME
   //!
   Cigi_uint16 SymbolID;

   //=========================================================
   //! SymbolState<br>
   //! FIXME
   //!
   SymbolStateGrp SymbolState;

   //=========================================================
   //! AttachState<br>
   //! FIXME
   //!
   AttachStateGrp AttachState;

   //=========================================================
   //! FlashCtrl<br>
   //! FIXME
   //!
   FlashCtrlGrp FlashCtrl;

   //=========================================================
   //! InheritColor<br>
   //! FIXME
   //!
   InheritColorGrp InheritColor;

   //=========================================================
   //! ParentSymbolID<br>
   //! FIXME
   //!
   Cigi_uint16 ParentSymbolID;

   //=========================================================
   //! SurfaceID<br>
   //! FIXME
   //!
   Cigi_uint16 SurfaceID;

   //=========================================================
   //! Layer<br>
   //! FIXME
   //!
   Cigi_uint8 Layer;

   //=========================================================
   //! FlashDutyCycle<br>
   //! FIXME
   //!
   Cigi_uint8 FlashDutyCycle;

   //=========================================================
   //! FlashPeriod<br>
   //! FIXME
   //!
   float FlashPeriod;

   //=========================================================
   //! UPosition<br>
   //! FIXME
   //!
   float UPosition;

   //=========================================================
   //! VPosition<br>
   //! FIXME
   //!
   float VPosition;

   //=========================================================
   //! Rotation<br>
   //! FIXME
   //!
   float Rotation;

   //=========================================================
   //! Red<br>
   //! FIXME
   //!
   Cigi_uint8 Red;

   //=========================================================
   //! Green<br>
   //! FIXME
   //!
   Cigi_uint8 Green;

   //=========================================================
   //! Blue<br>
   //! FIXME
   //!
   Cigi_uint8 Blue;

   //=========================================================
   //! Alpha<br>
   //! FIXME
   //!
   Cigi_uint8 Alpha;

   //=========================================================
   //! ScaleU<br>
   //! FIXME
   //!
   float ScaleU;

   //=========================================================
   //! ScaleV<br>
   //! FIXME
   //!
   float ScaleV;




};



#endif   //  #if !defined(_CIGI_BASE_SYMBOL_CTRL_INCLUDED_)

