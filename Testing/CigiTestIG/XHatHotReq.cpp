// XHatHotReq.cpp: Body of the XHatHotReq class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatHotReq.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatHotReq::XHatHotReq()
{

}

XHatHotReq::~XHatHotReq()
{

}


void XHatHotReq::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatHotReqV3_2 *InPckt = (CigiHatHotReqV3_2 *)Packet;

   bool ok = true;

   printf("===> HatHotReq <===\n");

   printf("HatHotID ==> %d\n",InPckt->GetHatHotID());
   printf("ReqType ==> %d\n",InPckt->GetReqType());
   printf("SrcCoordSys ==> %d\n",InPckt->GetSrcCoordSys());
   printf("UpdatePeriod ==> %d\n",InPckt->GetUpdatePeriod());
   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("Xoff ==> %f\n",InPckt->GetXoff());
   printf("Yoff ==> %f\n",InPckt->GetYoff());
   printf("Zoff ==> %f\n",InPckt->GetZoff());

}

