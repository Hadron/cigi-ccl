// XHotReqV2.cpp: Body of the XHotReqV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHotReqV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHotReqV2::XHotReqV2()
{

}

XHotReqV2::~XHotReqV2()
{

}


void XHotReqV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHotReqV2 *InPckt = (CigiHotReqV2 *)Packet;

   bool ok = true;

   printf("Hot Request:\n");
   printf("\tLatitude = %f\n",InPckt->GetLat());
   printf("\tLongitude = %f\n",InPckt->GetLon());

}

