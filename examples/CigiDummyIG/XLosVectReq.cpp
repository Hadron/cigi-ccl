// XLosVectReq.cpp: Body of the XLosVectReq class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosVectReq.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosVectReq::XLosVectReq()
{

}

XLosVectReq::~XLosVectReq()
{

}


void XLosVectReq::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosVectReqV3_2 *InPckt = (CigiLosVectReqV3_2 *)Packet;

   bool ok = true;

   printf("===> LosVectReq <===\n");

   printf("LosID ==> %d\n",InPckt->GetLosID());
   printf("ReqType ==> %d\n",InPckt->GetReqType());
   printf("SrcCoordSys ==> %d\n",InPckt->GetSrcCoordSys());
   printf("ResponseCoordSys ==> %d\n",InPckt->GetResponseCoordSys());
   printf("AlphaThresh ==> %d\n",InPckt->GetAlphaThresh());
   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("VectAz ==> %f\n",InPckt->GetVectAz());
   printf("VectEl ==> %f\n",InPckt->GetVectEl());
   printf("MinRange ==> %f\n",InPckt->GetMinRange());
   printf("MaxRange ==> %f\n",InPckt->GetMaxRange());
   printf("SrcXoff ==> %f\n",InPckt->GetSrcXoff());
   printf("SrcYoff ==> %f\n",InPckt->GetSrcYoff());
   printf("SrcZoff ==> %f\n",InPckt->GetSrcZoff());
   printf("Mask ==> %d\n",InPckt->GetMask());
   printf("UpdatePeriod ==> %d\n",InPckt->GetUpdatePeriod());

}

