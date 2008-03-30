// XSensorRespV3.cpp: Body of the XSensorRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSensorRespV3.h"
#include <CigiSensorRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSensorRespV3::XSensorRespV3()
{

}

XSensorRespV3::~XSensorRespV3()
{

}


void XSensorRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSensorRespV3 *InPckt = (CigiSensorRespV3 *)Packet;


   printf("Sensor Response V3:\n");
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
   printf("\tFrame Counter = %u\n",InPckt->GetFrameCntr());

}


