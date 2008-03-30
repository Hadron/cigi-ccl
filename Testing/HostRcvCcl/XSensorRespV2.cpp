// XSensorRespV2.cpp: Body of the XSensorRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSensorRespV2.h"
#include <CigiSensorRespV2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSensorRespV2::XSensorRespV2()
{

}

XSensorRespV2::~XSensorRespV2()
{

}


void XSensorRespV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSensorRespV2 *InPckt = (CigiSensorRespV2 *)Packet;


   printf("Sensor Response V2:\n");
   printf("\tView ID = %u\n",InPckt->GetViewID());
   printf("\tSensor ID = %u\n",InPckt->GetSensorID());

   printf("\tSensor Status = %d : ",InPckt->GetSensorStat());
   switch(InPckt->GetSensorStat())
   {
   case 0:
      printf("Searching\n");
      break;
   case 1:
      printf("Tracking\n");
      break;
   case 2:
      printf("NearBrakeLock\n");
      break;
   case 3:
      printf("BrakeLock\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tGate Size X = %u\n",InPckt->GetGateSzX());
   printf("\tGate Size Y = %u\n",InPckt->GetGateSzY());
   printf("\tGate X offset = %f\n",InPckt->GetGateXoff());
   printf("\tGate Y offset = %f\n",InPckt->GetGateYoff());

}


