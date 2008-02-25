// XAerosolResp.cpp: Body of the XAerosolResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XAerosolResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XAerosolResp::XAerosolResp()
{

}

XAerosolResp::~XAerosolResp()
{

}


void XAerosolResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiAerosolRespV3 *InPckt = (CigiAerosolRespV3 *)Packet;

   printf("RequestID ==> %d\n",InPckt->GetRequestID());
   printf("LayerID ==> %d\n",InPckt->GetLayerID());
   printf("AerosolConcentration ==> %f\n",InPckt->GetAerosolConcentration());


}
