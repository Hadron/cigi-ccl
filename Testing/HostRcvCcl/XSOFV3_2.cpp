// XSOFV3_2.cpp: Body of the XSOFV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSOFV3_2.h"
#include <CigiSOFV3_2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSOFV3_2::XSOFV3_2()
{

}

XSOFV3_2::~XSOFV3_2()
{

}


void XSOFV3_2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSOFV3_2 *InPckt = (CigiSOFV3_2 *)Packet;


   printf("Start Of Frame V3_2:\n");
   printf("\tDatabase ID = %u\n",InPckt->GetDatabaseID());
   printf("\tIG Status = %u\n",InPckt->GetIGStatus());

   printf("\tIG Mode = %d : ",InPckt->GetIGMode());
   switch(InPckt->GetIGMode())
   {
   case 0:
      printf("Reset\n");
      break;
   case 1:
      printf("Standby\n");
      break;
   case 2:
      printf("Operate\n");
      break;
   case 3:
      printf("debug\n");
      break;
   case 4:
      printf("OfflineMaint\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tTime Stamp Valid = %d\n",InPckt->GetTimeStampValid());

   printf("\tEarth Reference Model = %d : ",InPckt->GetEarthRefModel());
   switch(InPckt->GetEarthRefModel())
   {
   case 0:
      printf("WGS84\n");
      break;
   case 1:
      printf("HostDefined\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tFrame Counter = %u\n",InPckt->GetFrameCntr());
   printf("\tTime Stamp = %u\n",InPckt->GetTimeStamp());
   printf("\tLast Received Host Frame = %u\n",InPckt->GetLastRcvdHostFrame());

}


