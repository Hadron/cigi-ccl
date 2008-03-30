// XSOFV3.cpp: Body of the XSOFV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSOFV3.h"
#include <CigiSOFV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSOFV3::XSOFV3()
{

}

XSOFV3::~XSOFV3()
{

}


void XSOFV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSOFV3 *InPckt = (CigiSOFV3 *)Packet;


   printf("Start Of Frame V3:\n");
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

}


