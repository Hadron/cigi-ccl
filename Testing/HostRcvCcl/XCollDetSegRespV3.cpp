// XCollDetSegRespV3.cpp: Body of the XCollDetSegRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetSegRespV3.h"
#include <CigiCollDetSegRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetSegRespV3::XCollDetSegRespV3()
{

}

XCollDetSegRespV3::~XCollDetSegRespV3()
{

}


void XCollDetSegRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetSegRespV3 *InPckt = (CigiCollDetSegRespV3 *)Packet;


   printf("Collision Detection Segment Response V3:\n");
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
   printf("\tIntersection Distance = %f\n",InPckt->GetIntersectDist());

}


