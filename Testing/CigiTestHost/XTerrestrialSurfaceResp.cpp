// XTerrestrialSurfaceResp.cpp: Body of the XTerrestrialSurfaceResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XTerrestrialSurfaceResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XTerrestrialSurfaceResp::XTerrestrialSurfaceResp()
{

}

XTerrestrialSurfaceResp::~XTerrestrialSurfaceResp()
{

}


void XTerrestrialSurfaceResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiTerrestrialSurfaceRespV3 *InPckt = (CigiTerrestrialSurfaceRespV3 *)Packet;

   printf("RequestID ==> %d\n",InPckt->GetRequestID());
   printf("SurfaceConditionID ==> %d\n",InPckt->GetSurfaceConditionID());


}
