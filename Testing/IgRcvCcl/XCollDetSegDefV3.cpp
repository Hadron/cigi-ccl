// XCollDetSegDefV3.cpp: Body of the XCollDetSegDefV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetSegDefV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetSegDefV3::XCollDetSegDefV3()
{

}

XCollDetSegDefV3::~XCollDetSegDefV3()
{

}


void XCollDetSegDefV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetSegDefV3 *InPckt = (CigiCollDetSegDefV3 *)Packet;

   printf("Collision Detection Segment Definition:\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tSegment ID = %d\n",InPckt->GetSegmentID());
   printf("\tSegment Enable = %d\n",InPckt->GetSegmentEn());
   printf("\tStart X = %f\n",InPckt->GetX1());
   printf("\tStart Y = %f\n",InPckt->GetY1());
   printf("\tStart Z = %f\n",InPckt->GetZ1());
   printf("\tEnding X = %f\n",InPckt->GetX2());
   printf("\tEnding Y = %f\n",InPckt->GetY2());
   printf("\tEnding Z = %f\n",InPckt->GetZ2());
   printf("\tMask = %d\n",InPckt->GetMask());


}
