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
 *  FILENAME:   CigiVersionJumpTable.h
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
 *  09/15/2003 James Durtschy                    CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Added the CIGI_SPEC modifier to the class declaration for exporting the 
 *  class in a Windows DLL.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the CIGI_RELEASED_MINOR_VERSION preprocessor definition.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added a forward class declaration for the CigiOutgoingMsg class.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the OutgoingMsg member variable to store a pointer to the outgoing 
 *  message.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the CigiMinorVersion member variable.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the ReaderCigiMinorVersion member variable to indicate the CIGI minor 
 *  version used by the reader and processing routines.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the SetOutgoingMsg accessor method.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the GetCigiMinorVersion accessor method.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the GetCigiTotalVersion method to get the CIGI version of the 
 *  external interface.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added an overloaded SetCigiVersion method to accept a CigiMinorVersionIn 
 *  parameter.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the existing SetCigiVersion method to use the new implementation
 *  with a default minor version number of 0.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added an overloaded SetReaderCigiVersion method to accept a 
 *  CigiMinorVersionIn parameter.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the existing SetReaderCigiVersion method to use the new 
 *  implementation with a default minor version number of 0.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the GetReaderCigiMinorVersion accessor method.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the GetReaderCigiTotalVersion method to get the reader's CIGI total 
 *  version.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the NextFrame method to get the current frame count.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the SetReceivedFrameID accessor method.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Added the GetReceivedFrameID accessor method.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.7.5
 */

#if !defined(_CIGI_VERSION_AND_JUMP_TABLE_INCLUDED_)
#define _CIGI_VERSION_AND_JUMP_TABLE_INCLUDED_

#define CIGI_MAX_VERSION 3
#define CIGI_RELEASED_MINOR_VERSION 2

#include "CigiBasePacket.h"
#include "CigiDefaultPacket.h"


class CigiOutgoingMsg;


//=========================================================
//! The class for Version control and Jump Table handling.
//!
class CIGI_SPEC CigiVersionJumpTable  
{
public:

   //=========================================================
   //! The enumeration for the Jump Table Type
   //!
   enum JumpTableType
   {
      Host,
      IG
   };

   //=========================================================
   //! The enumeration for the ID Convertion Table Type
   //!
   enum IDCvrtTblType
   {
      Reader=0,
      Writer=1
   };

   //=========================================================
   //! The enumeration or Table of Signal Types.
   //!
   enum SignalTblType
   {
      SigNone=0,
      SigIGCtrl=1,
      SigEntityCtrl=2,
      SigViewDef=3,
      SigViewCtrl=4,
      SigRateCtrl=5,
      SigSensorCtrl=6,
      SigTrajectory=7,
      SigWeatherCtrl=8,
      SigCollDetSegDef=9,
      SigLosSegReq=10,
      SigLosVectReq=11,
      SigHatHotReq=12,
      SigEnvCtrl=13,
      SigSpecEffDef=14,
      SigArtPartCtrl=15,
      SigCollDetVolDef=16,
      SigShortArtPartCtrl=17,
      SigConfClampEntityCtrl=18,
      SigMaritimeSurfaceCtrl=19,
      SigEnvRgnCtrl=20,
      SigTerrestrialSurfaceCtrl=21,
      SigMotionTrackCtrl=22,
      SigEarthModelDef=23,
      SigPostionReq=24,
      SigEnvCondReq=25,
      SigSOF=26,
      SigCollDetSegResp=27,
      SigSensorResp=28,
      SigSensorXResp=29,
      SigLosResp=30,
      SigLosXResp=31,
      SigHatHotResp=32,
      SigCollDetVolResp=33,
      SigPositionResp=34,
      SigWeatherCondResp=35,
      SigAerosolResp=36,
      SigMaritimeSurfaceResp=37,
      SigTerrestrialSurfaceResp=38,
      SigAnimationStop=39,
      SigEventNotification=40,
      SigHatReq=41,
      SigHotReq=42,
      SigHatHotXReq=43,
      SigHatResp=44,
      SigHotResp=45,
      SigHatHotXResp=46,
      SigWaveCtrl=47,
      SigIGMsg=48,
      SigAtmosCtrl=49,
      SigCelestialCtrl=50,
      SigCompCtrl=51,
      SigShortCompCtrl=52
   };



