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
 *  FILENAME:   CigiIncomingMsg.cpp
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
 *  
 *  04/06/2005 Greg Basler                       Version 1.5.2
 *  Fixed the GetFirstPacket function to use the correct start of frame and IG 
 *  control opcode values.
 *  
 *  07/05/2005 Greg Basler                       Version 1.5.4
 *  Modified the ProcessIncomingMsg function to check for and throw a buffer 
 *  overrun exception when the actual data exists beyond the end of the 
 *  incoming buffer.
 *  
 *  08/11/2005 Greg Basler                       Version 1.5.5
 *  Modified the GetFirstPacket method to get the pointer to the correct 
 *  SOF and IG Control handling objects.
 *  
 *  10/06/2005 Greg Basler                       Version 1.5.6
 *  Fixed the ProcessIncomingMsg and GetFirstPacket methods to correctly 
 *  handle frame counter synchronization.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the ProcessIncomingMsg method to use CIGI minor version numbers.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the GetFirstPacket and GetNextPacket methods to use CIGI minor 
 *  version numbers.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *  
 *  07/14/2006 Greg Basler                       Version 1.7.2
 *  Changed the constructor and GetFirstPacket so that the IterationVersion
 *  is properly initialized and set.  Changed ProcessIncomingMsg,
 *  GetFirstPacket, and GetNextPacket to set the Cigi Version with the
 *  correct version numbers.
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.7.5
 */

#define _EXPORT_CCL_

#include "CigiIncomingMsg.h"
#include "CigiExceptions.h"
#include "CigiBaseSOF.h"
#include "CigiBaseIGCtrl.h"

#include "CigiEnvCtrlV1.h"
#include "CigiEnvCtrlV2.h"
#include "CigiCelestialCtrl.h"
#include "CigiAtmosCtrl.h"


// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiIncomingMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiIncomingMsg::CigiIncomingMsg()
{

   Iteration = false;

   for(int ndx=0;ndx<257;ndx++)
   {
      CallBackList[ndx] = NULL;
      EventList[ndx] = NULL;
      SignalList = NULL;
   }

   Swap = false;

   MostMatureCigiVersionReceived = 0;

   IterationVersion = 0;

}

// ================================================
// ~CigiIncomingMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiIncomingMsg::~CigiIncomingMsg()
{
   CigiEventList *TEvent;

   CigiEventList *CrntSObj = SignalList;

   while(CrntSObj != NULL)
   {
      TEvent = CrntSObj->GetNextEvent();
      delete CrntSObj;
      CrntSObj = TEvent;
   }

   for(int ndx=0;ndx<257;ndx++)
   {
      CigiEventList *CrntEObj = EventList[ndx];
      CigiEventList *CrntCBObj = CallBackList[ndx];

      while(CrntEObj != NULL)
      {
         TEvent = CrntEObj->GetNextEvent();
         delete CrntEObj;
         CrntEObj = TEvent;
      }

      while(CrntCBObj != NULL)
      {
         TEvent = CrntCBObj->GetNextEvent();
         delete CrntCBObj;
         CrntCBObj = TEvent;
      }

   }

}


// ====================================================================
// Processing
// ====================================================================

