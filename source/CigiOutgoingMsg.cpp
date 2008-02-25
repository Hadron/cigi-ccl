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
 *  FILENAME:   CigiOutgoingMsg.cpp
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
 *  Defined _EXPORT_CCL_ for exporting the class in a Windows DLL.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Changed native C++ types to use CCL-defined types instead where appropriate.
 *  
 *  02/20/2006 Greg Basler                       Version 1.6.0
 *  Added the PackageMsg and FreeMsg methods to better update the frame
 *  the frame counter in the IG_Ctrl packet for hosts
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the class constructor and destructor methods to initialize 
 *  (allocate) and destroy the CurrentIGCtrl and CurrentSOF member variables.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Updated the overloaded << operators for the CigiBaseIGCtrl parameter to set 
 *  the CurrentIGCtrl member variable, and for the CigiBaseSOF parameter to set 
 *  the CurrentSOF member variable.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Updated the UpdateFrameCntr methods to use minor version numbers and to add 
 *  additional frame synchronization functionality.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Modified the UpdateIGCtrl and UpdateSOF methods to use minor version 
 *  numbers and to add additional frame synchronization functionality.
 *  
 *  04/14/2006 Greg Basler                       Version 1.7.0
 *  Implemented the Reset method.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 *
 *  11/27/2006 Greg Basler                       Version 1.7.4
 *  Corrected UpdateIGCtrl so that it zeros the outgoing database id when the
 *    outgoing database id is negative or incoming database id is negative
 *    unless it is -128 or the outgoing database id is the same as the
 *    incoming database id.
 *    It does not zero the id if the incoming id is -128 because an incoming
 *    database id of -128 signifies a database not found condition.
 *  
 *  04/24/2007 Greg Basler                       Version 1.7.5
 *  Corrected a problem with the database id adjustment code in UpdateIGCtrl.
 *    The user can disable database id adjustment by declaring
 *    _NO_DATABASE_ADJUSTMENT_. (note: the system will still 0 a negative
 *    database request.) The database adjustment code now will 0 the database
 *    request if the incoming database number is the same or the negative of
 *    database request. It does not 0 the database request if the incoming
 *    database number is -128.
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.7.5
 */

#include <stdlib.h>

#define _EXPORT_CCL_

#include "CigiOutgoingMsg.h"
#include "CigiBasePacket.h"
#include "CigiExceptions.h"
#include "CigiSwapping.h"

#include "CigiIGCtrlV3.h"
#include "CigiSOFV3.h"

#ifdef CIGI_LITTLE_ENDIAN
   #define CIGI_SCOPY2 CigiSwap2
   #define CIGI_SCOPY4 CigiSwap4
   #define CIGI_SCOPY8 CigiSwap8
#else
   #define CIGI_SCOPY2 CigiCopy2
   #define CIGI_SCOPY4 CigiCopy4
   #define CIGI_SCOPY8 CigiCopy8
#endif


// ====================================================================
// Construction/Destruction
// ====================================================================

// ================================================
// CigiOutgoingMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg::CigiOutgoingMsg()
{
   PackagedMsg = -1;

   CurrentIGCtrl = new CigiIGCtrlV3;
   CurrentSOF = new CigiSOFV3;

}

// ================================================
// ~CigiOutgoingMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg::~CigiOutgoingMsg()
{

   delete CurrentIGCtrl;
   delete CurrentSOF;

}



// ====================================================================
// Processing
// ====================================================================

// ================================================
// BeginMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::BeginMsg()
{

   if(Active || Locked)
   {

#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Active = true;
   ValidIGCtrlSOF = false;

   if(!Data[CrntMsgBuf])
   {
      Data[CrntMsgBuf] = true;

      if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
      {
         // adjust the following for IG Control Packet
         BuffFillCnt[CrntMsgBuf] = VJmp->GetIGCtrlSize();
         FillBufferPos = BasePtr[CrntMsgBuf] + VJmp->GetIGCtrlSize();
      }
      else
      {
         // adjust the following for SOF Packet
         BuffFillCnt[CrntMsgBuf] = VJmp->GetSOFSize();
         FillBufferPos = BasePtr[CrntMsgBuf] + VJmp->GetSOFSize();
      }
   }

   return(CIGI_SUCCESS);

}


// ================================================
// operator << - IG Control
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBaseIGCtrl &refPacket)
{
   *CurrentIGCtrl = refPacket;

   Cigi_uint8 JTblNdx =
      VJmp->GetCnvtID(refPacket.GetPacketID(),refPacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {
      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);

      PackHndlr->Pack(&refPacket, BasePtr[CrntFillBuf], NULL);

      ValidIGCtrlSOF = true;
   }
#ifndef CIGI_NO_EXCEPT
   else
      throw CigiImproperPacketException();
#endif

   return(*this);

}


