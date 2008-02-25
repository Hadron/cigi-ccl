// XViewDef.cpp: Body of the XViewDef class.
//
//////////////////////////////////////////////////////////////////////

#include "XViewDef.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XViewDef::XViewDef()
{

}

XViewDef::~XViewDef()
{

}


void XViewDef::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiViewDefV3 *InPckt = (CigiViewDefV3 *)Packet;

   printf("===> ViewDef <===\n");

   printf("ViewID ==> %d\n",InPckt->GetViewID());
   printf("GroupID ==> %d\n",InPckt->GetGroupID());
   printf("FOVNearEn ==> %d\n",InPckt->GetFOVNearEn());
   printf("FOVFarEn ==> %d\n",InPckt->GetFOVFarEn());
   printf("FOVLeftEn ==> %d\n",InPckt->GetFOVLeftEn());
   printf("FOVRightEn ==> %d\n",InPckt->GetFOVRightEn());
   printf("FOVTopEn ==> %d\n",InPckt->GetFOVTopEn());
   printf("FOVBottomEn ==> %d\n",InPckt->GetFOVBottomEn());
   printf("MirrorMode ==> %d\n",InPckt->GetMirrorMode());
   printf("PixelReplicateMode ==> %d\n",InPckt->GetPixelReplicateMode());
   printf("ProjectionType ==> %d\n",InPckt->GetProjectionType());
   printf("Reorder ==> %d\n",InPckt->GetReorder());
   printf("ViewType ==> %d\n",InPckt->GetViewType());
   printf("FOVNear ==> %f\n",InPckt->GetFOVNear());
   printf("FOVFar ==> %f\n",InPckt->GetFOVFar());
   printf("FOVLeft ==> %f\n",InPckt->GetFOVLeft());
   printf("FOVRight ==> %f\n",InPckt->GetFOVRight());
   printf("FOVTop ==> %f\n",InPckt->GetFOVTop());
   printf("FOVBottom ==> %f\n",InPckt->GetFOVBottom());


}
