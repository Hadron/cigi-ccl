// XIGMsg.cpp: Body of the XIGMsg class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XIGMsg.h"
#include "string.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XIGMsg::XIGMsg()
{

}

XIGMsg::~XIGMsg()
{

}


void XIGMsg::OnPacketReceived(CigiBasePacket *Packet)
{
CigiIGMsgV3 *InPckt = (CigiIGMsgV3 *)Packet;

   printf("MsgID ==> %d\n",InPckt->GetMsgID());
   printf("Msg ==> %s\n",InPckt->GetMsg());


}
