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
 *  FILENAME:   CigiBaseSymbolTextDef.h
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

#if !defined(_CIGI_BASE_SYMBOL_TEXT_DEF_INCLUDED_)
#define _CIGI_BASE_SYMBOL_TEXT_DEF_INCLUDED_


#include "CigiBaseVariableSizePckt.h"

#include <string>

// ====================================================================
// preprocessor definitions
// ====================================================================

#define CIGI_SYMBOL_TEXT_DEFINITION_PACKET_ID_V3_3 243  // FIXME
#define CIGI_SYMBOL_TEXT_DEFINITION_PACKET_SIZE_V3_3 12


class CigiSymbolTextDefV3_3;


//=========================================================
//! The base class for all packets.
//!
class CIGI_SPEC CigiBaseSymbolTextDef :
   public CigiBaseVariableSizePckt
{

   friend class CigiSymbolTextDefV3_3;

public:


   //=========================================================
   //! The enumeration for the CigiBaseSymbolTextDef
   //!   Datum type Group
   //!
   enum AlignmentGrp
   {
      TopLeft=0,
      TopCenter=1,
      TopRight=2,
      CenterLeft=3,
      Center=4,
      CenterRight=5,
      BottomLeft=6,
      BottomCenter=7,
      BottomRight=8,
   };

   //=========================================================
   //! The enumeration for the CigiBaseSymbolTextDef
   //!   Datum type Group
   //!
   enum OrientationGrp
   {
      LeftToRight=0,
      TopToBottom=1,
      RightToLeft=2,
      BottomToTop=3,
   };


   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiBaseSymbolTextDef(void);

   //=========================================================
   //! General Destructor
   //!
   virtual ~CigiBaseSymbolTextDef(void);

   //=========================================================
   //! Copy Constructor
   //!
   CigiBaseSymbolTextDef(const CigiBaseSymbolTextDef &BaseIn);

   //=========================================================
   //! Assignment operator
   //!
   CigiBaseSymbolTextDef & operator=(const CigiBaseSymbolTextDef &BaseIn);


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
   //! A pure virtual function to determine the size that the
   //!  packet will take up when packed.
   //! This function is not implemented in this class.
   //! \param refPacket - A pointer to the current pack point.
   //!
   //! \return The size that the packet will take up when packed
   //!
	virtual int GetTruePacketSize(CigiBaseVariableSizePckt &refPacket)
   { return(PacketSize + refPacket.GetVariableDataSize()); }

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
   

   //+> Alignment

   //=========================================================
   //! Sets the Alignment with bound checking control
   //! \param AlignmentIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetAlignment(const AlignmentGrp AlignmentIn, bool bndchk=true);

   //=========================================================
   //! Gets the Alignment with bound checking control
   //! \return Alignment
   //!
   AlignmentGrp GetAlignment(void) const { return(Alignment); }


   //+> Orientation

   //=========================================================
   //! Sets the Orientation with bound checking control
   //! \param OrientationIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetOrientation(const OrientationGrp OrientationIn, bool bndchk=true);

   //=========================================================
   //! Gets the Orientation with bound checking control
   //! \return Orientation
   //!
   OrientationGrp GetOrientation(void) const { return(Orientation); }


   //+> FontID

   //=========================================================
   //! Sets the FontID with bound checking control
   //! \param FontIDIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFontID(const Cigi_uint8 FontIDIn, bool bndchk=true)
   {
      FontID = FontIDIn;
      return(CIGI_SUCCESS);
   }

   //=========================================================
   //! Gets the FontID with bound checking control
   //! \return FontID
   //!
   Cigi_uint8 GetFontID(void) const { return(FontID); }


   //+> FontSize

   //=========================================================
   //! Sets the FontSize with bound checking control
   //! \param FontSizeIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetFontSize(const float FontSizeIn, bool bndchk=true);

   //=========================================================
   //! Gets the FontSize with bound checking control
   //! \return FontSize
   //!
   float GetFontSize(void) const { return(FontSize); }


   //+> Text

   //=========================================================
   //! Sets the Text with bound checking control
   //! \param TextIn - FIXME
   //! \param bndchk - Enables (true) or disables (false) bounds checking.
   //!
   //! \return This returns CIGI_SUCCESS or an error code
   //!   defined in CigiErrorCodes.h
   int SetText(const std::string &TextIn, bool bndchk=true);

   //=========================================================
   //! Gets the TextSize with bound checking control
   //! \return TextSize
   //!
   int GetTextSize(void) const { return(VariableDataSize); }

   //=========================================================
   //! Gets the Text
   //! \return The current symbology text
   const std::string & GetText(void) { return(Text); }



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
   AlignmentGrp Alignment;

   //=========================================================
   //! AttachState<br>
   //! FIXME
   //!
   OrientationGrp Orientation;

   //=========================================================
   //! Datum1Type<br>
   //! FIXME
   //!
   Cigi_uint8 FontID;

   //=========================================================
   //! Datum1Type<br>
   //! FIXME
   //!
   float FontSize;

   //=========================================================
   //! Text<br>
   //! The symbol text
   //!
   std::string Text;

   //=========================================================
   //! MaxCharCnt<br>
   //! The maximum number of bytes not including NULLs
   //!
   const static int MaxCharCnt = 235;

};



#endif   //  #if !defined(_CIGI_BASE_SYMBOL_TEXT_DEF_INCLUDED_)