// ================================================
// ProcessIncomingMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIncomingMsg::ProcessIncomingMsg(Cigi_uint8 *Buff, int Size)
{
   Cigi_uint8 PacketID;
   Cigi_uint8 ReadPacketID;
   Cigi_uint8 PacketSize;
   CigiBasePacket *Packet;
   Cigi_uint8 Version;
   Cigi_uint8 MinorVer;
   int tMVer;
   CigiBaseSOF *SOF;
   CigiBaseIGCtrl *IGCtrl;
   bool ValidPacket = false;
   CigiEventList *CrntObj;
   int ReaderCigiVersion;
   int ProcType;

   Swap = false;

   MsgSize = Size;

   MsgStart = CrntPacket = Buff;
   ReadBufferPos = 0;

   if(!Iteration)
   {

      PacketID = *Buff;
      PacketSize = *(Buff+1);

      if(VJmp->GetJmpTbltype() == CigiVersionJumpTable::Host)
      {
         if(PacketID == 101) // CIGI_START_OF_FRAME_OPCODE)
         {
            Version = (int)(*(Buff+2));

            if(Version < 3)
               MinorVer = 0;
            else
               MinorVer = (int)((*(Buff+5) >> 4) & 0x0f);

         }
         else
         {

#ifndef CIGI_NO_EXCEPT
            throw CigiMissingStartOfFrameException();
#endif
            return(CIGI_ERROR_MISSING_SOF_PACKET);

         }
      }
      else
      {
         if(PacketID == 1) // CIGI_IG_CONTROL_OPCODE)
         {
            Version = (int)(*(Buff+2));

            if(Version < 3)
               MinorVer = 0;
            else
               MinorVer = (int)((*(Buff+4) >> 4) & 0x0f);

         }
         else
         {

#ifndef CIGI_NO_EXCEPT
            throw CigiMissingIgControlException();
#endif
            return(CIGI_ERROR_MISSING_IG_CONTROL_PACKET);

         }
      }


      // If there is an unrecognized version ...
      // Set the version to 3 and do the best
      //   compatibility conversion possible.
      tMVer = ((Version << 8) & 0x0000ff00) | 
               (MinorVer & 0x000000ff);

      if((Version != VJmp->GetCigiVersion()) ||
         (MinorVer != VJmp->GetCigiMinorVersion()))
      {

#ifndef CIGI_NO_EXCEPT
         try
         {
            VJmp->SetCigiVersion(Version,MinorVer);
         }
         catch(CigiValueOutOfRangeException)
         {
            VJmp->SetCigiVersion(3,2);
            tMVer = 0;
         }
#else
         if(VJmp->SetCigiVersion(Version,MinorVer) != CIGI_SUCCESS)
         {
            VJmp->SetCigiVersion(3,2);
            tMVer = 0;
         }
#endif
      }


      ValidPacket = false;
      if(PacketID == 101)
      {
         SOF = (CigiBaseSOF *)VJmp->GetPcktHndlr(101);
         SOF->Unpack(CrntPacket,false,NULL);
         Swap = SOF->GetSwap();
         Packet = (CigiBasePacket *)SOF;
         ValidPacket = true;
         VJmp->SetReceivedFrameID(SOF->GetFrameCntr());
         if((VJmp->IsSynchronous()) &&
            ((VJmp->GetCigiVersion() < 3) ||
            ((VJmp->GetCigiVersion() == 3) && (VJmp->GetCigiMinorVersion() < 2))))
            VJmp->SetFrameCnt(SOF->GetFrameCntr());
      }
      else
      {
         IGCtrl = (CigiBaseIGCtrl *)VJmp->GetPcktHndlr(1);
         IGCtrl->Unpack(CrntPacket,false,NULL);
         Swap = IGCtrl->GetSwap();
         Packet = (CigiBasePacket *)IGCtrl;
         ValidPacket = true;
         VJmp->SetReceivedFrameID(IGCtrl->GetFrameCntr());
      }

      ReadBufferPos = (int)PacketSize;
      CrntPacket += (int)PacketSize;

      ReaderCigiVersion = VJmp->GetReaderCigiVersion();
      ReadPacketID = VJmp->GetCnvtToReaderID(PacketID);

      if(ValidPacket)
      {

#ifndef CIGI_NO_SIGNAL_PROCESSING
         SignalJump(ReadPacketID, Packet);
#endif
#ifndef CIGI_NO_EVENT_PROCESSING
         // Event processing
         CrntObj = EventList[ReadPacketID];

         while(CrntObj != NULL)
         {
            (CrntObj->GetCigiEvent())->OnPacketReceived(Packet);

            CrntObj = CrntObj->GetNextEvent();
         }
#endif
#ifndef CIGI_NO_CALLBACK
         // Callback processing
         CrntObj = CallBackList[ReadPacketID];

         while(CrntObj != NULL)
         {
            (CrntObj->GetCigiCallBack())(Packet);

            CrntObj = CrntObj->GetNextEvent();
         }

      }
#endif


      while(ReadBufferPos < Size)
      {

         PacketID = *CrntPacket;
         PacketSize = *(CrntPacket+1);

         // Check to determine if the Last packet in the buffer has truncated.
         // If so, the message was truncated by the communications protocol.
         // Also, the last (truncated) packet cannot be processed.
         if((ReadBufferPos + PacketSize) > Size)
         {
#ifndef CIGI_NO_EXCEPT
            throw CigiBufferOverrunException();
#endif
            return(CIGI_ERROR_BUFFER_OVERRUN);

            break;
         }


         Packet = VJmp->GetPcktHndlr(PacketID);
         ProcType = 0;
         if(ValidPacket = VJmp->GetRcvVld(PacketID))
         {

            // get process type
            ProcType = VJmp->GetProcType(PacketID);

            switch(ProcType)
            {
            case 1:   // Entity control
               Packet->Unpack(CrntPacket,Swap,ATbl);
               break;
            case 3:   // V3 Celestial or Atmosphere to V1 or V2 EnvCtrl
               Packet->Unpack(CrntPacket,Swap,&EnvHoldObj);
               break;
            case 2:   // V1 or V2 EnvCtrl to Celestial and Atmosphere
            default:   // most packets
               Packet->Unpack(CrntPacket,Swap,NULL);
               break;
            }

         }

         if(PacketSize != 0)
         {
            ReadBufferPos += PacketSize;
            CrntPacket += (int)PacketSize;
         }
         else
         {
            CrntPacket += Size - ReadBufferPos;
            ReadBufferPos = Size;
         }

         if(ValidPacket)
         {

            ReadPacketID = VJmp->GetCnvtToReaderID(PacketID);

            bool PacketProcessed = false;

            int Step = 1;
            Cigi_uint8 Pckt[2];

            switch(ProcType)
            {
            case 1:   // Entity control
               Step = 1;
               Pckt[0] = Pckt[1] = ReadPacketID;
               break;
            case 2:   // V1 or V2 EnvCtrl to Celestial and Atmosphere
               Step = 2;
               Pckt[0] = CIGI_ATMOS_CTRL_PACKET_ID_V3;
               Pckt[1] = CIGI_CELESTIAL_CTRL_PACKET_ID_V3;
               break;
            case 3:   // V3 Celestial or Atmosphere to V1 or 2 EnvCtrl
               Step = 1;
               Pckt[0] = Pckt[1] = ReadPacketID;
               Packet = &EnvHoldObj;
               break;
            default:   // most packets
               Step = 1;
               Pckt[0] = Pckt[1] = ReadPacketID;
               break;
            }


            for(int IDndx=0;IDndx<Step;IDndx++)
            {

#ifndef CIGI_NO_SIGNAL_PROCESSING

               if(SignalJump(Pckt[IDndx], Packet))
                  PacketProcessed = true;

#endif
#ifndef CIGI_NO_EVENT_PROCESSING
               // Event processing
               CrntObj = EventList[Pckt[IDndx]];

               while(CrntObj != NULL)
               {
                  PacketProcessed = true;

                  (CrntObj->GetCigiEvent())->OnPacketReceived(Packet);

                  CrntObj = CrntObj->GetNextEvent();
               }
#endif
#ifndef CIGI_NO_CALLBACK
               // Callback processing
               CrntObj = CallBackList[Pckt[IDndx]];

               while(CrntObj != NULL)
               {
                  PacketProcessed = true;

                  (CrntObj->GetCigiCallBack())(Packet);

                  CrntObj = CrntObj->GetNextEvent();
               }
#endif

            }



            if(!PacketProcessed)
            {
#ifndef CIGI_NO_EVENT_PROCESSING
               // Event processing
               CrntObj = EventList[0];

               while(CrntObj != NULL)
               {
                  (CrntObj->GetCigiEvent())->OnPacketReceived(Packet);

                  CrntObj = CrntObj->GetNextEvent();
               }
#endif
#ifndef CIGI_NO_CALLBACK
               // Callback processing
               CrntObj = CallBackList[0];

               while(CrntObj != NULL)
               {
                  (CrntObj->GetCigiCallBack())(Packet);

                  CrntObj = CrntObj->GetNextEvent();
               }
#endif
            }

         }

      }

      // Determine the most mature Cigi version received
      if(MostMatureCigiVersionReceived != tMVer)
      {
         if(MostMatureCigiVersionReceived < tMVer)
         {
            if(tMVer != 0)
               // tMVer is already the Set Cigi Version
               MostMatureCigiVersionReceived = tMVer;
         }
         else
         {

            // Break The Most Mature Cigi Version into Cigi Version
            //  and Cigi Minor Version
            Version = (MostMatureCigiVersionReceived >> 8) & 0x000000ff;
            MinorVer = MostMatureCigiVersionReceived & 0x000000ff;

            // Set version to the most mature Cigi version received
#ifndef CIGI_NO_EXCEPT
            try
            {
               VJmp->SetCigiVersion(Version,MinorVer);
            }
            catch(CigiValueOutOfRangeException)
            {
               // Reset version back to tMVer

               // Convert tMVer to Version & Minor Version
               Version = (tMVer >> 8) & 0x000000ff;
               MinorVer = tMVer & 0x000000ff;

               try
               {
                  VJmp->SetCigiVersion(Version,MinorVer);
                  MostMatureCigiVersionReceived = tMVer;
               }
               catch(CigiValueOutOfRangeException)
               {
                  // Default to Version 3.2
                  VJmp->SetCigiVersion(3,2);
                  MostMatureCigiVersionReceived = 0;
               }
            }
#else
            if(VJmp->SetCigiVersion(Version,MinorVer) != CIGI_SUCCESS)
            {
               // Reset version back to tMVer

               // Convert tMVer to Version & Minor Version
               Version = (tMVer >> 8) & 0x000000ff;
               MinorVer = tMVer & 0x000000ff;

               if(VJmp->SetCigiVersion(Version,MinorVer) != CIGI_SUCCESS)
               {
                  // Default to Version 3.2
                  VJmp->SetCigiVersion(3,2);
                  MostMatureCigiVersionReceived = 0;
               }
               else
                  MostMatureCigiVersionReceived = tMVer;

            }

#endif

         }

      }



   }


   return(CIGI_SUCCESS);

}



