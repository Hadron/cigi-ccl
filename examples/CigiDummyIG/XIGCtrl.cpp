// XIGCtrl.cpp: Body of the XIGCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XIGCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGCtrl::XIGCtrl()
{

}

XIGCtrl::~XIGCtrl()
{

}


void XIGCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiIGCtrlV3_2 *InPckt = (CigiIGCtrlV3_2 *)Packet;

   bool ok = true;

   printf("===> IGCtrl <===\n");

   printf("Version ==> %d\n",InPckt->GetVersion());
   printf("DatabaseID ==> %d\n",InPckt->GetDatabaseID());
   printf("IGMode ==> %d\n",InPckt->GetIGMode());
   printf("TimestampValid ==> %d\n",InPckt->GetTimeStampValid());
   printf("MinorVersion ==> %d\n",InPckt->GetMinorVersion());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());
   printf("TimeStampV3 ==> %d\n",InPckt->GetTimeStamp());
   printf("IGFrameCntr ==> %d\n",InPckt->GetLastRcvdIGFrame());


}
