// XHatRespV1.cpp: Body of the XHatRespV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatRespV1.h"
#include <CigiHatRespV1.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatRespV1::XHatRespV1()
{

}

XHatRespV1::~XHatRespV1()
{

}


void XHatRespV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatRespV1 *InPckt = (CigiHatRespV1 *)Packet;


   printf("HAT Response V1:\n");
   printf("\tHat ID = %u\n",InPckt->GetHatHotID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tHat = %f\n",InPckt->GetHat());

}


