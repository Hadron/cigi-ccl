// XTerrestrialSurfaceRespV3.cpp: Body of the XTerrestrialSurfaceRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XTerrestrialSurfaceRespV3.h"
#include <CigiTerrestrialSurfaceRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XTerrestrialSurfaceRespV3::XTerrestrialSurfaceRespV3()
{

}

XTerrestrialSurfaceRespV3::~XTerrestrialSurfaceRespV3()
{

}


void XTerrestrialSurfaceRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiTerrestrialSurfaceRespV3 *InPckt = (CigiTerrestrialSurfaceRespV3 *)Packet;


   printf("Terrestrial Surface Response V3:\n");
   printf("\tRequest ID = %u\n",InPckt->GetRequestID());
   printf("\tSurface Condition ID = %u\n",InPckt->GetSurfaceConditionID());

}


