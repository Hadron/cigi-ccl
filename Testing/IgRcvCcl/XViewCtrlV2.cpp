// XViewCtrlV2.cpp: Body of the XViewCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XViewCtrlV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XViewCtrlV2::XViewCtrlV2()
{

}

XViewCtrlV2::~XViewCtrlV2()
{

}


void XViewCtrlV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiViewCtrlV2 *InPckt = (CigiViewCtrlV2 *)Packet;

   printf("View Control:\n");

   printf("\tView ID = %d\n",InPckt->GetViewID());
   printf("\tGroup ID = %d\n",InPckt->GetGroupID());
   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tX Offset Enable = %d\n",InPckt->GetXOffEn());
   printf("\tY Offset Enable = %d\n",InPckt->GetYOffEn());
   printf("\tZ Offset Enable = %d\n",InPckt->GetZOffEn());
   printf("\tRoll Enable = %d\n",InPckt->GetRollEn());
   printf("\tPitch Enable = %d\n",InPckt->GetPitchEn());
   printf("\tYaw Enable = %d\n",InPckt->GetYawEn());
   printf("\tX Offset = %f\n",InPckt->GetXOff());
   printf("\tY Offset = %f\n",InPckt->GetYOff());
   printf("\tZ Offset = %f\n",InPckt->GetZOff());
   printf("\tRoll = %f\n",InPckt->GetRoll());
   printf("\tPitch = %f\n",InPckt->GetPitch());
   printf("\tYaw = %f\n",InPckt->GetYaw());

}
