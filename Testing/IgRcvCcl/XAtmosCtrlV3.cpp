// XAtmosCtrlV3.cpp: Body of the XAtmosCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XAtmosCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XAtmosCtrlV3::XAtmosCtrlV3()
{

}

XAtmosCtrlV3::~XAtmosCtrlV3()
{

}


void XAtmosCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiAtmosCtrlV3 *InPckt = (CigiAtmosCtrlV3 *)Packet;

   printf("Atmosphere Control:\n");

   printf("\tAtmosphere Enable = %d\n",InPckt->GetAtmosEn());
   printf("\tHumidity = %d\n",InPckt->GetHumidity());
   printf("\tAir Temperature = %f\n",InPckt->GetAirTemp());
   printf("\tVisibility = %f\n",InPckt->GetVisibility());
   printf("\tHorizontal Wind Speed = %f\n",InPckt->GetHorizWindSp());
   printf("\tVertical Wind Speed = %f\n",InPckt->GetVertWindSp());
   printf("\tWind Direction = %f\n",InPckt->GetWindDir());
   printf("\tBarometric Pressure = %f\n",InPckt->GetBaroPress());

}
