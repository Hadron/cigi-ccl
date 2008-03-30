// XViewCtrlV3.cpp: Body of the XViewCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XViewCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XViewCtrlV3::XViewCtrlV3()
{

}

XViewCtrlV3::~XViewCtrlV3()
{

}


void XViewCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
CigiViewCtrlV3 *InPckt = (CigiViewCtrlV3 *)Packet;

   printf("View Control:\n");

   printf("\tView ID = %d\n",InPckt->GetViewID());
   printf("\tGroup ID = %d\n",InPckt->GetGroupID());
   printf("\tX Offset Enable = %d\n",InPckt->GetXOffEn());
   printf("\tY Offset Enable = %d\n",InPckt->GetYOffEn());
   printf("\tZ Offset Enable = %d\n",InPckt->GetZOffEn());
   printf("\tRoll Enable = %d\n",InPckt->GetRollEn());
   printf("\tPitch Enable = %d\n",InPckt->GetPitchEn());
   printf("\tYaw Enable = %d\n",InPckt->GetYawEn());
   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tX Offset = %f\n",InPckt->GetXOff());
   printf("\tY Offset = %f\n",InPckt->GetYOff());
   printf("\tZ Offset = %f\n",InPckt->GetZOff());
   printf("\tRoll = %f\n",InPckt->GetRoll());
   printf("\tPitch = %f\n",InPckt->GetPitch());
   printf("\tYaw = %f\n",InPckt->GetYaw());

}
