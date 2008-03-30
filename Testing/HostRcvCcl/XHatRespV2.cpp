// XHatRespV2.cpp: Body of the XHatRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatRespV2.h"
#include <CigiHatRespV2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatRespV2::XHatRespV2()
{

}

XHatRespV2::~XHatRespV2()
{

}


void XHatRespV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatRespV2 *InPckt = (CigiHatRespV2 *)Packet;


   printf("HAT Response V2:\n");
   printf("\tHat ID = %u\n",InPckt->GetHatHotID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tHat = %f\n",InPckt->GetHat());

}


