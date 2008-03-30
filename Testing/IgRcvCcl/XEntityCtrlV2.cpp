// XEntityCtrlV2.cpp: Body of the XEntityCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEntityCtrlV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEntityCtrlV2::XEntityCtrlV2()
{

}

XEntityCtrlV2::~XEntityCtrlV2()
{

}


void XEntityCtrlV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEntityCtrlV2 *InPckt = (CigiEntityCtrlV2 *)Packet;

   bool ok = true;

   printf("Entity Control\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());

   printf("\tEntity State = %d : ",InPckt->GetEntityState());
   switch(InPckt->GetEntityState())
   {
   case 0:
      printf("LoadHideV2\n");
      break;
   case 1:
      printf("LoadShowV2\n");
      break;
   case 2:
      printf("UnloadV2\n");
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

   printf("\tAnimation State = %d : ",InPckt->GetEffectState());
   switch(InPckt->GetEffectState())
   {
   case 0:
      printf("StopV2\n");
      break;
   case 1:
      printf("PlayV2\n");
      break;
   case 2:
      printf("RestartV2\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tEntity Type = %d\n",InPckt->GetEntityType());
   printf("\tParent ID = %d\n",InPckt->GetParentID());
   printf("\tOpacity = %f\n",InPckt->GetOpacity());
   printf("\tTemperature = %f\n",InPckt->GetTemp());
   printf("\tRoll = %f\n",InPckt->GetRoll());
   printf("\tPitch = %f\n",InPckt->GetPitch());
   printf("\tHeading = %f\n",InPckt->GetHeading());
   printf("\tX Offset = %f\n",InPckt->GetXoff());
   printf("\tY Offset = %f\n",InPckt->GetYoff());
   printf("\tZ Offset = %f\n",InPckt->GetZoff());

}
