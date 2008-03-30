// XSpecEffDefV2.cpp: Body of the XSpecEffDefV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSpecEffDefV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSpecEffDefV2::XSpecEffDefV2()
{

}

XSpecEffDefV2::~XSpecEffDefV2()
{

}


void XSpecEffDefV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSpecEffDefV2 *InPckt = (CigiSpecEffDefV2 *)Packet;

   bool ok = true;

   printf("Special Effect\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());


   printf("\tSequence Direction = %d : ",InPckt->GetSeqDir());
   switch(InPckt->GetSeqDir())
   {
   case 0:
      printf("Forward\n");
      break;
   case 1:
      printf("Backward\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tColor Enable = %d\n",InPckt->GetColorEn());
   printf("\tRed Component = %d\n",InPckt->GetRed());
   printf("\tGreen Component = %d\n",InPckt->GetGreen());
   printf("\tBlue Component = %d\n",InPckt->GetBlue());
   printf("\tX Scale = %f\n",InPckt->GetXScale());
   printf("\tY Scale = %f\n",InPckt->GetYScale());
   printf("\tZ Scale = %f\n",InPckt->GetZScale());
   printf("\tTime Scale = %f\n",InPckt->GetTimeScale());
   printf("\tEffect Count = %d\n",InPckt->GetEffectCnt());
   printf("\tSeperation = %f\n",InPckt->GetSeparation());
   printf("\tBurst Rate = %f\n",InPckt->GetBurstRate());
   printf("\tDuration = %f\n",InPckt->GetDuration());

}
