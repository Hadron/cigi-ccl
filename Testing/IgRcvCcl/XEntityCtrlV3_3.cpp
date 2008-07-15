// XEntityCtrlV3_3.cpp: Body of the XEntityCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEntityCtrlV3_3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEntityCtrlV3_3::XEntityCtrlV3_3()
{

}

XEntityCtrlV3_3::~XEntityCtrlV3_3()
{

}


void XEntityCtrlV3_3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEntityCtrlV3_3 *InPckt = (CigiEntityCtrlV3_3 *)Packet;

   bool ok = true;

   printf("Entity Control\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());

   printf("\tEntity State = %d : ",InPckt->GetEntityState());
   switch(InPckt->GetEntityState())
   {
   case 0:
      printf("Standby\n");
      break;
   case 1:
      printf("Active\n");
      break;
   case 2:
      printf("Remove\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tAttach State = %d : ",InPckt->GetAttachState());
   switch(InPckt->GetAttachState())
   {
   case 0:
      printf("Detach\n");
      break;
   case 1:
      printf("Attach\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tCollision Detection Enable = %d : ",InPckt->GetCollisionDetectEn());
   switch(InPckt->GetCollisionDetectEn())
   {
   case 0:
      printf("Disable\n");
      break;
   case 1:
      printf("Enable\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tInherit Alpha = %d : ",InPckt->GetInheritAlpha());
   switch(InPckt->GetCollisionDetectEn())
   {
   case 0:
      printf("NoInherit\n");
      break;
   case 1:
      printf("Inherit\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tGround Clamp = %d : ",InPckt->GetGrndClamp());
   switch(InPckt->GetGrndClamp())
   {
   case 0:
      printf("NoClamp\n");
      break;
   case 1:
      printf("Altitude Clamp\n");
      break;
   case 2:
      printf("Conformal Clamp\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tAnimation Direction = %d : ",InPckt->GetAnimationDir());
   switch(InPckt->GetAnimationDir())
   {
   case 0:
      printf("Forward\n");
      break;
   case 1:
      printf("Backward\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tAnimation Loop Mode = %d : ",InPckt->GetAnimationLoopMode());
   switch(InPckt->GetAnimationLoopMode())
   {
   case 0:
      printf("OneShot\n");
      break;
   case 1:
      printf("Continuous\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tAnimation State = %d : ",InPckt->GetAnimationState());
   switch(InPckt->GetAnimationState())
   {
   case 0:
      printf("Stop\n");
      break;
   case 1:
      printf("Pause\n");
      break;
   case 2:
      printf("Play\n");
      break;
   case 3:
      printf("Continue\n");
      break;
   default:
      printf("\n");
      break;
   }

   if(InPckt->GetSmoothingEn())
      printf("\tSmoothing Enabled\n");
   else
      printf("\tSmoothing Disabled\n");

   printf("\tAlpha = %d\n",InPckt->GetAlpha());
   printf("\tEntity Type = %d\n",InPckt->GetEntityType());
   printf("\tParent ID = %d\n",InPckt->GetParentID());
   printf("\tRoll = %f\n",InPckt->GetRoll());
   printf("\tPitch = %f\n",InPckt->GetPitch());
   printf("\tYaw = %f\n",InPckt->GetYaw());
   printf("\tX Offset = %f\n",InPckt->GetXoff());
   printf("\tY Offset = %f\n",InPckt->GetYoff());
   printf("\tZ Offset = %f\n",InPckt->GetZoff());

}