// ================================================
// operator << - Start Of Frame
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBaseSOF &refPacket)
{
   *CurrentSOF = refPacket;

   Cigi_uint8 JTblNdx =
      VJmp->GetCnvtID(refPacket.GetPacketID(),refPacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {
      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);

      PackHndlr->Pack(&refPacket, BasePtr[CrntFillBuf], NULL);

      ValidIGCtrlSOF = true;
   }
#ifndef CIGI_NO_EXCEPT
   else
      throw CigiImproperPacketException();
#endif

   return(*this);

}


// ================================================
// operator << - Entity Control
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBaseEntityCtrl &refPacket)
{

   if(!Active || Locked)
      return(*this);  // add exception coding here!

   Cigi_uint8 JTblNdx =
      VJmp->GetCnvtID(refPacket.GetPacketID(),refPacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {

      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);
    
      int Size = PackHndlr->GetPacketSize();

      if( Size > 0 )
      {

         // Check room left in current buffer
         if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
         {
            PackHndlr->Pack(&refPacket, FillBufferPos, ATbl);
            BuffFillCnt[CrntFillBuf] += Size;
            FillBufferPos += Size;
         }
         else
         {

            // next message buffer
            int NMsgBuf = CrntFillBuf + 1;
            if(NMsgBuf >= BufferCount)
               NMsgBuf = 0;

            if(!Data[NMsgBuf])
            {
               CrntFillBuf = NMsgBuf;
               Data[NMsgBuf] = true;
               if(VJmp->GetJmpTbltype() ==
                         CigiVersionJumpTable::Host)
               {
                  // adjust the following for IG Control Packet
                  BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                  FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
               }
               else
               {
                  // adjust the following for SOF Packet
                  BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                  FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
               }


               PackHndlr->Pack(&refPacket, FillBufferPos, ATbl);
               BuffFillCnt[NMsgBuf] += Size;
               FillBufferPos += Size;

            }
#ifndef CIGI_NO_EXCEPT
            else
               throw CigiBufferOverrunException();
#endif

         }

      }

   }

   return(*this);

}



