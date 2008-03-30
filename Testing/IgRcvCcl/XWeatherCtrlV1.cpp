// XWeatherCtrlV1.cpp: Body of the XWeatherCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XWeatherCtrlV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XWeatherCtrlV1::XWeatherCtrlV1()
{

}

XWeatherCtrlV1::~XWeatherCtrlV1()
{

}


void XWeatherCtrlV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiWeatherCtrlV1 *InPckt = (CigiWeatherCtrlV1 *)Packet;

   printf("Weather Control:\n");

   printf("\tID = %d\n",InPckt->GetEntityID());
   printf("\tWeather Enable = %d\n",InPckt->GetWeatherEn());
   printf("\tScud Enable = %d\n",InPckt->GetScudEn());
   printf("\tRandom Winds Enable = %d\n",InPckt->GetRandomWindsEn());
   printf("\tSeverity = %d\n",InPckt->GetSeverity());
   printf("\tPhenomenon Type = %d\n",InPckt->GetPhenomenonType());
   printf("\tAir Temperature = %f\n",InPckt->GetAirTemp());
   printf("\tOpacity = %f\n",InPckt->GetOpacity());
   printf("\tScud Frequency = %f\n",InPckt->GetScudFreq());
   printf("\tCoverage = %f\n",InPckt->GetCoverage());
   printf("\tBase Elevation = %f\n",InPckt->GetBaseElev());
   printf("\tThickness = %f\n",InPckt->GetThickness());
   printf("\tTransition = %f\n",InPckt->GetTransition());
   printf("\tHorizontal Wind Speed = %f\n",InPckt->GetHorizWindSp());
   printf("\tWind Direction = %f\n",InPckt->GetWindDir());

}
