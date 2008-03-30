// XSensorXRespV3.cpp: Body of the XSensorXRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSensorXRespV3.h"
#include <CigiSensorXRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSensorXRespV3::XSensorXRespV3()
{

}

XSensorXRespV3::~XSensorXRespV3()
{

}


void XSensorXRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSensorXRespV3 *InPckt = (CigiSensorXRespV3 *)Packet;


   printf("Sensor Extended Response V3:\n");
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

   printf("\tEntity Target = %d\n",InPckt->GetEntityTgt());
   printf("\tEntity ID = %u\n",InPckt->GetEntityID());
   printf("\tGate Size X = %u\n",InPckt->GetGateSzX());
   printf("\tGate Size Y = %u\n",InPckt->GetGateSzY());
   printf("\tGate X offset = %f\n",InPckt->GetGateXoff());
   printf("\tGate Y offset = %f\n",InPckt->GetGateYoff());
   printf("\tFrame Counter = %u\n",InPckt->GetFrameCntr());
   printf("\tTrack Point Latitude = %f\n",InPckt->GetTrackPntLat());
   printf("\tTrack Point Longitude = %f\n",InPckt->GetTrackPntLon());
   printf("\tTrack Point Altitude = %f\n",InPckt->GetTrackPntAlt());

}


