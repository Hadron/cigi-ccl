// XCollDetVolRespV2.cpp: Body of the XCollDetVolRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetVolRespV2.h"
#include <CigiCollDetVolRespV2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetVolRespV2::XCollDetVolRespV2()
{

}

XCollDetVolRespV2::~XCollDetVolRespV2()
{

}


void XCollDetVolRespV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetVolRespV2 *InPckt = (CigiCollDetVolRespV2 *)Packet;


   printf("Collision Detection Volume Response V2:\n");
   printf("\tEntity ID = %u\n",InPckt->GetEntityID());
   printf("\tVolume ID = %u\n",InPckt->GetVolID());

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

}


