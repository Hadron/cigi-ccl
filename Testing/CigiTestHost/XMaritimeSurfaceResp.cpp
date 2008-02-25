// XMaritimeSurfaceResp.cpp: Body of the XMaritimeSurfaceResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XMaritimeSurfaceResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XMaritimeSurfaceResp::XMaritimeSurfaceResp()
{

}

XMaritimeSurfaceResp::~XMaritimeSurfaceResp()
{

}


void XMaritimeSurfaceResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiMaritimeSurfaceRespV3 *InPckt = (CigiMaritimeSurfaceRespV3 *)Packet;

   printf("RequestID ==> %d\n",InPckt->GetRequestID());
   printf("SurfaceHeight ==> %f\n",InPckt->GetSurfaceHeight());
   printf("WaterTemp ==> %f\n",InPckt->GetWaterTemp());
   printf("Clarity ==> %f\n",InPckt->GetClarity());


}
