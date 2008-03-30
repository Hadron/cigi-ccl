// XCelestialCtrlV3.cpp: Body of the XCelestialCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCelestialCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCelestialCtrlV3::XCelestialCtrlV3()
{

}

XCelestialCtrlV3::~XCelestialCtrlV3()
{

}


void XCelestialCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCelestialCtrlV3 *InPckt = (CigiCelestialCtrlV3 *)Packet;

   printf("Celestial Control:\n");

   printf("\tHour = %d\n",InPckt->GetHour());
   printf("\tMinute = %d\n",InPckt->GetMinute());
   printf("\tEphemeris Enable = %d\n",InPckt->GetEphemerisEn());
   printf("\tSun Enable = %d\n",InPckt->GetSunEn());
   printf("\tMoon Enable = %d\n",InPckt->GetMoonEn());
   printf("\tStar Enable = %d\n",InPckt->GetStarEn());
   printf("\tDate Valid = %d\n",InPckt->GetDateVld());
   printf("\tMonth = %d\n",InPckt->GetMonth());
   printf("\tDay = %d\n",InPckt->GetDay());
   printf("\tYear = %d\n",InPckt->GetYear());
   printf("\tStar Intensity = %f\n",InPckt->GetStarInt());

}