// ================================================
// operator << - Entity Control
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBaseEnvCtrl &refPacket)
{

   int Size;

   if(!Active || Locked)
      return(*this);  // add exception coding here!

   Cigi_uint8 JTblNdx =
      VJmp->GetCnvtID(refPacket.GetPacketID(),refPacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {

      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);

      Cigi_uint8 FillVer = refPacket.GetVersion();
      Cigi_uint8 SendVer = PackHndlr->GetVersion();

      // If the fill and send versions are the same or
      //   they are both below version 3
      if((FillVer == SendVer) ||
         ((FillVer < 3) && (SendVer < 3)))
      {

         Size = PackHndlr->GetPacketSize();

         if( Size > 0 )
         {

            // Check room left in current buffer
            if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
            {
               PackHndlr->Pack(&refPacket, FillBufferPos, NULL);
               BuffFillCnt[CrntFillBuf] += Size;
               FillBufferPos += Size;
            }
            else
            {

               // next message buffer
               int NMsgBuf = CrntFillBuf + 1;
               if(NMsgBuf >= BufferCount)
                  NMsgBuf = 0;

               if(!Data[NMsgBuf])
               {
                  CrntFillBuf = NMsgBuf;
                  Data[NMsgBuf] = true;
                  if(VJmp->GetJmpTbltype() ==
                     CigiVersionJumpTable::Host)
                  {
                     // adjust the following for IG Control Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
                  }
                  else
                  {
                     // adjust the following for SOF Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
                  }


                  PackHndlr->Pack(&refPacket, FillBufferPos, NULL);
                  BuffFillCnt[NMsgBuf] += Size;
                  FillBufferPos += Size;

               }
#ifndef CIGI_NO_EXCEPT
               else
                  throw CigiBufferOverrunException();
#endif

            }

         }

      }
      // if fill version is 1 or 2 sending to version 3
      else if((FillVer < 3) && (SendVer == 3))
      {

         // Get special Packet handlers
         CigiBasePacket * CPackHndlr = NULL;  // Celestial
         CigiBasePacket * APackHndlr = NULL;  // Atmosphere
         VJmp->GetDEnvPcktHndlr(&CPackHndlr,&APackHndlr);

         // Fill in Celestial

         Size = CPackHndlr->GetPacketSize();

         if( Size > 0 )
         {

            // Check room left in current buffer
            if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
            {
               CPackHndlr->Pack(&refPacket, FillBufferPos, NULL);
               BuffFillCnt[CrntFillBuf] += Size;
               FillBufferPos += Size;
            }
            else
            {

               // next message buffer
               int NMsgBuf = CrntFillBuf + 1;
               if(NMsgBuf >= BufferCount)
                  NMsgBuf = 0;

               if(!Data[NMsgBuf])
               {
                  CrntFillBuf = NMsgBuf;
                  Data[NMsgBuf] = true;
                  if(VJmp->GetJmpTbltype() ==
                     CigiVersionJumpTable::Host)
                  {
                     // adjust the following for IG Control Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
                  }
                  else
                  {
                     // adjust the following for SOF Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
                  }


                  CPackHndlr->Pack(&refPacket, FillBufferPos, NULL);
                  BuffFillCnt[NMsgBuf] += Size;
                  FillBufferPos += Size;

               }
#ifndef CIGI_NO_EXCEPT
               else
                  throw CigiBufferOverrunException();
#endif

            }

         }


         // Fill in Atmosphere

         Size = APackHndlr->GetPacketSize();

         if( Size > 0 )
         {

            // Check room left in current buffer
            if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
            {
               APackHndlr->Pack(&refPacket, FillBufferPos, NULL);
               BuffFillCnt[CrntFillBuf] += Size;
               FillBufferPos += Size;
            }
            else
            {

               // next message buffer
               int NMsgBuf = CrntFillBuf + 1;
               if(NMsgBuf >= BufferCount)
                  NMsgBuf = 0;

               if(!Data[NMsgBuf])
               {
                  CrntFillBuf = NMsgBuf;
                  Data[NMsgBuf] = true;
                  if(VJmp->GetJmpTbltype() ==
                     CigiVersionJumpTable::Host)
                  {
                     // adjust the following for IG Control Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
                  }
                  else
                  {
                     // adjust the following for SOF Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
                  }


                  APackHndlr->Pack(&refPacket, FillBufferPos, NULL);
                  BuffFillCnt[NMsgBuf] += Size;
                  FillBufferPos += Size;

               }
#ifndef CIGI_NO_EXCEPT
               else
                  throw CigiBufferOverrunException();
#endif

            }

         }

      }
      // otherwise fill version 3 to send version 1 or 2
      else
      {

         refPacket.FillHold(&EnvHoldObj);

         Size = PackHndlr->GetPacketSize();

         if( Size > 0 )
         {

            // Check room left in current buffer
            if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
            {
//               PackHndlr->Pack(&refPacket, FillBufferPos, (void *)&EnvHoldObj);
               PackHndlr->Pack(&EnvHoldObj, FillBufferPos,NULL);
               BuffFillCnt[CrntFillBuf] += Size;
               FillBufferPos += Size;
            }
            else
            {

               // next message buffer
               int NMsgBuf = CrntFillBuf + 1;
               if(NMsgBuf >= BufferCount)
                  NMsgBuf = 0;

               if(!Data[NMsgBuf])
               {
                  CrntFillBuf = NMsgBuf;
                  Data[NMsgBuf] = true;
                  if(VJmp->GetJmpTbltype() ==
                     CigiVersionJumpTable::Host)
                  {
                     // adjust the following for IG Control Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
                  }
                  else
                  {
                     // adjust the following for SOF Packet
                     BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                     FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
                  }


//                  PackHndlr->Pack(&refPacket, FillBufferPos, (void *)&EnvHoldObj);
                  PackHndlr->Pack(&EnvHoldObj, FillBufferPos,NULL);
                  BuffFillCnt[NMsgBuf] += Size;
                  FillBufferPos += Size;

               }
#ifndef CIGI_NO_EXCEPT
               else
                  throw CigiBufferOverrunException();
#endif

            }

         }

      }

   }

   return(*this);

}



