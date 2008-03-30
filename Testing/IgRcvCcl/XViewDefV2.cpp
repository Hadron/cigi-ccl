// XViewDefV2.cpp: Body of the XViewDefV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XViewDefV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XViewDefV2::XViewDefV2()
{

}

XViewDefV2::~XViewDefV2()
{

}


void XViewDefV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiViewDefV2 *InPckt = (CigiViewDefV2 *)Packet;

   printf("View Definition:\n");

   printf("\tView ID = %d\n",InPckt->GetViewID());
   printf("\tGroup ID = %d\n",InPckt->GetGroupID());
   printf("\tView Type = %d\n",InPckt->GetViewType());

   printf("\tReplicate Mode = %d : ",InPckt->GetPixelReplicateMode());
   switch(InPckt->GetPixelReplicateMode())
   {
   case 0:
      printf("ReplicateNone\n");
      break;
   case 1:
      printf("Replicate1x2\n");
      break;
   case 2:
      printf("Replicate2x1\n");
      break;
   case 3:
      printf("Replicate2x2\n");
      break;
   case 4:
      printf("ReplicateDefA\n");
      break;
   case 5:
      printf("ReplicateDefB\n");
      break;
   case 6:
      printf("ReplicateDefC\n");
      break;
   case 7:
      printf("ReplicateDefD\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tMirror Mode = %d : ",InPckt->GetMirrorMode());
   switch(InPckt->GetMirrorMode())
   {
   case 0:
      printf("MirrorNone\n");
      break;
   case 1:
      printf("Horizontal\n");
      break;
   case 2:
      printf("Vertical\n");
      break;
   case 3:
      printf("Horiz_Vert\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tTracker Assigned = %d\n",InPckt->GetTrackerAssigned());
   printf("\tNear FOV Clipping Plane Enable = %d\n",InPckt->GetFOVNearEn());
   printf("\tFar FOV Clipping Plane Enable = %d\n",InPckt->GetFOVFarEn());
   printf("\tLeft FOV Clipping Plane Enable = %d\n",InPckt->GetFOVLeftEn());
   printf("\tRight FOV Clipping Plane Enable = %d\n",InPckt->GetFOVRightEn());
   printf("\tTop FOV Clipping Plane Enable = %d\n",InPckt->GetFOVTopEn());
   printf("\tBottom FOV Clipping Plane Enable = %d\n",InPckt->GetFOVBottomEn());
   printf("\tNear FOV Clipping Plane = %f\n",InPckt->GetFOVNear());
   printf("\tFar FOV Clipping Plane = %f\n",InPckt->GetFOVFar());
   printf("\tLeft FOV Clipping Plane = %f\n",InPckt->GetFOVLeft());
   printf("\tRight FOV Clipping Plane = %f\n",InPckt->GetFOVRight());
   printf("\tTop FOV Clipping Plane = %f\n",InPckt->GetFOVTop());
   printf("\tBottom FOV Clipping Plane = %f\n",InPckt->GetFOVBottom());


}
