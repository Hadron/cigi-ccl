// XIGMsgV3.cpp: Body of the XIGMsgV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XIGMsgV3.h"
#include <CigiIGMsgV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGMsgV3::XIGMsgV3()
{

}

XIGMsgV3::~XIGMsgV3()
{

}


void XIGMsgV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiIGMsgV3 *InPckt = (CigiIGMsgV3 *)Packet;


   printf("IG Message V3:\n");
   printf("\tMessage ID = %u\n",InPckt->GetMsgID());
   printf("\tMessage = %s\n",InPckt->GetMsg());

}


