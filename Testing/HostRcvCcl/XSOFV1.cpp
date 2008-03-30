// XSOFV1.cpp: Body of the XSOFV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSOFV1.h"
#include <CigiSOFV1.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSOFV1::XSOFV1()
{

}

XSOFV1::~XSOFV1()
{

}


void XSOFV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSOFV1 *InPckt = (CigiSOFV1 *)Packet;


   printf("Start Of Frame V1:\n");
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

}


