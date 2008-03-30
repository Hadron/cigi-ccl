// XLosVectReqV1.cpp: Body of the XLosVectReqV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosVectReqV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosVectReqV1::XLosVectReqV1()
{

}

XLosVectReqV1::~XLosVectReqV1()
{

}


void XLosVectReqV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosVectReqV1 *InPckt = (CigiLosVectReqV1 *)Packet;

   bool ok = true;

   printf("Line of Site Vector Request:\n");

   printf("\tLine of Site ID = %d\n",InPckt->GetLosID());
   printf("\tVector Azimuth = %f\n",InPckt->GetVectAz());
   printf("\tVector Elevation = %f\n",InPckt->GetVectEl());
   printf("\tMax Range = %f\n",InPckt->GetMaxRange());
   printf("\tSource Lat = %f\n",InPckt->GetSrcLat());
   printf("\tSource Lon = %f\n",InPckt->GetSrcLon());
   printf("\tSource Alt = %f\n",InPckt->GetSrcAlt());

}

