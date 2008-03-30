// XMotionTrackCtrlV3.cpp: Body of the XMotionTrackCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XMotionTrackCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XMotionTrackCtrlV3::XMotionTrackCtrlV3()
{

}

XMotionTrackCtrlV3::~XMotionTrackCtrlV3()
{

}


void XMotionTrackCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiMotionTrackCtrlV3 *InPckt = (CigiMotionTrackCtrlV3 *)Packet;

   bool ok = true;

   printf("Motion Tracker Control:\n");

   printf("\tView ID = %d\n",InPckt->GetViewID());
   printf("\tTracker ID = %d\n",InPckt->GetTrackerID());
   printf("\tTracker Enable = %d\n",InPckt->GetTrackerEn());
   printf("\tBoresight Enable = %d\n",InPckt->GetBoresightEn());
   printf("\tX Enable = %d\n",InPckt->GetXEn());
   printf("\tY Enable = %d\n",InPckt->GetYEn());
   printf("\tZ Enable = %d\n",InPckt->GetZEn());
   printf("\tRoll Enable = %d\n",InPckt->GetRollEn());
   printf("\tPitch Enable = %d\n",InPckt->GetPitchEn());
   printf("\tYaw Enable = %d\n",InPckt->GetYawEn());

   printf("\tScope = %d : ",InPckt->GetScope());
   switch(InPckt->GetScope())
   {
   case 0:
      printf("View\n");
      break;
   case 1:
      printf("ViewGrp\n");
      break;
   default:
      printf("\n");
      break;
   }

}
