// XHatHotResp.cpp: Body of the XHatHotResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XHatHotResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatHotResp::XHatHotResp()
{

}

XHatHotResp::~XHatHotResp()
{

}


void XHatHotResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiHatHotRespV3_2 *InPckt = (CigiHatHotRespV3_2 *)Packet;

   printf("HatHotID ==> %d\n",InPckt->GetHatHotID());
   printf("Valid ==> %d\n",InPckt->GetValid());
   printf("ReqType ==> %d\n",InPckt->GetReqType());
   printf("FrameID ==> %d\n",InPckt->GetHostFrame());
   printf("Hat ==> %f  :::  Hot ==> %f\n",InPckt->GetHat(),InPckt->GetHot());


}
