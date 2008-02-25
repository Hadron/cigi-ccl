// XLosResp.cpp: Body of the XLosResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XLosResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosResp::XLosResp()
{

}

XLosResp::~XLosResp()
{

}


void XLosResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiLosRespV3_2 *InPckt = (CigiLosRespV3_2 *)Packet;

   printf("LosID ==> %d\n",InPckt->GetLosID());
   printf("Valid ==> %d\n",InPckt->GetValid());
   printf("EntityIDValid ==> %d\n",InPckt->GetEntityIDValid());
   printf("Visible ==> %d\n",InPckt->GetVisible());
   printf("FrameID ==> %d\n",InPckt->GetHostFrame());
   printf("RespCount ==> %d\n",InPckt->GetRespCount());
   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("Range ==> %f\n",InPckt->GetRange());


}
