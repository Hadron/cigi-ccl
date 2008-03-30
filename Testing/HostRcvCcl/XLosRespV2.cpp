// XLosRespV2.cpp: Body of the XLosRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosRespV2.h"
#include <CigiLosRespV2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosRespV2::XLosRespV2()
{

}

XLosRespV2::~XLosRespV2()
{

}


void XLosRespV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosRespV2 *InPckt = (CigiLosRespV2 *)Packet;


   printf("Line Of Sight Response V2:\n");
   printf("\tLine Of Sight ID = %u\n",InPckt->GetLosID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tVisible = %d\n",InPckt->GetVisible());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tRange = %f\n",InPckt->GetRange());
   printf("\tLatitude = %f\n",InPckt->GetLatitude());
   printf("\tLongitude = %f\n",InPckt->GetLongitude());
   printf("\tAltitude = %f\n",InPckt->GetAltitude());

}