// ================================================
// operator << - Most Packets
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
CigiOutgoingMsg & CigiOutgoingMsg::operator <<(CigiBasePacket &refBasePacket)
{

   int pSize;

   if(!Active || Locked)
      return(*this);  // add exception coding here!

   Cigi_uint8 JTblNdx =
      VJmp->GetCnvtID(refBasePacket.GetPacketID(),refBasePacket.GetVersion());

   bool Valid = VJmp->GetSndVld(JTblNdx);

   if(Valid)
   {

      CigiBasePacket * PackHndlr = VJmp->GetPcktHndlr(JTblNdx);
    
      int Size = PackHndlr->GetPacketSize();

      if( Size > 0 )
      {

         // Check room left in current buffer
         if((BufferSize - BuffFillCnt[CrntFillBuf]) >= Size)
         {
            pSize = PackHndlr->Pack(&refBasePacket, FillBufferPos, NULL);
            BuffFillCnt[CrntFillBuf] += pSize;
            FillBufferPos += pSize;
         }
         else
         {

            // next message buffer
            int NMsgBuf = CrntFillBuf + 1;
            if(NMsgBuf >= BufferCount)
               NMsgBuf = 0;

            if(!Data[NMsgBuf])
            {
               CrntFillBuf = NMsgBuf;
               Data[NMsgBuf] = true;
               if(VJmp->GetJmpTbltype() ==
                         CigiVersionJumpTable::Host)
               {
                  // adjust the following for IG Control Packet
                  BuffFillCnt[NMsgBuf] = VJmp->GetIGCtrlSize();
                  FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetIGCtrlSize();
               }
               else
               {
                  // adjust the following for SOF Packet
                  BuffFillCnt[NMsgBuf] = VJmp->GetSOFSize();
                  FillBufferPos = BasePtr[NMsgBuf] + VJmp->GetSOFSize();
               }


               pSize = PackHndlr->Pack(&refBasePacket, FillBufferPos, NULL);
               BuffFillCnt[NMsgBuf] += pSize;
               FillBufferPos += pSize;

            }
#ifndef CIGI_NO_EXCEPT
            else
               throw CigiBufferOverrunException();
#endif

         }

      }

   }

   return(*this);

}

// ================================================
// UpdateFrameCntr
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UpdateFrameCntr()
{
   if(!ValidIGCtrlSOF)
   {
      if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingIgControlException();
#endif
         return(CIGI_ERROR_MISSING_IG_CONTROL_PACKET);
      }
      else
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingStartOfFrameException();
#endif
         return(CIGI_ERROR_MISSING_SOF_PACKET);
      }
   }

   int MajorVer = VJmp->GetCigiVersion();

   Cigi_uint32 *buf = (Cigi_uint32 *)BasePtr[CrntMsgBuf];

   Cigi_uint32 Frame = 0;

   bool FrmCtrl = ((MajorVer > 3) ||
         ((MajorVer == 3) && (VJmp->GetCigiMinorVersion() > 1)));

   if((!VJmp->IsSynchronous())||
      (VJmp->GetJmpTbltype() == CigiVersionJumpTable::IG) || FrmCtrl)
      Frame = VJmp->NextFrame();
   else
      Frame = VJmp->GetFrameCnt();


   Cigi_uint32 *pBufr = &buf[VJmp->GetOutFrameBufPos()];

   if(MajorVer >= 3)
   {
      *pBufr = Frame;
      if(FrmCtrl)
      {
         pBufr += 2;
         *pBufr = VJmp->GetReceivedFrameID();
      }
   }
   else
   {
      CIGI_SCOPY4(pBufr,&Frame);
      if(FrmCtrl)
      {
         pBufr += 2;
         Frame = VJmp->GetReceivedFrameID();
         CIGI_SCOPY4(pBufr,&Frame);
      }
   }



   return(CIGI_SUCCESS);

}


