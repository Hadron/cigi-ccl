// XLosSegReq.cpp: Body of the XLosSegReq class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosSegReq.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosSegReq::XLosSegReq()
{

}

XLosSegReq::~XLosSegReq()
{

}


void XLosSegReq::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosSegReqV3_2 *InPckt = (CigiLosSegReqV3_2 *)Packet;

   printf("===> LosSegReq <===\n");

   printf("LosID ==> %d\n",InPckt->GetLosID());
   printf("ReqType ==> %d\n",InPckt->GetReqType());
   printf("SrcCoordSys ==> %d\n",InPckt->GetSrcCoordSys());
   printf("DstCoordSys ==> %d\n",InPckt->GetDstCoordSys());
   printf("ResponseCoordSys ==> %d\n",InPckt->GetResponseCoordSys());
   printf("DestinationEntityValid ==> %d\n",InPckt->GetDestEntityIDValid());
   printf("AlphaThresh ==> %d\n",InPckt->GetAlphaThresh());
   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("SrcXoff ==> %f\n",InPckt->GetSrcXoff());
   printf("SrcYoff ==> %f\n",InPckt->GetSrcYoff());
   printf("SrcZoff ==> %f\n",InPckt->GetSrcZoff());
   printf("DstXoff ==> %f\n",InPckt->GetDstXoff());
   printf("DstYoff ==> %f\n",InPckt->GetDstYoff());
   printf("DstZoff ==> %f\n",InPckt->GetDstZoff());
   printf("Mask ==> %d\n",InPckt->GetMask());
   printf("UpdatePeriod ==> %d\n",InPckt->GetUpdatePeriod());
   printf("DestinationEntityID ==> %d\n",InPckt->GetDestEntityID());


}