   //==> Management

   //=========================================================
   //! General Constructor
   //!
	CigiVersionJumpTable(JumpTableType JmpTblType);

   //=========================================================
   //! General Destructor
   //!
	virtual ~CigiVersionJumpTable();


   //=========================================================
   //! Setting the pointer to the outgoing message
   //! \param OutgoingMsgIn - The pointer to the outgoing message
   //!
	void SetOutgoingMsg(CigiOutgoingMsg *OutgoingMsgIn)
   {
      OutgoingMsg = OutgoingMsgIn;
   }



   //==> Processing Member functions

   //+> Cigi Version

   //=========================================================
   //! Sets the Cigi Version with bound checking control
   //!  This is for CIGI versions before 3.2
   //! \param CigiVersionIn - Sets the Cigi Version of
   //!   the external interface
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	inline int SetCigiVersion(const int CigiVersionIn, bool bndchk=true)
   {
      return(SetCigiVersion(CigiVersionIn,0,bndchk));
   }

   //=========================================================
   //! Sets the complete Cigi Version with bound checking control
   //! \param CigiVersionIn - Sets the Cigi Version of
   //!   the external interface
   //! \param CigiMinorVersionIn - Sets the Cigi Minor Version of
   //!   the external interface
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
	int SetCigiVersion(const int CigiVersionIn,
                      const int CigiMinorVersionIn,
                      bool bndchk=true);

   //=========================================================
   //! Gets the Cigi Version of the external interface.
   //! \return the Cigi Version of the external interface.
   //!
   int GetCigiVersion(void) const { return(CigiVersion); }

   //=========================================================
   //! Gets the Cigi Minor Version of the external interface.
   //! \return the Cigi Minor Version of the external interface.
   //!
   int GetCigiMinorVersion(void) const { return(CigiMinorVersion); }

   //=========================================================
   //! Gets the Cigi Version of the external interface.
   //! \param CigiVersionRef - A reference to a Cigi Version variable.
   //! \param CigiMinorVersionRef - A reference to a Cigi Minor
   //!   version variable.
   //!
   void GetCigiTotalVersion(int &CigiVersionRef, int &CigiMinorVersionRef)
   {
      CigiVersionRef = CigiVersion;
      CigiMinorVersionRef = CigiMinorVersion;
   }

   //+> Reader's Cigi Version

   //=========================================================
   //! Sets the Reader's Cigi Version with bound checking control
   //!  This is for CIGI versions before 3.2
   //! \param CigiVersionIn - Sets the Cigi Version of
   //!   the reading and processing routines.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   inline int SetReaderCigiVersion(const int CigiVersionIn, bool bndchk=true)
   {
      return(SetReaderCigiVersion(CigiVersionIn,0,bndchk));
   }

   //=========================================================
   //! Sets the Reader's Cigi Version with bound checking control
   //! \param CigiVersionIn - Sets the Cigi Version of
   //!   the reading and processing routines.
   //! \param CigiMinorVersionIn - Sets the Cigi Minor Version of
   //!   the reading and processing routines.
   //! \param bndchk - Enables (true) or disables (false) bounds checking
   //!
   //! \return This returns CIGI_SUCCESS or an error code 
   //!   defined in CigiErrorCodes.h
   //!
   int SetReaderCigiVersion(const int CigiVersionIn,
                            const int CigiMinorVersionIn,
                            bool bndchk=true);

   //=========================================================
   //! Gets the Reader's Cigi Version.
   //! \return the Cigi Version of the reader and processing routines.
   //!
   int GetReaderCigiVersion(void) const { return(ReaderCigiVersion); }

   //=========================================================
   //! Gets the Reader's Cigi Minor Version.
   //! \return the Cigi Minor Version of the reader and processing routines.
   //!
   int GetReaderCigiMinorVersion(void) const { return(ReaderCigiMinorVersion); }

