// XEntityCtrlV1.cpp: Body of the XEntityCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEntityCtrlV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEntityCtrlV1::XEntityCtrlV1()
{

}

XEntityCtrlV1::~XEntityCtrlV1()
{

}


void XEntityCtrlV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEntityCtrlV1 *InPckt = (CigiEntityCtrlV1 *)Packet;

   bool ok = true;

   printf("Entity Control\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());

   printf("\tEntity State = %d : ",InPckt->GetEntityState());
   switch(InPckt->GetEntityState())
   {
   case 0:
      printf("DestructV1\n");
      break;
   case 1:
      printf("ConstructV1\n");
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
      printf("NoActionV1\n");
      break;
   case 1:
      printf("LoadV1\n");
      break;
   case 2:
      printf("LoadActivateV1\n");
      break;
   case 3:
      printf("ActivateV1\n");
      break;
   case 4:
      printf("DeactivateV1\n");
      break;
   case 5:
      printf("DeactivateUnloadV1\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tEntity Type = %d\n",InPckt->GetEntityType());
   printf("\tParent ID = %d\n",InPckt->GetParentID());
   printf("\tTemperature = %f\n",InPckt->GetTemp());
   printf("\tRoll = %f\n",InPckt->GetRoll());
   printf("\tPitch = %f\n",InPckt->GetPitch());
   printf("\tHeading = %f\n",InPckt->GetHeading());
   printf("\tX Offset = %f\n",InPckt->GetXoff());
   printf("\tY Offset = %f\n",InPckt->GetYoff());
   printf("\tZ Offset = %f\n",InPckt->GetZoff());

}
