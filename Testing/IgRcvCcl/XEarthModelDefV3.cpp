// XEarthModelDefV3.cpp: Body of the XEarthModelDefV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEarthModelDefV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEarthModelDefV3::XEarthModelDefV3()
{

}

XEarthModelDefV3::~XEarthModelDefV3()
{

}


void XEarthModelDefV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEarthModelDefV3 *InPckt = (CigiEarthModelDefV3 *)Packet;

   bool ok = true;

   printf("Earth Reference Model Definition:\n");

   printf("\tCustom Earth Reference Model Enable = %d\n",InPckt->GetCustomERMEn());
   printf("\tEquatorial Radius = %f\n",InPckt->GetEquatorialRadius());
   printf("\tFlattening = %f\n",InPckt->GetFlattening());

}
