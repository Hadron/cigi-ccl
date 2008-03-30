// XCelestialCtrl.cpp: Body of the XCelestialCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XCelestialCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCelestialCtrl::XCelestialCtrl()
{

}

XCelestialCtrl::~XCelestialCtrl()
{

}


void XCelestialCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCelestialCtrlV3 *InPckt = (CigiCelestialCtrlV3 *)Packet;

   printf("===> CelestialCtrl <===\n");

   printf("Hour ==> %d\n",InPckt->GetHour());
   printf("Minute ==> %d\n",InPckt->GetMinute());
   printf("EphemerisEn ==> %d\n",InPckt->GetEphemerisEn());
   printf("SunEn ==> %d\n",InPckt->GetSunEn());
   printf("MoonEn ==> %d\n",InPckt->GetMoonEn());
   printf("StarEn ==> %d\n",InPckt->GetStarEn());
   printf("DateVld ==> %d\n",InPckt->GetDateVld());
   printf("Month ==> %d\n",InPckt->GetMonth());
   printf("Day ==> %d\n",InPckt->GetDay());
   printf("Year ==> %d\n",InPckt->GetYear());
   printf("StarInt ==> %f\n",InPckt->GetStarInt());


}