   //=========================================================
   //! Gets the Reader's Cigi Total Version.
   //! \param CigiVersionRef - A reference to a Reader's Cigi Version variable.
   //! \param CigiMinorVersionRef - A reference to a Reader's Cigi Minor 
   //!   version variable.
   //!
   void GetReaderCigiTotalVersion(int &CigiVersionRef, int &CigiMinorVersionRef)
   {
      CigiVersionRef = ReaderCigiVersion;
      CigiMinorVersionRef = ReaderCigiMinorVersion;
   }

   //+> Frame Count

   //=========================================================
   //! Sets the current Frame Count
   //! \param FrameCntIn - Sets the frame count of the session.
   //!
   void SetFrameCnt(const int FrameCntIn) { FrameCnt = FrameCntIn; }

   //=========================================================
   //! Gets the current Frame Count.
   //! \return the current frame count of the session.
   //!
   int GetFrameCnt(void) const { return(FrameCnt); }

   //=========================================================
   //! Gets the current Frame Count.
   //! \return the current frame count of the session.
   //!
   Cigi_uint32 NextFrame(void)
   {
      FrameCnt++;
      return(FrameCnt);
   }

   //=========================================================
   //! Sets the last received Frame ID.
   //! \param FrameCntIn - Sets the last received frame id.
   //!
   void SetReceivedFrameID(const Cigi_uint32 ReceivedFrameIDIn)
   {
      ReceivedFrameID = ReceivedFrameIDIn;
   }

   //=========================================================
   //! Gets the last received Frame ID.
   //! \return the last received Frame ID.
   //!
   Cigi_uint32 GetReceivedFrameID(void) const { return(ReceivedFrameID); }

   //+> Synchronous Operation

   //=========================================================
   //! Sets the synchronous/asynchronous mode of operation.<br>
   //!   Synchronous operation is when the host responds directly
   //!   to a SOF from the IG.<br>
   //!   Asynchronous operation is when the host sends its
   //!   messages at its own frame timing without any regard
   //!   for the SOF message from the IG.
   //! \param Sync - Sets the synchronous/asynchronous mode 
   //!   of operation.<br>
   //!   true - Synchronous operation.
   //!   false - Asynchronous operation.
   //!
   void SetSynchronous(const bool Sync) { Synchronous = Sync; }

   //=========================================================
   //! Gets the synchronous/asynchronous mode of operation.
   //! \return the synchronous/asynchronous mode of operation.
   //!   true - Synchronous operation.
   //!   false - Asynchronous operation.
   //!
   bool IsSynchronous(void) const { return(Synchronous); }


   //+> Misc. Information

   //=========================================================
   //! Gets the Jump Table Type.
   //! \return the Jump Table Type. ( Host or IG )
   //!
   JumpTableType GetJmpTbltype(void) const { return(JTblType); }

   //=========================================================
   //! Gets the size of the SOF packet.
   //! \return the size of the SOF packet in bytes.
   //!
   int GetSOFSize(void) const { return(SOFSize); }

   //=========================================================
   //! Gets the size of the IG Ctrl packet.
   //! \return the size of the IG Ctrl packet in bytes.
   //!
   int GetIGCtrlSize(void) const { return(IGCtrlSize); }

   //=========================================================
   //! Gets the position of the frame counter in the current message.
   //! \return the position of the frame counter in the 
   //!   current message/buffer as a word index.
   //!
   int GetOutFrameBufPos(void) const { return(OutFrameBufPos); }

   //=========================================================
   //! Gets the handling objects for Celestial and Atmosphere packets.
   //! \param CelestHnd - Pointer to a pointer for the Celestial handler.
   //! \param AtmosHnd - Pointer to a pointer for the Atmosphere handler.
   //!
   //! \return Valid data flag.
   //!
   bool GetDEnvPcktHndlr(CigiBasePacket ** CelestHnd, CigiBasePacket ** AtmosHnd);


   //+> Packet ID Conversion

