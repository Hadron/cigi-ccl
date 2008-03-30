// XMotionTrackCtrl.cpp: Body of the XMotionTrackCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XMotionTrackCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XMotionTrackCtrl::XMotionTrackCtrl()
{

}

XMotionTrackCtrl::~XMotionTrackCtrl()
{

}


void XMotionTrackCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiMotionTrackCtrlV3 *InPckt = (CigiMotionTrackCtrlV3 *)Packet;

   bool ok = true;

   printf("===> MotionTrackCtrl <===\n");

   printf("ViewID ==> %d\n",InPckt->GetViewID());
   printf("TrackerID ==> %d\n",InPckt->GetTrackerID());
   printf("TrackerEn ==> %d\n",InPckt->GetTrackerEn());
   printf("BoresightEn ==> %d\n",InPckt->GetBoresightEn());
   printf("XEn ==> %d\n",InPckt->GetXEn());
   printf("YEn ==> %d\n",InPckt->GetYEn());
   printf("ZEn ==> %d\n",InPckt->GetZEn());
   printf("RollEn ==> %d\n",InPckt->GetRollEn());
   printf("PitchEn ==> %d\n",InPckt->GetPitchEn());
   printf("YawEn ==> %d\n",InPckt->GetYawEn());
   printf("Scope ==> %d\n",InPckt->GetScope());


}
