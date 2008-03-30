// XCollDetSegDef.cpp: Body of the XCollDetSegDef class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetSegDef.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetSegDef::XCollDetSegDef()
{

}

XCollDetSegDef::~XCollDetSegDef()
{

}


void XCollDetSegDef::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetSegDefV3 *InPckt = (CigiCollDetSegDefV3 *)Packet;

   printf("===> CollDetSegDef <===\n");

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("SegmentID ==> %d\n",InPckt->GetSegmentID());
   printf("SegmentEn ==> %d\n",InPckt->GetSegmentEn());
   printf("X1 ==> %f\n",InPckt->GetX1());
   printf("Y1 ==> %f\n",InPckt->GetY1());
   printf("Z1 ==> %f\n",InPckt->GetZ1());
   printf("X2 ==> %f\n",InPckt->GetX2());
   printf("Y2 ==> %f\n",InPckt->GetY2());
   printf("Z2 ==> %f\n",InPckt->GetZ2());
   printf("Mask ==> %d\n",InPckt->GetMask());


}
