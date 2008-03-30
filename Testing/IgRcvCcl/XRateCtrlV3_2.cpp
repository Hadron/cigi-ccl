// XRateCtrlV3_2.cpp: Body of the XRateCtrlV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XRateCtrlV3_2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XRateCtrlV3_2::XRateCtrlV3_2()
{

}

XRateCtrlV3_2::~XRateCtrlV3_2()
{

}


void XRateCtrlV3_2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiRateCtrlV3_2 *InPckt = (CigiRateCtrlV3_2 *)Packet;

   bool ok = true;

   printf("Rate Control\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tArticulated Part ID = %d\n",InPckt->GetArtPartID());
   printf("\tApply to Articulated Part = %d\n",InPckt->GetApplyToArtPart());

   printf("\tCoordinate System = %d : ",InPckt->GetCoordSys());
   switch(InPckt->GetCoordSys())
   {
   case 0:
      printf("World\n");
      break;
   case 1:
      printf("Local\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tX Rate = %f\n",InPckt->GetXRate());
   printf("\tY Rate = %f\n",InPckt->GetYRate());
   printf("\tZ Rate = %f\n",InPckt->GetZRate());
   printf("\tRoll Rate = %f\n",InPckt->GetRollRate());
   printf("\tPitch Rate = %f\n",InPckt->GetPitchRate());
   printf("\tYaw Rate = %f\n",InPckt->GetYawRate());

}
