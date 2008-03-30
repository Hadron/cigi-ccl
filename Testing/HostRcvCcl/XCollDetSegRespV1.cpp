// XCollDetSegRespV1.cpp: Body of the XCollDetSegRespV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetSegRespV1.h"
#include <CigiCollDetSegRespV1.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetSegRespV1::XCollDetSegRespV1()
{

}

XCollDetSegRespV1::~XCollDetSegRespV1()
{

}


void XCollDetSegRespV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetSegRespV1 *InPckt = (CigiCollDetSegRespV1 *)Packet;


   printf("Collision Detection Segment Response V1:\n");
   printf("\tEntity ID = %u\n",InPckt->GetEntityID());
   printf("\tSegment ID = %u\n",InPckt->GetSegID());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tX = %f\n",InPckt->GetX());
   printf("\tY = %f\n",InPckt->GetY());
   printf("\tZ = %f\n",InPckt->GetZ());

}


