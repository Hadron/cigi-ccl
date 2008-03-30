// XEnvCtrlV1.cpp: Body of the XEnvCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEnvCtrlV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEnvCtrlV1::XEnvCtrlV1()
{

}

XEnvCtrlV1::~XEnvCtrlV1()
{

}


void XEnvCtrlV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEnvCtrlV1 *InPckt = (CigiEnvCtrlV1 *)Packet;

   printf("Environmental Control:\n");

   printf("\tHour = %d\n",InPckt->GetHour());
   printf("\tMinute = %d\n",InPckt->GetMinute());
   printf("\tEphemeris Enable = %d\n",InPckt->GetEphemerisEn());
   printf("\tHumidity = %d\n",InPckt->GetHumidity());
   printf("\tMonth = %d\n",InPckt->GetMonth());
   printf("\tDay = %d\n",InPckt->GetDay());
   printf("\tYear = %d\n",InPckt->GetYear());
   printf("\tAir Temperature = %f\n",InPckt->GetAirTemp());
   printf("\tVisibility = %f\n",InPckt->GetVisibility());
   printf("\tHorizontal Wind Speed = %f\n",InPckt->GetHorizWindSp());
   printf("\tWind Direction = %f\n",InPckt->GetWindDir());

}
