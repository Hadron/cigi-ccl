// XSOFV2.cpp: Body of the XSOFV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSOFV2.h"
#include <CigiSOFV2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSOFV2::XSOFV2()
{

}

XSOFV2::~XSOFV2()
{

}


void XSOFV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSOFV2 *InPckt = (CigiSOFV2 *)Packet;


   printf("Start Of Frame V2:\n");
   printf("\tDatabase ID = %d\n",InPckt->GetDatabaseID());
   printf("\tIG Status = %u\n",InPckt->GetIGStatus());

   printf("\tIG Mode = %d : ",InPckt->GetIGMode());
   switch(InPckt->GetIGMode())
   {
   case 0:
      printf("Reset\n");
      break;
   case 1:
      printf("Operate\n");
      break;
   case 2:
      printf("debug\n");
      break;
   case 3:
      printf("OfflineMaint\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tFrame Counter = %u\n",InPckt->GetFrameCntr());
   printf("\tTime Stamp = %f\n",InPckt->GetTimeStamp());

}