   //=========================================================
   //! Converts the supplied writer's packet id to the packet id
   //!   of the current external interface due to Cigi version
   //!   differences.
   //! \param PacketID - The writer's packet id
   //! \param Version - The writer's CIGI version
   //!
   //! \return the packet id of the current external interface.
   //!
   Cigi_uint8 GetCnvtID(const Cigi_uint8 PacketID, const int Version)
   {
      if((Version > 0)&&(Version < 4))
         return(PacketIDMap[Version][PacketID]);
      else
         return(0);
   }

   //=========================================================
   //! Converts the current external interface packet id to 
   //!   the packet id of the reader due to Cigi version
   //!   differences.
   //! \param PacketID - The current external interface packet id
   //!
   //! \return the reader's packet id.
   //!
   Cigi_uint8 GetCnvtToReaderID(const Cigi_uint8 PacketID)
   {
         return(PacketIDMap[0][PacketID]);
   }


   //+> Tables

   //=========================================================
   //! Gets the send valid flag for the specified packet id.
   //! \param SndPcktID - The writer's packet id
   //!
   //! \return the a flag specifying whether the specified
   //!   packet is valid to send.
   //!
   bool GetSndVld(const Cigi_uint8 SndPcktID) const { return(VldSnd[SndPcktID]); }

   //=========================================================
   //! Gets the receive valid flag for the specified packet id.
   //! \param RcvPcktID - The reader's packet id
   //!
   //! \return the a flag specifying whether the specified
   //!   packet is valid to receive.
   //!
   bool GetRcvVld(const Cigi_uint8 RcvPcktID) const { return(VldRcv[RcvPcktID]); }

   //=========================================================
   //! Gets the handling object for a specific packet id.
   //! \param PacketID - The packet id of the packet to be processed
   //!
   //! \return An pointer to the handling object for the specified packet.
   //!
   CigiBasePacket * GetPcktHndlr(const Cigi_uint8 PacketID) const { return(JmpTbl[PacketID]); }

   //=========================================================
   //! Gets the signal type for a specific packet id.
   //! \param PacketID - The packet id of the packet to be processed
   //!
   //! \return An pointer to the handling object for the specified packet.
   //!
   SignalTblType GetSignalType(const Cigi_uint8 PacketID) const { return(SignalMap[PacketID]); }

   //=========================================================
   //! Gets the Process type for a specific packet id.
   //! \param PacketID - The packet id of the packet to be processed
   //!
   //! \return An pointer to the handling object for the specified packet.
   //!
   int GetProcType(const Cigi_uint8 PacketID) const { return(ProcType[PacketID]); }


   //+> Registering

   //=========================================================
   //! Register a user packet for use.
   //! \param Packet - A pointer to the packet manager object
   //! \param PacketID - The packet id
   //! \param HostSend - A flag specifying whether the host
   //!   can send this packet.
   //! \param IGSend - A flag specifying whether the IG
   //!   can send this packet.
   //!
   //! \return the a flag specifying whether the specified
   //!   packet is valid to send.
   //!
	int RegisterUserPacket(CigiBasePacket *Packet, Cigi_uint8 PacketID, bool HostSend, bool IGSend);


protected:

   //==> Member variables

   //=========================================================
   //! Cigi Version used by the external interface.
   //!
	int CigiVersion;

   //=========================================================
   //! Cigi Minor Version used by the external interface.
   //!
	int CigiMinorVersion;

   //=========================================================
   //! Cigi Version used by the reader and processing routines.
   //!
   int ReaderCigiVersion;

   //=========================================================
   //! Cigi Minor Version used by the reader and processing routines.
   //!
   int ReaderCigiMinorVersion;

   //=========================================================
   //! The Jump Table type - Host or IG
   //!
   JumpTableType JTblType;

   //=========================================================
   //! A default packet manager
   //!
   CigiDefaultPacket DefaultPacket;

   //=========================================================
   //! The Jump Table for packet managers
   //!
   CigiBasePacket *JmpTbl[256];

