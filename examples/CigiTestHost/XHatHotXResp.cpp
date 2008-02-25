// XHatHotXResp.cpp: implementation of the XHatHotXResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XHatHotXResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatHotXResp::XHatHotXResp()
{

}

XHatHotXResp::~XHatHotXResp()
{

}

void XHatHotXResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiHatHotXRespV3_2 *InPckt = (CigiHatHotXRespV3_2 *)Packet;

   printf("HatHotID ==> %d\n",InPckt->GetHatHotID());
   printf("Valid ==> %d\n",InPckt->GetValid());
   printf("FrameID ==> %d\n",InPckt->GetHostFrame());
   printf("Hat ==> %f\n",InPckt->GetHat());
   printf("Hot ==> %f\n",InPckt->GetHot());
   printf("Material ==> %d\n",InPckt->GetMaterial());
   printf("NormAz ==> %f\n",InPckt->GetNormAz());
   printf("NormEl ==> %f\n",InPckt->GetNormEl());

}
