// XMaritimeSurfaceRespV3.cpp: Body of the XMaritimeSurfaceRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XMaritimeSurfaceRespV3.h"
#include <CigiMaritimeSurfaceRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XMaritimeSurfaceRespV3::XMaritimeSurfaceRespV3()
{

}

XMaritimeSurfaceRespV3::~XMaritimeSurfaceRespV3()
{

}


void XMaritimeSurfaceRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiMaritimeSurfaceRespV3 *InPckt = (CigiMaritimeSurfaceRespV3 *)Packet;


   printf("Maritime Surface Response V3:\n");
   printf("\tRequest ID = %u\n",InPckt->GetRequestID());
   printf("\tSurface Height = %f\n",InPckt->GetSurfaceHeight());
   printf("\tWater Temperature = %f\n",InPckt->GetWaterTemp());

}