   //=========================================================
   //! The Packet ID Mapping Table<br>
   //! The first index is:<br>
   //!   0     => reader conversion subtable
   //!   1 - 3 => the convert from Cigi version.<br>
   //! The second index is the convert from packet id.
   //!
   Cigi_uint8 TotalPacketIDMap[4][4][256];

   //=========================================================
   //! The Packet ID Mapping Table
   //! The first index is the convert from Cigi version.<br>
   //! The second index is the convert to Cigi version.<br>
   //! The third index is the convert from packet id.
   //!
   Cigi_uint8 PacketIDMap[4][256];


   //=========================================================
   //! A pointer to the outgoing message object
   //!
   CigiOutgoingMsg *OutgoingMsg;

   //=========================================================
   //! The Packet valid to send Table
   //!
   bool VldSnd[256];

   //=========================================================
   //! The Packet valid to receive Table
   //!
   bool VldRcv[256];

   //=========================================================
   //! The Packet to signal handler mapping Table
   //!
   SignalTblType SignalMap[256];

   //=========================================================
   //! The Process type table
   //!
   int ProcType[256];

   //=========================================================
   //! The Start Of Frame packet size
   //!
   int SOFSize;

   //=========================================================
   //! The IG Control packet size
   //!
   int IGCtrlSize;

   //=========================================================
   //! The position of the frame counter in the buffer as
   //!   a word index.
   //!
   int OutFrameBufPos;

   //=========================================================
   //! The Current frame counter
   //!
   int FrameCnt;

   //=========================================================
   //! The frame ID last received
   //!
   Cigi_uint32 ReceivedFrameID;

   //=========================================================
   //! The synchronous operation flag
   //!
   bool Synchronous;


   //==> Protected Member Functions


   //=========================================================
   //! Clears all external interface tables
   //!
	void ClearTbls(void);

   //=========================================================
   //! Clears all Reader tables
   //!
   void ClearReaderTbls(void);

   //=========================================================
   //! Set all external interface jump tables for V1 output
   //!
	void SetJmpTblV1(void);

   //=========================================================
   //! Set all external interface jump tables for V2 output
   //!
	void SetJmpTblV2(void);

   //=========================================================
   //! Set all external interface jump tables for V3 output
   //!
	void SetJmpTblV3(const int CigiMinorVersionIn);

   //=========================================================
   //! Initialize all Packet ID map tables
   //!
	void InitPacketIDMaps(void);

   //=========================================================
   //! Set all external interface map tables for V1 output
   //!
	void SetPacketIDMapsV1(void);

   //=========================================================
   //! Set all external interface map tables for V2 output
   //!
	void SetPacketIDMapsV2(void);

   //=========================================================
   //! Set all external interface map tables for V3 output
   //!
	void SetPacketIDMapsV3(void);

   //=========================================================
   //! Set reader map tables
   //! \param from - converting from external interface Cigi version
   //! \param to - converting to reader's Cigi version
   //!
	void SetReaderPacketIDMaps(int from, int to);

   //=========================================================
   //! Set all external interface valid tables for V1 output
   //!
	void SetVldTblsV1(void);

   //=========================================================
   //! Set all external interface valid tables for V2 output
   //!
	void SetVldTblsV2(void);

   //=========================================================
   //! Set all external interface valid tables for V3 output
   //!
	void SetVldTblsV3(void);

   //=========================================================
   //! Set all reader signal tables for V1 output
   //!
   void SetSignalMapV1(void);

   //=========================================================
   //! Set all reader signal tables for V2 output
   //!
   void SetSignalMapV2(void);

   //=========================================================
   //! Set all reader signal tables for V3 output
   //!
   void SetSignalMapV3(void);

   //=========================================================
   //! Set all ProcType tables for V1 output
   //!
   void SetProcTypeV1(void);

   //=========================================================
   //! Set all ProcType tables for V2 output
   //!
   void SetProcTypeV2(void);

   //=========================================================
   //! Set all ProcType tables for V3 output
   //!
   void SetProcTypeV3(void);

};

#endif // !defined(_CIGI_VERSION_AND_JUMP_TABLE_INCLUDED_)