// ================================================
// SignalJump
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
bool CigiIncomingMsg::SignalJump(const Cigi_uint8 PacketID, CigiBasePacket *Packet)
{
   CigiVersionJumpTable::SignalTblType JmpNdx =
      VJmp->GetSignalType(PacketID);

   bool Processed = false;

   CigiEventList *CrntObj = SignalList;

   while(CrntObj != NULL)
   {

      Processed = true;

      switch(JmpNdx)
      {
      case CigiVersionJumpTable::SigIGCtrl:
         (CrntObj->GetCigiSignal())->OnIGCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigEntityCtrl:
         (CrntObj->GetCigiSignal())->OnEntityCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigViewDef:
         (CrntObj->GetCigiSignal())->OnViewDef(Packet);
         break;
      case CigiVersionJumpTable::SigViewCtrl:
         (CrntObj->GetCigiSignal())->OnViewCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigRateCtrl:
         (CrntObj->GetCigiSignal())->OnRateCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigSensorCtrl:
         (CrntObj->GetCigiSignal())->OnSensorCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigTrajectory:
         (CrntObj->GetCigiSignal())->OnTrajectory(Packet);
         break;
      case CigiVersionJumpTable::SigWeatherCtrl:
         (CrntObj->GetCigiSignal())->OnWeatherCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigCollDetSegDef:
         (CrntObj->GetCigiSignal())->OnCollDetSegDef(Packet);
         break;
      case CigiVersionJumpTable::SigLosSegReq:
         (CrntObj->GetCigiSignal())->OnLosSegReq(Packet);
         break;
      case CigiVersionJumpTable::SigLosVectReq:
         (CrntObj->GetCigiSignal())->OnLosVectReq(Packet);
         break;
      case CigiVersionJumpTable::SigHatReq:
         (CrntObj->GetCigiSignal())->OnHatReq(Packet);
         break;
      case CigiVersionJumpTable::SigHotReq:
         (CrntObj->GetCigiSignal())->OnHotReq(Packet);
         break;
      case CigiVersionJumpTable::SigHatHotReq:
         (CrntObj->GetCigiSignal())->OnHatHotReq(Packet);
         break;
      case CigiVersionJumpTable::SigHatHotXReq:
         (CrntObj->GetCigiSignal())->OnHatHotXReq(Packet);
         break;
      case CigiVersionJumpTable::SigEnvCtrl:
         (CrntObj->GetCigiSignal())->OnEnvCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigSpecEffDef:
         (CrntObj->GetCigiSignal())->OnSpecEffDef(Packet);
         break;
      case CigiVersionJumpTable::SigArtPartCtrl:
         (CrntObj->GetCigiSignal())->OnArtPartCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigCollDetVolDef:
         (CrntObj->GetCigiSignal())->OnCollDetVolDef(Packet);
         break;
      case CigiVersionJumpTable::SigShortArtPartCtrl:
         (CrntObj->GetCigiSignal())->OnShortArtPartCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigConfClampEntityCtrl:
         (CrntObj->GetCigiSignal())->OnConfClampEntityCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigMaritimeSurfaceCtrl:
         (CrntObj->GetCigiSignal())->OnMaritimeSurfaceCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigEnvRgnCtrl:
         (CrntObj->GetCigiSignal())->OnEnvRgnCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigTerrestrialSurfaceCtrl:
         (CrntObj->GetCigiSignal())->OnTerrestrialSurfaceCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigMotionTrackCtrl:
         (CrntObj->GetCigiSignal())->OnMotionTrackCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigEarthModelDef:
         (CrntObj->GetCigiSignal())->OnEarthModelDef(Packet);
         break;
      case CigiVersionJumpTable::SigPostionReq:
         (CrntObj->GetCigiSignal())->OnPostionReq(Packet);
         break;
      case CigiVersionJumpTable::SigEnvCondReq:
         (CrntObj->GetCigiSignal())->OnEnvCondReq(Packet);
         break;
      case CigiVersionJumpTable::SigWaveCtrl:
         (CrntObj->GetCigiSignal())->OnWaveCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigCompCtrl:
         (CrntObj->GetCigiSignal())->OnCompCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigShortCompCtrl:
         (CrntObj->GetCigiSignal())->OnShortCompCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigSOF:
         (CrntObj->GetCigiSignal())->OnSOF(Packet);
         break;
      case CigiVersionJumpTable::SigCollDetSegResp:
         (CrntObj->GetCigiSignal())->OnCollDetSegResp(Packet);
         break;
      case CigiVersionJumpTable::SigSensorResp:
         (CrntObj->GetCigiSignal())->OnSensorResp(Packet);
         break;
      case CigiVersionJumpTable::SigSensorXResp:
         (CrntObj->GetCigiSignal())->OnSensorXResp(Packet);
         break;
      case CigiVersionJumpTable::SigLosResp:
         (CrntObj->GetCigiSignal())->OnLosResp(Packet);
         break;
      case CigiVersionJumpTable::SigLosXResp:
         (CrntObj->GetCigiSignal())->OnLosXResp(Packet);
         break;
      case CigiVersionJumpTable::SigHatResp:
         (CrntObj->GetCigiSignal())->OnHatResp(Packet);
         break;
      case CigiVersionJumpTable::SigHotResp:
         (CrntObj->GetCigiSignal())->OnHotResp(Packet);
         break;
      case CigiVersionJumpTable::SigHatHotResp:
         (CrntObj->GetCigiSignal())->OnHatHotResp(Packet);
         break;
      case CigiVersionJumpTable::SigHatHotXResp:
         (CrntObj->GetCigiSignal())->OnHatHotXResp(Packet);
         break;
      case CigiVersionJumpTable::SigCollDetVolResp:
         (CrntObj->GetCigiSignal())->OnCollDetVolResp(Packet);
         break;
      case CigiVersionJumpTable::SigPositionResp:
         (CrntObj->GetCigiSignal())->OnPositionResp(Packet);
         break;
      case CigiVersionJumpTable::SigWeatherCondResp:
         (CrntObj->GetCigiSignal())->OnWeatherCondResp(Packet);
         break;
      case CigiVersionJumpTable::SigAerosolResp:
         (CrntObj->GetCigiSignal())->OnAerosolResp(Packet);
         break;
      case CigiVersionJumpTable::SigMaritimeSurfaceResp:
         (CrntObj->GetCigiSignal())->OnMaritimeSurfaceResp(Packet);
         break;
      case CigiVersionJumpTable::SigTerrestrialSurfaceResp:
         (CrntObj->GetCigiSignal())->OnTerrestrialSurfaceResp(Packet);
         break;
      case CigiVersionJumpTable::SigAnimationStop:
         (CrntObj->GetCigiSignal())->OnAnimationStop(Packet);
         break;
      case CigiVersionJumpTable::SigEventNotification:
         (CrntObj->GetCigiSignal())->OnEventNotification(Packet);
         break;
      case CigiVersionJumpTable::SigIGMsg:
         (CrntObj->GetCigiSignal())->OnIGMsg(Packet);
         break;
      case CigiVersionJumpTable::SigAtmosCtrl:
         (CrntObj->GetCigiSignal())->OnAtmosCtrl(Packet);
         break;
      case CigiVersionJumpTable::SigCelestialCtrl:
         (CrntObj->GetCigiSignal())->OnCelestialCtrl(Packet);
         break;
      default:
         (CrntObj->GetCigiSignal())->OnUnrecognized(Packet);
         break;
      }

      CrntObj = CrntObj->GetNextEvent();

   }

   return(Processed);

}



