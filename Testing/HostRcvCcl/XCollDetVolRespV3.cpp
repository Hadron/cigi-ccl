// XCollDetVolRespV3.cpp: Body of the XCollDetVolRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetVolRespV3.h"
#include <CigiCollDetVolRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetVolRespV3::XCollDetVolRespV3()
{

}

XCollDetVolRespV3::~XCollDetVolRespV3()
{

}


void XCollDetVolRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetVolRespV3 *InPckt = (CigiCollDetVolRespV3 *)Packet;


   printf("Collision Detection Volume Response V3:\n");
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
   printf("\tCollision Volume ID = %u\n",InPckt->GetCollVolID());

}


