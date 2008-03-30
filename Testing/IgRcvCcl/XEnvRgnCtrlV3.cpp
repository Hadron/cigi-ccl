// XEnvRgnCtrlV3.cpp: Body of the XEnvRgnCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEnvRgnCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEnvRgnCtrlV3::XEnvRgnCtrlV3()
{

}

XEnvRgnCtrlV3::~XEnvRgnCtrlV3()
{

}


void XEnvRgnCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEnvRgnCtrlV3 *InPckt = (CigiEnvRgnCtrlV3 *)Packet;

   printf("Environmental Region Control\n");

   printf("\tRegion ID = %d\n",InPckt->GetRegionID());

   printf("\tRegion State = %d : ",InPckt->GetRgnState());
   switch(InPckt->GetRgnState())
   {
   case 0:
      printf("Inactive\n");
      break;
   case 1:
      printf("Active\n");
      break;
   case 2:
      printf("Destroyed\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tWeather Property = %d : ",InPckt->GetWeatherProp());
   switch(InPckt->GetWeatherProp())
   {
   case 0:
      printf("UseLast\n");
      break;
   case 1:
      printf("Merge\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tAerosol = %d : ",InPckt->GetAerosol());
   switch(InPckt->GetAerosol())
   {
   case 0:
      printf("UseLast\n");
      break;
   case 1:
      printf("Merge\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tMaritime Surface = %d : ",InPckt->GetMaritimeSurface());
   switch(InPckt->GetMaritimeSurface())
   {
   case 0:
      printf("UseLast\n");
      break;
   case 1:
      printf("Merge\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tTerrestrial Surface = %d : ",InPckt->GetTerrestrialSurface());
   switch(InPckt->GetTerrestrialSurface())
   {
   case 0:
      printf("UseLast\n");
      break;
   case 1:
      printf("Merge\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tLat = %f\n",InPckt->GetLat());
   printf("\tLon = %f\n",InPckt->GetLon());
   printf("\tX Size = %f\n",InPckt->GetXSize());
   printf("\tY Size = %f\n",InPckt->GetYSize());
   printf("\tCorner Radius = %f\n",InPckt->GetCornerRadius());
   printf("\tRotation = %f\n",InPckt->GetRotation());
   printf("\tTransition = %f\n",InPckt->GetTransition());


}