// ====================================================================
// Accessors
// ====================================================================



// ================================================
// GetNextBuffToLoad
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Cigi_uint8 *CigiIncomingMsg::GetNextBuffToLoad(void)
{

   if(BufferCount != 1)
   {
      int tbuf = CrntFillBuf + 1;
      if(tbuf >= BufferCount)
         tbuf = 0;

      if(tbuf != CrntMsgBuf)
         CrntFillBuf = tbuf;

      BuffFillCnt[CrntFillBuf] = 0;
      FillBufferPos = BasePtr[CrntFillBuf];
   }
   else
      CrntFillBuf = 0;

   return(BasePtr[CrntFillBuf]);

}



// ================================================
// AdvanceCrntBuffer
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void CigiIncomingMsg::AdvanceCrntBuffer(void)
{

   if(BufferCount == 1)
      CrntMsgBuf = 0;
   else
   {
      if(CrntMsgBuf != CrntFillBuf)
      {
         CrntMsgBuf++;
         if(CrntMsgBuf >= BufferCount)
            CrntMsgBuf = 0;

      }
      else
         BuffFillCnt[CrntMsgBuf] = 0;
   }

}




// ================================================
// GetFirstPacket
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBasePacket * CigiIncomingMsg::GetFirstPacket()
{
   Cigi_uint8 PacketID;
   Cigi_uint8 PacketSize;
   CigiBasePacket *Packet;
   int Version;
   int MinorVer;
   int tMVer;
   CigiBaseSOF *SOF;
   CigiBaseIGCtrl *IGCtrl;

   Swap = false;


   CrntPacket = MsgStart;
   ReadBufferPos = 0;

   PacketID = *CrntPacket;
   PacketSize = *(CrntPacket+1);
   Version = (int)(*(CrntPacket+2));

   if(Version < 3)
      MinorVer = 0;
   else
      MinorVer = (int)((*(CrntPacket+4) >> 4) & 0x0f);



   // If there is an unrecognized version ...
   // Set the version to 3 and do the best
   //   compatibility conversion possible.
   tMVer = ((Version << 8) & 0x0000ff00) | 
      (MinorVer & 0x000000ff);

   if((Version != VJmp->GetCigiVersion()) ||
      (MinorVer != VJmp->GetCigiMinorVersion()))
   {

#ifndef CIGI_NO_EXCEPT
      try
      {
         VJmp->SetCigiVersion(Version,MinorVer);
         IterationVersion = tMVer;
      }
      catch(CigiValueOutOfRangeException)
      {
         VJmp->SetCigiVersion(3,2);
         tMVer = 0;
         IterationVersion = ((3 << 8) & 0x0000ff00) | 2;
      }
#else
      if(VJmp->SetCigiVersion(Version,MinorVer) == CIGI_SUCCESS)
         IterationVersion = tMVer;
      else
      {
         VJmp->SetCigiVersion(3,2);
         tMVer = 0;
         IterationVersion = ((3 << 8) & 0x0000ff00) | 2;
      }
#endif
   }

   // If the Iteration version has not been set,
   //  set it to the last recieved CIGI version.
   if(IterationVersion == 0)
      IterationVersion = tMVer;


   if(VJmp->GetJmpTbltype() == CigiVersionJumpTable::Host)
   {
      if(PacketID == 101) // CIGI_START_OF_FRAME_OPCODE)
      {
         SOF = (CigiBaseSOF *)VJmp->GetPcktHndlr(101);
         SOF->Unpack(CrntPacket,false,NULL);
         Swap = SOF->GetSwap();
         Packet = (CigiBasePacket *)SOF;
         VJmp->SetReceivedFrameID(SOF->GetFrameCntr());
         if((VJmp->IsSynchronous()) &&
            ((VJmp->GetCigiVersion() < 3) ||
            ((VJmp->GetCigiVersion() == 3) && (VJmp->GetCigiMinorVersion() < 2))))
            VJmp->SetFrameCnt(SOF->GetFrameCntr());
      }
      else
      {

#ifndef CIGI_NO_EXCEPT
         throw CigiMissingStartOfFrameException();
#endif
         return(NULL);

      }
   }
   else
   {
      if(PacketID == 1) // CIGI_IG_CONTROL_OPCODE)
      {
         IGCtrl = (CigiBaseIGCtrl *)VJmp->GetPcktHndlr(1);
         IGCtrl->Unpack(CrntPacket,false,NULL);
         Swap = IGCtrl->GetSwap();
         Packet = (CigiBasePacket *)IGCtrl;
      }
      else
      {

#ifndef CIGI_NO_EXCEPT
         throw CigiMissingIgControlException();
#endif
         return(NULL);

      }
   }


   ReadBufferPos = (int)PacketSize;
   CrntPacket += (int)PacketSize;


   // Determine the most mature Cigi version received
   if(MostMatureCigiVersionReceived != tMVer)
   {
      if(MostMatureCigiVersionReceived < tMVer)
      {
         if(tMVer != 0)
            // tMVer is already the Set Cigi Version
            MostMatureCigiVersionReceived = tMVer;
      }
      else
      {

         // Break The Most Mature Cigi Version into Cigi Version
         //  and Cigi Minor Version
         Version = (MostMatureCigiVersionReceived >> 8) & 0x000000ff;
         MinorVer = MostMatureCigiVersionReceived & 0x000000ff;

         // Set version to the most mature Cigi version received
#ifndef CIGI_NO_EXCEPT
         try
         {
            VJmp->SetCigiVersion(Version,MinorVer);
         }
         catch(CigiValueOutOfRangeException)
         {
            // Reset version back to tMVer

            // Convert tMVer to Version & Minor Version
            Version = (tMVer >> 8) & 0x000000ff;
            MinorVer = tMVer & 0x000000ff;

            try
            {
               VJmp->SetCigiVersion(Version,MinorVer);
               MostMatureCigiVersionReceived = tMVer;
            }
            catch(CigiValueOutOfRangeException)
            {
               // Default to Version 3.2
               VJmp->SetCigiVersion(3,2);
               MostMatureCigiVersionReceived = 0;
            }
         }
#else
         if(VJmp->SetCigiVersion(Version,MinorVer) != CIGI_SUCCESS)
         {
            // Reset version back to tMVer

            // Convert tMVer to Version & Minor Version
            Version = (tMVer >> 8) & 0x000000ff;
            MinorVer = tMVer & 0x000000ff;

            if(VJmp->SetCigiVersion(Version,MinorVer) != CIGI_SUCCESS)
            {
               // Default to Version 3.2
               VJmp->SetCigiVersion(3,2);
               MostMatureCigiVersionReceived = 0;
            }
            else
               MostMatureCigiVersionReceived = tMVer;

         }

#endif

      }

   }


   return(Packet);

}

