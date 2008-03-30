// XIGCtrlV3_2.cpp: Body of the XIGCtrlV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XIGCtrlV3_2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGCtrlV3_2::XIGCtrlV3_2()
{

}

XIGCtrlV3_2::~XIGCtrlV3_2()
{

}


void XIGCtrlV3_2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiIGCtrlV3_2 *InPckt = (CigiIGCtrlV3_2 *)Packet;

   bool ok = true;

   printf("IGCtrl:\n");

   printf("Version ==> %d\n",InPckt->GetVersion());
   printf("DatabaseID ==> %d\n",InPckt->GetDatabaseID());
   printf("IGMode ==> %d\n",InPckt->GetIGMode());
   printf("TimestampValid ==> %d\n",InPckt->GetTimeStampValid());
   printf("MinorVersion ==> %d\n",InPckt->GetMinorVersion());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());
   printf("TimeStampV3_2 ==> %d\n",InPckt->GetTimeStamp());
   printf("IGFrameCntr ==> %d\n",InPckt->GetLastRcvdIGFrame());

}
