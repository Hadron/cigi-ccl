// XRateCtrlV1.cpp: Body of the XRateCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XRateCtrlV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XRateCtrlV1::XRateCtrlV1()
{

}

XRateCtrlV1::~XRateCtrlV1()
{

}


void XRateCtrlV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiRateCtrlV1 *InPckt = (CigiRateCtrlV1 *)Packet;

   bool ok = true;

   printf("Rate Control\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tArticulated Part ID = %d\n",InPckt->GetArtPartID());
   printf("\tX Rate = %f\n",InPckt->GetXRate());
   printf("\tY Rate = %f\n",InPckt->GetYRate());
   printf("\tZ Rate = %f\n",InPckt->GetZRate());
   printf("\tRoll Rate = %f\n",InPckt->GetRollRate());
   printf("\tPitch Rate = %f\n",InPckt->GetPitchRate());
   printf("\tYaw Rate = %f\n",InPckt->GetYawRate());

}