// ================================================
// UpdateFrameCntr
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UpdateFrameCntr(Cigi_uint8 *OutgoingMsg)
{

   Cigi_uint32 Frame = 0;
   Cigi_uint32 *pBufr = NULL;

   if((VJmp == NULL)||(OutgoingMsg == NULL))
      return(CIGI_ERROR_UNEXPECTED_NULL);

   int MajorVer = VJmp->GetCigiVersion();

   bool FrmCtrl = ((MajorVer > 3) ||
         ((MajorVer == 3) && (VJmp->GetCigiMinorVersion() > 1)));

   if((!VJmp->IsSynchronous())||
      (VJmp->GetJmpTbltype() == CigiVersionJumpTable::IG) || FrmCtrl)
      Frame = VJmp->NextFrame();
   else
      Frame = VJmp->GetFrameCnt();

   pBufr = ((Cigi_uint32 *)OutgoingMsg) + VJmp->GetOutFrameBufPos();

   if(MajorVer >= 3)
   {
      *pBufr = Frame;
      if(FrmCtrl)
      {
         pBufr += 2;
         *pBufr = VJmp->GetReceivedFrameID();
      }
   }
   else
   {
      CIGI_SCOPY4(pBufr,&Frame);
      if(FrmCtrl)
      {
         pBufr += 2;
         Frame = VJmp->GetReceivedFrameID();
         CIGI_SCOPY4(pBufr,&Frame);
      }
   }



   return(CIGI_SUCCESS);

}


// ================================================
// UpdateIGCtrl
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UpdateIGCtrl(Cigi_uint8 *OutgoingMsg, Cigi_uint8 *IncomingMsg)
{

   Cigi_uint32 Frame = 0;
   Cigi_uint32 InFrame = 0;
   Cigi_uint32 *pBufr = NULL;
   Cigi_int8 *OBufr = NULL;
   Cigi_int8 *IBufr = NULL;
   int MajorVer = VJmp->GetCigiVersion();

   if((VJmp == NULL)||(OutgoingMsg == NULL))
      return(CIGI_ERROR_UNEXPECTED_NULL);


   // Note: For all current CIGI Versions in the
   //  IG Control and Start-Of-Frame packets:
   //  The Packet ID is in the same location in the packets.
   //  The version ID is in the same location in the packets.
   //  The database ID is in the same location in the packets.
   //  The outgoing frame counter is in the same location in the packets.

   bool FrmCtrl = ((MajorVer > 3) ||
         ((MajorVer == 3) && (VJmp->GetCigiMinorVersion() > 1)));



   if((!VJmp->IsSynchronous())||(IncomingMsg == NULL))
   {
      Frame = VJmp->NextFrame();
      if(FrmCtrl)
      {
         InFrame = VJmp->GetReceivedFrameID();
      }
   }
   else
   {
      // For synchronous host operation,
      //  get the frame number from the just received SOF packet
      //  and use that as the current frame number.
      if(*IncomingMsg == 101)
      {
         pBufr = ((Cigi_uint32 *)IncomingMsg) + 2;  // Frame counter location
         if(*(IncomingMsg + 2) >= 3)  // Cigi Version number
         {
            // Cigi Version 3 byte swap magic number
            if(*(((Cigi_uint16 *)IncomingMsg) + 3) == 0x8000)
               Frame = *pBufr;
            else
               CigiSwap4(&Frame,pBufr);
         }
         else
         {
            CIGI_SCOPY4(&Frame,pBufr);
         }

         if(FrmCtrl)
         {
            InFrame = Frame;
            Frame = VJmp->NextFrame();
         }

         // check and adjust the Database IDs
         OBufr = (Cigi_int8 *)(OutgoingMsg + 3);
         if(*OBufr != 0)
         {
            if(*OBufr < 0)
            {
               *OBufr = 0;  // Host sent Database IDs should never be negative
            }
#if !defined(_NO_DATABASE_ADJUSTMENT_)
            else
            {
               // If *IBufr is -128, the IG did not find that database
               //   so the host should send a corrected database id
               // However, if the *OBufr is the same as the *IBufr or
               //  the *IBufr is the negative of *OBufr,
               //  (specifically excluding -128) the outgoing
               //  database id should be 0
               IBufr = (Cigi_int8 *)(IncomingMsg + 3);
               if((*IBufr != -128) &&
                  ((*OBufr == *IBufr) || (*OBufr == (*IBufr * (-1)))))
               {
                  *OBufr = 0;
               }
            }
#endif
         }
      }
      else
      {
         Frame = VJmp->NextFrame();
         if(FrmCtrl)
         {
            InFrame = VJmp->GetReceivedFrameID();
         }
      }
   }



   pBufr = ((Cigi_uint32 *)OutgoingMsg) + VJmp->GetOutFrameBufPos();

   if(VJmp->GetCigiVersion() >= 3)
   {
      *pBufr = Frame;
      if(FrmCtrl)
      {
         pBufr += 2;
         *pBufr = InFrame;
      }
   }
   else
   {
      CIGI_SCOPY4(pBufr,&Frame);
      if(FrmCtrl)
      {
         pBufr += 2;
         CIGI_SCOPY4(pBufr,&InFrame);
      }
   }


   return(CIGI_SUCCESS);

}


