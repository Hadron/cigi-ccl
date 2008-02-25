// XEntityCtrl.cpp: Body of the XEntityCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XEntityCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEntityCtrl::XEntityCtrl()
{

}

XEntityCtrl::~XEntityCtrl()
{

}


void XEntityCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEntityCtrlV3 *InPckt = (CigiEntityCtrlV3 *)Packet;

   bool ok = true;

   printf("===> EntityCtrl <===\n");

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("EntityState ==> %d\n",InPckt->GetEntityState());
   printf("AttachState ==> %d\n",InPckt->GetAttachState());
   printf("CollisionDetectEn ==> %d\n",InPckt->GetCollisionDetectEn());
   printf("InheritAlpha ==> %d\n",InPckt->GetInheritAlpha());
   printf("GrndClamp ==> %d\n",InPckt->GetGrndClamp());
   printf("AnimationDir ==> %d\n",InPckt->GetAnimationDir());
   printf("AnimationLoopMode ==> %d\n",InPckt->GetAnimationLoopMode());
   printf("AnimationState ==> %d\n",InPckt->GetAnimationState());
   printf("Alpha ==> %d\n",InPckt->GetAlpha());
   printf("EntityType ==> %d\n",InPckt->GetEntityType());
   printf("ParentID ==> %d\n",InPckt->GetParentID());
   printf("Roll ==> %f\n",InPckt->GetRoll());
   printf("Pitch ==> %f\n",InPckt->GetPitch());
   printf("Yaw ==> %f\n",InPckt->GetYaw());
   printf("Xoff ==> %f\n",InPckt->GetXoff());
   printf("Yoff ==> %f\n",InPckt->GetYoff());
   printf("Zoff ==> %f\n",InPckt->GetZoff());


}
