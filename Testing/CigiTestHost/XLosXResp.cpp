// XLosXResp.cpp: Body of the XLosXResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XLosXResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosXResp::XLosXResp()
{

}

XLosXResp::~XLosXResp()
{

}


void XLosXResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiLosXRespV3_2 *InPckt = (CigiLosXRespV3_2 *)Packet;

   printf("LosID ==> %d\n",InPckt->GetLosID());
   printf("Valid ==> %d\n",InPckt->GetValid());
   printf("EntityIDValid ==> %d\n",InPckt->GetEntityIDValid());
   printf("RangeValid ==> %d\n",InPckt->GetRangeValid());
   printf("Visible ==> %d\n",InPckt->GetVisible());
   printf("FrameID ==> %d\n",InPckt->GetHostFrame());
   printf("RespCount ==> %d\n",InPckt->GetRespCount());
   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("Range ==> %f\n",InPckt->GetRange());
   printf("Xoff ==> %f\n",InPckt->GetXoff());
   printf("Yoff ==> %f\n",InPckt->GetYoff());
   printf("Zoff ==> %f\n",InPckt->GetZoff());
   printf("Red ==> %d\n",InPckt->GetRed());
   printf("Green ==> %d\n",InPckt->GetGreen());
   printf("Blue ==> %d\n",InPckt->GetBlue());
   printf("Alpha ==> %d\n",InPckt->GetAlpha());
   printf("Material ==> %d\n",InPckt->GetMaterial());
   printf("NormalAz ==> %f\n",InPckt->GetNormalAz());
   printf("NormalEl ==> %f\n",InPckt->GetNormalEl());


}
