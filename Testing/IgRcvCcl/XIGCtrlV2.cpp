// XIGCtrlV2.cpp: Body of the XIGCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XIGCtrlV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGCtrlV2::XIGCtrlV2()
{

}

XIGCtrlV2::~XIGCtrlV2()
{

}


void XIGCtrlV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiIGCtrlV2 *InPckt = (CigiIGCtrlV2 *)Packet;

   bool ok = true;

   printf("IGCtrl\n");

   printf("Version ==> %d\n",InPckt->GetVersion());
   printf("DatabaseID ==> %d\n",InPckt->GetDatabaseID());
   printf("IGMode ==> %d\n",InPckt->GetIGMode());
   printf("Tracking Device Enable V2 ==> %d\n",InPckt->GetTrackDeviceEn());
   printf("Boresight Track Device V2 ==> %d\n",InPckt->GetBoresightTrackDevice());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());
   printf("TimeStampV2 ==> %d\n",InPckt->GetTimeStamp());

}
