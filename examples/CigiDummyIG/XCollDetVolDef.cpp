// XCollDetVolDef.cpp: Body of the XCollDetVolDef class.
//
//////////////////////////////////////////////////////////////////////

#include "XCollDetVolDef.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetVolDef::XCollDetVolDef()
{

}

XCollDetVolDef::~XCollDetVolDef()
{

}


void XCollDetVolDef::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCollDetVolDefV3 *InPckt = (CigiCollDetVolDefV3 *)Packet;

   bool ok = true;

   printf("===> CollDetVolDef <===\n");

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("VolID ==> %d\n",InPckt->GetVolID());
   printf("VolEn ==> %d\n",InPckt->GetVolEn());
   printf("VolType ==> %d\n",InPckt->GetVolType());
   printf("Xoff ==> %f\n",InPckt->GetXoff());
   printf("Yoff ==> %f\n",InPckt->GetYoff());
   printf("Zoff ==> %f\n",InPckt->GetZoff());
   printf("HeightOrRadius ==> %f\n",InPckt->GetHeightOrRadius());
   printf("Width ==> %f\n",InPckt->GetWidth());
   printf("Depth ==> %f\n",InPckt->GetDepth());
   printf("Roll ==> %f\n",InPckt->GetRoll());
   printf("Pitch ==> %f\n",InPckt->GetPitch());
   printf("Yaw ==> %f\n",InPckt->GetYaw());


}