// ================================================
// UpdateSOF
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UpdateSOF(Cigi_uint8 *OutgoingMsg)
{
   // Note: For all current CIGI Versions in the
   //  IG Control and Start-Of-Frame packets:
   //  The Packet ID is in the same location in the packets.
   //  The version ID is in the same location in the packets.
   //  The frame counter is in the same location in the packets.

   // For Async operation or for IG operation,
   //   simply increment the frame counter

   if((VJmp == NULL)||(OutgoingMsg == NULL))
      return(CIGI_ERROR_UNEXPECTED_NULL);

   int MajorVer = VJmp->GetCigiVersion();

   Cigi_uint32 Frame = VJmp->NextFrame();

   bool FrmCtrl = ((MajorVer > 3) ||
         ((MajorVer == 3) && (VJmp->GetCigiMinorVersion() > 1)));


   Cigi_uint32 *pBufr = ((Cigi_uint32 *)OutgoingMsg) + VJmp->GetOutFrameBufPos();

   if(VJmp->GetCigiVersion() >= 3)
   {
      *pBufr = Frame;
      if(FrmCtrl)
      {
         pBufr += 2;
         *pBufr = VJmp->GetReceivedFrameID();
      }
   }
   else
   {
      CIGI_SCOPY4(pBufr,&Frame);
      if(FrmCtrl)
      {
         pBufr += 2;
         Frame = VJmp->GetReceivedFrameID();
         CIGI_SCOPY4(pBufr,&Frame);
      }
   }


   return(CIGI_SUCCESS);

}


// ================================================
// LockMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::LockMsg()
{

   if(!ValidIGCtrlSOF)
   {
      if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingIgControlException();
#endif
         return(CIGI_ERROR_MISSING_IG_CONTROL_PACKET);
      }
      else
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingStartOfFrameException();
#endif
         return(CIGI_ERROR_MISSING_SOF_PACKET);
      }
   }

   if( !Active || Locked )
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Locked = true;
   ValidIGCtrlSOF = false;

   return(CIGI_SUCCESS);

}

// ================================================
// GetMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Cigi_uint8 * CigiOutgoingMsg::GetMsg(int &length)
{

   if(!Active)
      return(NULL);

   length = BuffFillCnt[CrntMsgBuf];

   return(BasePtr[CrntMsgBuf]);

}

// ================================================
// GetBuffer
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Cigi_uint8 * CigiOutgoingMsg::GetBuffer()
{

   if(!Active)
      return(NULL);

   return(BasePtr[CrntMsgBuf]);

}

// ================================================
// GetMsgLength
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::GetMsgLength()
{

   if(!Active)
      return(0);

   return(BuffFillCnt[CrntMsgBuf]);

}