// ================================================
// GetNextPacket
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiBasePacket * CigiIncomingMsg::GetNextPacket()
{
   Cigi_uint8 PacketID;
   Cigi_uint8 PacketSize;
   CigiBasePacket *Packet;
   int Version;
   int MinorVer;
   int tMVer = ((VJmp->GetCigiVersion() << 8) & 0x0000ff00) |
                (VJmp->GetCigiMinorVersion() & 0x000000ff);

   if(IterationVersion != tMVer)
   {
      Version = (IterationVersion >> 8) & 0x000000ff;
      MinorVer = IterationVersion & 0x000000ff;
#ifndef CIGI_NO_EXCEPT
      try
      {
         VJmp->SetCigiVersion(Version,MinorVer);
      }
      catch(CigiValueOutOfRangeException)
      {
         VJmp->SetCigiVersion(3,2);
         IterationVersion = ((3 << 8) & 0x0000ff00) | 2;
      }
#else
      if(VJmp->SetCigiVersion(Version,MinorVer) != CIGI_SUCCESS)
      {
         VJmp->SetCigiVersion(3,2);
         IterationVersion = ((3 << 8) & 0x0000ff00) | 2;
      }
#endif
   }

   if(ReadBufferPos < MsgSize)
   {

      PacketID = *CrntPacket;
      Packet = VJmp->GetPcktHndlr(PacketID);
      Packet->Unpack(CrntPacket,Swap,NULL);
      PacketSize = Packet->GetPacketSize();

      ReadBufferPos += PacketSize;
      CrntPacket += (int)PacketSize;

   }
   else
      Packet = NULL;



   // Determine the most mature Cigi version received
   if(MostMatureCigiVersionReceived != IterationVersion)
   {

      // Break The Most Mature Cigi Version into Cigi Version
      //  and Cigi Minor Version
      Version = (MostMatureCigiVersionReceived >> 8) & 0x000000ff;
      MinorVer = MostMatureCigiVersionReceived & 0x000000ff;

#ifndef CIGI_NO_EXCEPT
      try
      {
         VJmp->SetCigiVersion(Version,MinorVer);
      }
      catch(CigiValueOutOfRangeException)
      {
         VJmp->SetCigiVersion(3,2);
      }
#else
      if(VJmp->SetCigiVersion(Version,MinorVer) != CIGI_SUCCESS)
         VJmp->SetCigiVersion(3,2);

#endif
   }



   return(Packet);

}

