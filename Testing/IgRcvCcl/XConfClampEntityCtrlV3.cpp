// XConfClampEntityCtrlV3.cpp: Body of the XConfClampEntityCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XConfClampEntityCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XConfClampEntityCtrlV3::XConfClampEntityCtrlV3()
{

}

XConfClampEntityCtrlV3::~XConfClampEntityCtrlV3()
{

}


void XConfClampEntityCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiConfClampEntityCtrlV3 *InPckt = (CigiConfClampEntityCtrlV3 *)Packet;

   bool ok = true;

   printf("Conformal Clamped Entity Control:\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tYaw = %f\n",InPckt->GetYaw());
   printf("\tLat = %f\n",InPckt->GetLat());
   printf("\tLon = %f\n",InPckt->GetLon());

}
