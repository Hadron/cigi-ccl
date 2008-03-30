// XLosRespV1.cpp: Body of the XLosRespV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosRespV1.h"
#include <CigiLosRespV1.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosRespV1::XLosRespV1()
{

}

XLosRespV1::~XLosRespV1()
{

}


void XLosRespV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosRespV1 *InPckt = (CigiLosRespV1 *)Packet;


   printf("Line Of Sight Response V1:\n");
   printf("\tLine Of Sight ID = %u\n",InPckt->GetLosID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tVisible = %d\n",InPckt->GetVisible());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tRange = %f\n",InPckt->GetRange());
   printf("\tLatitude = %f\n",InPckt->GetLatitude());
   printf("\tLongitude = %f\n",InPckt->GetLongitude());
   printf("\tAltitude = %f\n",InPckt->GetAltitude());

}


