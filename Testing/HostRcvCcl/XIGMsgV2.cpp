// XIGMsgV2.cpp: Body of the XIGMsgV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XIGMsgV2.h"
#include <CigiIGMsgV2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGMsgV2::XIGMsgV2()
{

}

XIGMsgV2::~XIGMsgV2()
{

}


void XIGMsgV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiIGMsgV2 *InPckt = (CigiIGMsgV2 *)Packet;


   printf("IG Message V2:\n");
   printf("\tMessage ID = %u\n",InPckt->GetMsgID());
   printf("\tMessage = %s\n",InPckt->GetMsg());

}


