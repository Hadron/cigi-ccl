// XIGCtrlV3_3.cpp: Body of the XIGCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XIGCtrlV3_3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGCtrlV3_3::XIGCtrlV3_3()
{

}

XIGCtrlV3_3::~XIGCtrlV3_3()
{

}


void XIGCtrlV3_3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiIGCtrlV3_3 *InPckt = (CigiIGCtrlV3_3 *)Packet;

   bool ok = true;

   printf("IGCtrl:\n");

   printf("Version ==> %d\n",InPckt->GetVersion());
   printf("DatabaseID ==> %d\n",InPckt->GetDatabaseID());
   printf("IGMode ==> %d\n",InPckt->GetIGMode());
   printf("TimestampValid ==> %d\n",InPckt->GetTimeStampValid());

   if(InPckt->GetSmoothingEn())
      printf("Smoothing Enabled\n");
   else
      printf("Smoothing Disabled\n");

   printf("MinorVersion ==> %d\n",InPckt->GetMinorVersion());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());
   printf("TimeStampV3_2 ==> %d\n",InPckt->GetTimeStamp());
   printf("IGFrameCntr ==> %d\n",InPckt->GetLastRcvdIGFrame());

}
