// XViewCtrlV1.cpp: Body of the XViewCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XViewCtrlV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XViewCtrlV1::XViewCtrlV1()
{

}

XViewCtrlV1::~XViewCtrlV1()
{

}


void XViewCtrlV1::OnPacketReceived(CigiBasePacket *Packet)
{
CigiViewCtrlV1 *InPckt = (CigiViewCtrlV1 *)Packet;

   printf("View Control:\n");

   printf("\tView ID = %d\n",InPckt->GetViewID());
   printf("\tGroup ID = %d\n",InPckt->GetGroupID());
   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tX Offset = %f\n",InPckt->GetXOff());
   printf("\tY Offset = %f\n",InPckt->GetYOff());
   printf("\tZ Offset = %f\n",InPckt->GetZOff());
   printf("\tRoll = %f\n",InPckt->GetRoll());
   printf("\tPitch = %f\n",InPckt->GetPitch());
   printf("\tYaw = %f\n",InPckt->GetYaw());

}
