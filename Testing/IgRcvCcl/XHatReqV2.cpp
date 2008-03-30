// XHatReqV2.cpp: Body of the XHatReqV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatReqV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatReqV2::XHatReqV2()
{

}

XHatReqV2::~XHatReqV2()
{

}


void XHatReqV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatReqV2 *InPckt = (CigiHatReqV2 *)Packet;

   bool ok = true;

   printf("Hat Request:\n");

   printf("\tHat ID = %d\n",InPckt->GetHatHotID());
   printf("\tLatitude = %f\n",InPckt->GetLat());
   printf("\tLongitude = %f\n",InPckt->GetLon());
   printf("\tAltitude = %f\n",InPckt->GetAlt());

}

