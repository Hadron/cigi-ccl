// XCollDetVolDefV2.cpp: Body of the XCollDetVolDefV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetVolDefV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetVolDefV2::XCollDetVolDefV2()
{

}

XCollDetVolDefV2::~XCollDetVolDefV2()
{

}


void XCollDetVolDefV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetVolDefV2 *InPckt = (CigiCollDetVolDefV2 *)Packet;

   bool ok = true;

   printf("Collision Detection Volume Definition:\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tVolume ID = %d\n",InPckt->GetVolID());
   printf("\tVolume Enable = %d\n",InPckt->GetVolEn());

   printf("\tX Offset = %f\n",InPckt->GetXoff());
   printf("\tY Offset = %f\n",InPckt->GetYoff());
   printf("\tZ Offset = %f\n",InPckt->GetZoff());
   printf("\tHeight or Radius = %f\n",InPckt->GetHeightOrRadius());
   printf("\tWidth = %f\n",InPckt->GetWidth());
   printf("\tDepth = %f\n",InPckt->GetDepth());


}
