// XWeatherCtrlV3.cpp: Body of the XWeatherCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XWeatherCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XWeatherCtrlV3::XWeatherCtrlV3()
{

}

XWeatherCtrlV3::~XWeatherCtrlV3()
{

}


void XWeatherCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiWeatherCtrlV3 *InPckt = (CigiWeatherCtrlV3 *)Packet;

   printf("Weather Control:\n");

   printf("\tID = %d\n",InPckt->GetEntityID());
   printf("\tLayer ID = %d\n",InPckt->GetLayerID());
   printf("\tHumidity = %d\n",InPckt->GetHumidity());
   printf("\tWeather Enable = %d\n",InPckt->GetWeatherEn());
   printf("\tScud Enable = %d\n",InPckt->GetScudEn());
   printf("\tRandom Winds Enable = %d\n",InPckt->GetRandomWindsEn());
   printf("\tRandom Lightning Enable = %d\n",InPckt->GetRandomLightningEn());

   printf("\tCloud Type = %d : ",InPckt->GetCloudType());
   switch(InPckt->GetCloudType())
   {
   case 0:
      printf("None\n");
      break;
   case 1:
      printf("Altocumulus\n");
      break;
   case 2:
      printf("Altostratus\n");
      break;
   case 3:
      printf("Cirrocumulus\n");
      break;
   case 4:
      printf("Cirrostratus\n");
      break;
   case 5:
      printf("Cirrus\n");
      break;
   case 6:
      printf("Cumulonimbus\n");
      break;
   case 7:
      printf("Cumulus\n");
      break;
   case 8:
      printf("Nimbostratus\n");
      break;
   case 9:
      printf("Stratocumulus\n");
      break;
   case 10:
      printf("Stratus\n");
      break;
   case 11:
      printf("DefA\n");
      break;
   case 12:
      printf("DefB\n");
      break;
   case 13:
      printf("DefC\n");
      break;
   case 14:
      printf("DefD\n");
      break;
   case 15:
      printf("DefE\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tScope = %d : ",InPckt->GetScope());
   switch(InPckt->GetScope())
   {
   case 0:
      printf("Global\n");
      break;
   case 1:
      printf("Regional\n");
      break;
   case 2:
      printf("Entity\n");
      break;
   default:
      printf("\n");
      break;
   }


   printf("\tSeverity = %d\n",InPckt->GetSeverity());
   printf("\tAir Temperature = %f\n",InPckt->GetAirTemp());
   printf("\tVisibility Range = %f\n",InPckt->GetVisibilityRng());
   printf("\tScud Frequency = %f\n",InPckt->GetScudFreq());
   printf("\tCoverage = %f\n",InPckt->GetCoverage());
   printf("\tBase Elevation = %f\n",InPckt->GetBaseElev());
   printf("\tThickness = %f\n",InPckt->GetThickness());
   printf("\tTransition = %f\n",InPckt->GetTransition());
   printf("\tHorizontal Wind Speed = %f\n",InPckt->GetHorizWindSp());
   printf("\tVertical Wind Speed = %f\n",InPckt->GetVertWindSp());
   printf("\tWind Direction = %f\n",InPckt->GetWindDir());
   printf("\tBarometric Pressure = %f\n",InPckt->GetBaroPress());
   printf("\tAerosol = %f\n",InPckt->GetAerosol());


}
