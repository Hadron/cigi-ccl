// XWeatherCtrl.cpp: Body of the XWeatherCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XWeatherCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XWeatherCtrl::XWeatherCtrl()
{

}

XWeatherCtrl::~XWeatherCtrl()
{

}


void XWeatherCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiWeatherCtrlV3 *InPckt = (CigiWeatherCtrlV3 *)Packet;

   printf("===> WeatherCtrl.h <===\n");

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("LayerID ==> %d\n",InPckt->GetLayerID());
   printf("Humidity ==> %d\n",InPckt->GetHumidity());
   printf("WeatherEn ==> %d\n",InPckt->GetWeatherEn());
   printf("ScudEn ==> %d\n",InPckt->GetScudEn());
   printf("RandomWindsEn ==> %d\n",InPckt->GetRandomWindsEn());
   printf("RandomLightningEn ==> %d\n",InPckt->GetRandomLightningEn());
   printf("CloudType ==> %d\n",InPckt->GetCloudType());
   printf("Scope ==> %d\n",InPckt->GetScope());
   printf("Severity ==> %d\n",InPckt->GetSeverity());
   printf("AirTemp ==> %f\n",InPckt->GetAirTemp());
   printf("VisibilityRng ==> %f\n",InPckt->GetVisibilityRng());
   printf("ScudFreq ==> %f\n",InPckt->GetScudFreq());
   printf("Coverage ==> %f\n",InPckt->GetCoverage());
   printf("BaseElev ==> %f\n",InPckt->GetBaseElev());
   printf("Thickness ==> %f\n",InPckt->GetThickness());
   printf("Transition ==> %f\n",InPckt->GetTransition());
   printf("HorizWindSp ==> %f\n",InPckt->GetHorizWindSp());
   printf("VertWindSp ==> %f\n",InPckt->GetVertWindSp());
   printf("WindDir ==> %f\n",InPckt->GetWindDir());
   printf("BaroPress ==> %f\n",InPckt->GetBaroPress());
   printf("Aerosol ==> %f\n",InPckt->GetAerosol());


}