// ================================================
// RegisterEventProcessor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIncomingMsg::RegisterEventProcessor(int PacketID, CigiBaseEventProcessor *EventMgr)
{

   if((PacketID < 0)||(PacketID > 256))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("PacketID",PacketID,0,256);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }

   CigiEventList *NewObj;

   if(EventList[PacketID] == NULL)
   {
      NewObj = new CigiEventList;
      NewObj->SetCigiEvent(EventMgr);
      EventList[PacketID] = NewObj;
   }
   else
   {
      CigiEventList *CrntObj = EventList[PacketID];

      while(CrntObj->GetNextEvent() != NULL)
      {
         CrntObj = CrntObj->GetNextEvent();
      }

      NewObj = new CigiEventList;
      CrntObj->SetNextEvent(NewObj);
      NewObj->SetCigiEvent(EventMgr);

   }

   return(CIGI_SUCCESS);

}

// ================================================
// UnregisterEventProcessor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIncomingMsg::UnregisterEventProcessor(int PacketID, CigiBaseEventProcessor *EventMgr)
{

   if((PacketID < 0)||(PacketID > 256))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("PacketID",PacketID,0,256);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }

   CigiEventList *PrevObj = NULL;
   CigiEventList *CrntObj = EventList[PacketID];
   CigiEventList *NextObj = NULL;
   bool Found = false;

   while(!Found && (CrntObj != NULL))
   {
      NextObj = CrntObj->GetNextEvent();
      if(CrntObj->GetCigiEvent() == EventMgr)
      {
         Found = true;

         if(PrevObj == NULL)
            EventList[PacketID] = NextObj;
         else
            PrevObj->SetNextEvent(NextObj);

         delete CrntObj;
      }
      else
      {
         PrevObj = CrntObj;
         CrntObj = NextObj;
      }
   }

   return(CIGI_SUCCESS);

}

