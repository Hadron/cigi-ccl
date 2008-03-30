// XArtPartCtrl.cpp: Body of the XArtPartCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XArtPartCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XArtPartCtrl::XArtPartCtrl()
{

}

XArtPartCtrl::~XArtPartCtrl()
{

}


void XArtPartCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiArtPartCtrlV3 *InPckt = (CigiArtPartCtrlV3 *)Packet;

   printf("===> ArtPartCtrl <===\n");

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("ArtPartID ==> %d\n",InPckt->GetArtPartID());
   printf("ArtPartEn ==> %d\n",InPckt->GetArtPartEn());
   printf("XOffEn ==> %d\n",InPckt->GetXOffEn());
   printf("YOffEn ==> %d\n",InPckt->GetYOffEn());
   printf("ZOffEn ==> %d\n",InPckt->GetZOffEn());
   printf("RollEn ==> %d\n",InPckt->GetRollEn());
   printf("PitchEn ==> %d\n",InPckt->GetPitchEn());
   printf("YawEn ==> %d\n",InPckt->GetYawEn());
   printf("XOff ==> %f\n",InPckt->GetXOff());
   printf("YOff ==> %f\n",InPckt->GetYOff());
   printf("ZOff ==> %f\n",InPckt->GetZOff());
   printf("Roll ==> %f\n",InPckt->GetRoll());
   printf("Pitch ==> %f\n",InPckt->GetPitch());
   printf("Yaw ==> %f\n",InPckt->GetYaw());


}
