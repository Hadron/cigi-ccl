// XCollDetVolDefV3.cpp: Body of the XCollDetVolDefV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetVolDefV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetVolDefV3::XCollDetVolDefV3()
{

}

XCollDetVolDefV3::~XCollDetVolDefV3()
{

}


void XCollDetVolDefV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetVolDefV3 *InPckt = (CigiCollDetVolDefV3 *)Packet;

   bool ok = true;

   printf("Collision Detection Volume Definition:\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tVolume ID = %d\n",InPckt->GetVolID());
   printf("\tVolume Enable = %d\n",InPckt->GetVolEn());

   printf("\tVolume Type = %d : ",InPckt->GetVolType());
   switch(InPckt->GetVolType())
   {
   case 0:
      printf("Sphere\n");
      break;
   case 1:
      printf("Cuboid\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tX Offset = %f\n",InPckt->GetXoff());
   printf("\tY Offset = %f\n",InPckt->GetYoff());
   printf("\tZ Offset = %f\n",InPckt->GetZoff());
   printf("\tHeight or Radius = %f\n",InPckt->GetHeightOrRadius());
   printf("\tWidth = %f\n",InPckt->GetWidth());
   printf("\tDepth = %f\n",InPckt->GetDepth());
   printf("\tRoll = %f\n",InPckt->GetRoll());
   printf("\tPitch = %f\n",InPckt->GetPitch());
   printf("\tYaw = %f\n",InPckt->GetYaw());


}