// ================================================
// RegisterCallBack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIncomingMsg::RegisterCallBack(int PacketID, CigiCBProcessor CallBack)
{

   if((PacketID < 0)||(PacketID > 256))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("PacketID",PacketID,0,256);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }

   CigiEventList *NewObj;

   if(CallBackList[PacketID] == NULL)
   {
      NewObj = new CigiEventList;
      NewObj->SetCigiCallBack(CallBack);
      CallBackList[PacketID] = NewObj;
   }
   else
   {
      CigiEventList *CrntObj = CallBackList[PacketID];

      while(CrntObj->GetNextEvent() != NULL)
      {
         CrntObj = CrntObj->GetNextEvent();
      }

      NewObj = new CigiEventList;
      CrntObj->SetNextEvent(NewObj);
      NewObj->SetCigiCallBack(CallBack);

   }

   return(CIGI_SUCCESS);

}

// ================================================
// UnregisterCallBack
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIncomingMsg::UnregisterCallBack(int PacketID, CigiCBProcessor CallBack)
{

   if((PacketID < 0)||(PacketID > 256))
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiValueOutOfRangeException("PacketID",PacketID,0,256);
#endif
      return(CIGI_ERROR_VALUE_OUT_OF_RANGE);
   }

   CigiEventList *PrevObj = NULL;
   CigiEventList *CrntObj = CallBackList[PacketID];
   CigiEventList *NextObj = NULL;
   bool Found = false;

   while(!Found && (CrntObj != NULL))
   {
      NextObj = CrntObj->GetNextEvent();
      if(CrntObj->GetCigiCallBack() == CallBack)
      {
         Found = true;

         if(PrevObj == NULL)
            CallBackList[PacketID] = NextObj;
         else
            PrevObj->SetNextEvent(NextObj);

         delete CrntObj;
      }
      else
      {
         PrevObj = CrntObj;
         CrntObj = NextObj;
      }
   }

   return(CIGI_SUCCESS);

}

