// XAtmosCtrl.cpp: Body of the XAtmosCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XAtmosCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XAtmosCtrl::XAtmosCtrl()
{

}

XAtmosCtrl::~XAtmosCtrl()
{

}


void XAtmosCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiAtmosCtrlV3 *InPckt = (CigiAtmosCtrlV3 *)Packet;

   printf("===> AtmosCtrl <===\n");

   printf("AtmosEn ==> %d\n",InPckt->GetAtmosEn());
   printf("Humidity ==> %d\n",InPckt->GetHumidity());
   printf("AirTemp ==> %f\n",InPckt->GetAirTemp());
   printf("Visibility ==> %f\n",InPckt->GetVisibility());
   printf("HorizWindSp ==> %f\n",InPckt->GetHorizWindSp());
   printf("VertWindSp ==> %f\n",InPckt->GetVertWindSp());
   printf("WindDir ==> %f\n",InPckt->GetWindDir());
   printf("BaroPress ==> %f\n",InPckt->GetBaroPress());


}
