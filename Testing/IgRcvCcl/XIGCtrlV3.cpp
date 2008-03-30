// XIGCtrlV3.cpp: Body of the XIGCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XIGCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGCtrlV3::XIGCtrlV3()
{

}

XIGCtrlV3::~XIGCtrlV3()
{

}


void XIGCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiIGCtrlV3 *InPckt = (CigiIGCtrlV3 *)Packet;

   bool ok = true;

   printf("IGCtrl\n");

   printf("Version ==> %d\n",InPckt->GetVersion());
   printf("DatabaseID ==> %d\n",InPckt->GetDatabaseID());
   printf("IGMode ==> %d\n",InPckt->GetIGMode());
   printf("TimestampValid ==> %d\n",InPckt->GetTimeStampValid());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());
   printf("TimeStampV3 ==> %d\n",InPckt->GetTimeStamp());

}