// ================================================
// RegisterSignalProcessor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIncomingMsg::RegisterSignalProcessor(CigiBaseSignalProcessing *SignalMgr)
{
   CigiEventList *NewObj;

   if(SignalList == NULL)
   {
      NewObj = new CigiEventList;
      NewObj->SetCigiSignal(SignalMgr);
      SignalList = NewObj;
   }
   else
   {
      CigiEventList *CrntObj = SignalList;

      while(CrntObj->GetNextEvent() != NULL)
      {
         CrntObj = CrntObj->GetNextEvent();
      }

      NewObj = new CigiEventList;
      CrntObj->SetNextEvent(NewObj);
      NewObj->SetCigiSignal(SignalMgr);

   }

   return(CIGI_SUCCESS);

}

// ================================================
// UnregisterSignalProcessor
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiIncomingMsg::UnregisterSignalProcessor(CigiBaseSignalProcessing *SignalMgr)
{
   CigiEventList *PrevObj = NULL;
   CigiEventList *CrntObj = SignalList;
   CigiEventList *NextObj = NULL;
   bool Found = false;

   while(!Found && (CrntObj != NULL))
   {
      NextObj = CrntObj->GetNextEvent();

      if(CrntObj->GetCigiSignal() == SignalMgr)
      {
         Found = true;

         if(PrevObj == NULL)
            SignalList = NextObj;
         else
            PrevObj->SetNextEvent(NextObj);

         delete CrntObj;
      }
      else
      {
         PrevObj = CrntObj;
         CrntObj = NextObj;
      }
   }

   return(CIGI_SUCCESS);

}



