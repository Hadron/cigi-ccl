// XArtPartCtrlV1.cpp: Body of the XArtPartCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XArtPartCtrlV1.h"
#include "CigiArtPartCtrlV1.h"
#include "CigiArtPartCtrlV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XArtPartCtrlV1::XArtPartCtrlV1()
{

}

XArtPartCtrlV1::~XArtPartCtrlV1()
{

}


void XArtPartCtrlV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiArtPartCtrlV1 *InPckt = (CigiArtPartCtrlV1 *)Packet;



   printf("Articulated Part Control:\n");
   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tArticulated Part ID = %d\n",InPckt->GetArtPartIDV1());
   printf("\tArticulated Part Enable = %d\n",InPckt->GetArtPartEn());
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
