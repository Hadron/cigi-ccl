// XAerosolRespV3.cpp: Body of the XAerosolRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XAerosolRespV3.h"
#include <CigiAerosolRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XAerosolRespV3::XAerosolRespV3()
{

}

XAerosolRespV3::~XAerosolRespV3()
{

}


void XAerosolRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiAerosolRespV3 *InPckt = (CigiAerosolRespV3 *)Packet;


   printf("Aerosol Response V3:\n");
   printf("\tRequest ID = %u\n",InPckt->GetRequestID());
   printf("\tLayer ID = %u\n",InPckt->GetLayerID());
   printf("\tAerosol Concentration = %f\n",InPckt->GetAerosolConcentration());

}


