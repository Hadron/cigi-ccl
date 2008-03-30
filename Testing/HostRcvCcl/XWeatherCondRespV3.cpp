// XWeatherCondRespV3.cpp: Body of the XWeatherCondRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XWeatherCondRespV3.h"
#include <CigiWeatherCondRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XWeatherCondRespV3::XWeatherCondRespV3()
{

}

XWeatherCondRespV3::~XWeatherCondRespV3()
{

}


void XWeatherCondRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiWeatherCondRespV3 *InPckt = (CigiWeatherCondRespV3 *)Packet;


   printf("Weather Condition Response V3:\n");
   printf("\tRequest ID = %u\n",InPckt->GetRequestID());
   printf("\tHumidity = %u\n",InPckt->GetHumidity());
   printf("\tAir Temperature = %f\n",InPckt->GetAirTemp());
   printf("\tVisibility = %f\n",InPckt->GetVisibility());
   printf("\tHorizontal Wind Speed = %f\n",InPckt->GetHorizWindSp());
   printf("\tVertical Wind Speed = %f\n",InPckt->GetVertWindSp());
   printf("\tWind Direction = %f\n",InPckt->GetWindDir());
   printf("\tBarometric Pressure = %f\n",InPckt->GetBaroPress());

}


