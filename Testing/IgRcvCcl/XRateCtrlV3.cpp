// XRateCtrlV3.cpp: Body of the XRateCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XRateCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XRateCtrlV3::XRateCtrlV3()
{

}

XRateCtrlV3::~XRateCtrlV3()
{

}


void XRateCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiRateCtrlV3 *InPckt = (CigiRateCtrlV3 *)Packet;

   bool ok = true;

   printf("Rate Control\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tArticulated Part ID = %d\n",InPckt->GetArtPartID());
   printf("\tApply to Articulated Part = %d\n",InPckt->GetApplyToArtPart());
   printf("\tX Rate = %f\n",InPckt->GetXRate());
   printf("\tY Rate = %f\n",InPckt->GetYRate());
   printf("\tZ Rate = %f\n",InPckt->GetZRate());
   printf("\tRoll Rate = %f\n",InPckt->GetRollRate());
   printf("\tPitch Rate = %f\n",InPckt->GetPitchRate());
   printf("\tYaw Rate = %f\n",InPckt->GetYawRate());

}
