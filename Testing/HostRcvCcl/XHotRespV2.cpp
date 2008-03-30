// XHotRespV2.cpp: Body of the XHotRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHotRespV2.h"
#include <CigiHotRespV2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHotRespV2::XHotRespV2()
{

}

XHotRespV2::~XHotRespV2()
{

}


void XHotRespV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHotRespV2 *InPckt = (CigiHotRespV2 *)Packet;


   printf("HOT Response V2:\n");
   printf("\tHot ID = %u\n",InPckt->GetHatHotID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tHot = %f\n",InPckt->GetHot());

}


