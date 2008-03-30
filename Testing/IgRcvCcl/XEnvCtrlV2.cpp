// XEnvCtrlV2.cpp: Body of the XEnvCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEnvCtrlV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEnvCtrlV2::XEnvCtrlV2()
{

}

XEnvCtrlV2::~XEnvCtrlV2()
{

}


void XEnvCtrlV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEnvCtrlV2 *InPckt = (CigiEnvCtrlV2 *)Packet;

   printf("Environmental Control:\n");

   printf("\tHour = %d\n",InPckt->GetHour());
   printf("\tMinute = %d\n",InPckt->GetMinute());
   printf("\tEphemeris Enable = %d\n",InPckt->GetEphemerisEn());
   printf("\tAtmosphere Enable = %d\n",InPckt->GetAtmosEn());
   printf("\tHumidity = %d\n",InPckt->GetHumidity());
   printf("\tMonth = %d\n",InPckt->GetMonth());
   printf("\tDay = %d\n",InPckt->GetDay());
   printf("\tYear = %d\n",InPckt->GetYear());
   printf("\tAir Temperature = %f\n",InPckt->GetAirTemp());
   printf("\tVisibility = %f\n",InPckt->GetVisibility());
   printf("\tHorizontal Wind Speed = %f\n",InPckt->GetHorizWindSp());
   printf("\tWind Direction = %f\n",InPckt->GetWindDir());
   printf("\tBarometric Pressure = %f\n",InPckt->GetBaroPress());
   printf("\tAerosol = %f\n",InPckt->GetAerosol());

}
