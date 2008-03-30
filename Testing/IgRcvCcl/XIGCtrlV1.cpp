// XIGCtrlV1.cpp: Body of the XIGCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XIGCtrlV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGCtrlV1::XIGCtrlV1()
{

}

XIGCtrlV1::~XIGCtrlV1()
{

}


void XIGCtrlV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiIGCtrlV1 *InPckt = (CigiIGCtrlV1 *)Packet;

   bool ok = true;

   printf("IGCtrl\n");

   printf("Version ==> %d\n",InPckt->GetVersion());
   printf("DatabaseID ==> %d\n",InPckt->GetDatabaseID());
   printf("IGMode ==> %d\n",InPckt->GetIGMode());
   printf("Tracking Device Enable V1 ==> %d\n",InPckt->GetTrackDeviceEn());
   printf("Boresight Track Device V1 ==> %d\n",InPckt->GetBoresightTrackDevice());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());
   printf("TimeStampV1 ==> %d\n",InPckt->GetTimeStamp());

}
