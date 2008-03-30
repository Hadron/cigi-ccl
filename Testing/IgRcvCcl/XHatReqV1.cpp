// XHatReqV1.cpp: Body of the XHatReqV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatReqV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatReqV1::XHatReqV1()
{

}

XHatReqV1::~XHatReqV1()
{

}


void XHatReqV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatReqV1 *InPckt = (CigiHatReqV1 *)Packet;

   bool ok = true;

   printf("Hat Request:\n");

   printf("\tHat ID = %d\n",InPckt->GetHatHotID());
   printf("\tLatitude = %f\n",InPckt->GetLat());
   printf("\tLongitude = %f\n",InPckt->GetLon());
   printf("\tAltitude = %f\n",InPckt->GetAlt());

}

