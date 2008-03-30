// XRateCtrl.cpp: Body of the XRateCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XRateCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XRateCtrl::XRateCtrl()
{

}

XRateCtrl::~XRateCtrl()
{

}


void XRateCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiRateCtrlV3_2 *InPckt = (CigiRateCtrlV3_2 *)Packet;

   bool ok = true;

   printf("===> RateCtrl <===\n");

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("ArtPartID ==> %d\n",InPckt->GetArtPartID());
   printf("ApplyToArtPart ==> %d\n",InPckt->GetApplyToArtPart());
   printf("CoordSystem ==> %d\n",InPckt->GetCoordSys());
   printf("XRate ==> %f\n",InPckt->GetXRate());
   printf("YRate ==> %f\n",InPckt->GetYRate());
   printf("ZRate ==> %f\n",InPckt->GetZRate());
   printf("RollRate ==> %f\n",InPckt->GetRollRate());
   printf("PitchRate ==> %f\n",InPckt->GetPitchRate());
   printf("YawRate ==> %f\n",InPckt->GetYawRate());


}
