// XCollDetSegRespV2.cpp: Body of the XCollDetSegRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetSegRespV2.h"
#include <CigiCollDetSegRespV2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetSegRespV2::XCollDetSegRespV2()
{

}

XCollDetSegRespV2::~XCollDetSegRespV2()
{

}


void XCollDetSegRespV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetSegRespV2 *InPckt = (CigiCollDetSegRespV2 *)Packet;


   printf("Collision Detection Segment Response V2:\n");
   printf("\tEntity ID = %u\n",InPckt->GetEntityID());
   printf("\tSegment ID = %u\n",InPckt->GetSegID());

   printf("\tCollision Type = %d : ",InPckt->GetCollType());
   switch(InPckt->GetCollType())
   {
   case 0:
      printf("NonEntity\n");
      break;
   case 1:
      printf("Entity\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tCollision Entity ID = %u\n",InPckt->GetCollEntityID());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tX = %f\n",InPckt->GetX());
   printf("\tY = %f\n",InPckt->GetY());
   printf("\tZ = %f\n",InPckt->GetZ());

}