// ================================================
// UnlockMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::UnlockMsg()
{

   if(!Active || !Locked)
   {

#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Active = false;

   BuffFillCnt[CrntMsgBuf] = 0;
   Data[CrntMsgBuf] = false;

   int NextBuf = CrntMsgBuf + 1;
   if(NextBuf == BufferCount)
      NextBuf = 0;

   if(CrntFillBuf == CrntMsgBuf)
      CrntFillBuf = NextBuf;

   CrntMsgBuf = NextBuf;

   Locked = false;

   return(CIGI_SUCCESS);

}

// ================================================
// PackageMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::PackageMsg(Cigi_uint8 **Msg, int &length)
{

   *Msg = NULL;
   length = 0;

   if(!ValidIGCtrlSOF)
   {
      if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingIgControlException();
#endif
         return(CIGI_ERROR_MISSING_IG_CONTROL_PACKET);
      }
      else
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiMissingStartOfFrameException();
#endif
         return(CIGI_ERROR_MISSING_SOF_PACKET);
      }
   }

   if( !Active || Locked )
   {
#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Locked = true;
   ValidIGCtrlSOF = false;

   if(PackagedMsg >= 0)
   {
      Data[PackagedMsg] = false;
      BuffFillCnt[PackagedMsg] = 0;
      PackagedMsg = -1;
   }

   length = BuffFillCnt[CrntMsgBuf];
   *Msg = BasePtr[CrntMsgBuf];
   PackagedMsg = CrntMsgBuf;


   int NextBuf = CrntMsgBuf + 1;
   if(NextBuf == BufferCount)
      NextBuf = 0;

   if(CrntFillBuf == CrntMsgBuf)
   {

      if(!Data[NextBuf])
      {
         CrntFillBuf = NextBuf;

         Data[NextBuf] = true;
         if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
         {
            // adjust the following for IG Control Packet
            BuffFillCnt[NextBuf] = VJmp->GetIGCtrlSize();
            FillBufferPos = BasePtr[NextBuf] + VJmp->GetIGCtrlSize();
         }
         else
         {
            // adjust the following for SOF Packet
            BuffFillCnt[NextBuf] = VJmp->GetSOFSize();
            FillBufferPos = BasePtr[NextBuf] + VJmp->GetSOFSize();
         }

      }
      else
      {
#ifndef CIGI_NO_EXCEPT
         throw CigiBufferOverrunException();
#endif
         return(CIGI_ERROR_BUFFER_OVERRUN);
      }

   }

   CrntMsgBuf = NextBuf;

   Locked = false;

   return(CIGI_SUCCESS);

}

// ================================================
// FreeMsg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::FreeMsg(void)
{
   if(PackagedMsg < 0)
   {

#ifndef CIGI_NO_EXCEPT
      throw CigiCalledOutOfSequenceException();
#endif
      return(CIGI_ERROR_CALLED_OUT_OF_SEQUENCE);
   }

   Data[PackagedMsg] = false;
   BuffFillCnt[PackagedMsg] = 0;

   PackagedMsg = -1;

   return(CIGI_SUCCESS);

}



// ================================================
// Reset
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int CigiOutgoingMsg::Reset(void)
{
   int ndx;

   for(ndx=0;ndx<BufferCount;ndx++)
   {
      BuffFillCnt[ndx] = 0;
      Data[ndx] = false;
   }

   CrntMsgBuf = 0;
   FillBufferPos = BasePtr[CrntMsgBuf] + VJmp->GetIGCtrlSize();
   PackagedMsg = -1;
   ValidIGCtrlSOF = false;
   Locked = false;
   CrntMsgBuf = 0;
   FillBufferPos = BasePtr[CrntMsgBuf];

   if(Active)
   {
      if(VJmp->GetJmpTbltype() ==
            CigiVersionJumpTable::Host)
      {
         // adjust the following for IG Control Packet
         BuffFillCnt[CrntMsgBuf] = VJmp->GetIGCtrlSize();
         FillBufferPos = BasePtr[CrntMsgBuf] + VJmp->GetIGCtrlSize();
         *this << *CurrentIGCtrl;
         ValidIGCtrlSOF = true;
      }
      else
      {
         // adjust the following for SOF Packet
         BuffFillCnt[CrntMsgBuf] = VJmp->GetSOFSize();
         FillBufferPos = BasePtr[CrntMsgBuf] + VJmp->GetSOFSize();
         *this << *CurrentSOF;
         ValidIGCtrlSOF = true;
      }
   }

   return(CIGI_SUCCESS);

}


