// XLosVectReqV2.cpp: Body of the XLosVectReqV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosVectReqV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosVectReqV2::XLosVectReqV2()
{

}

XLosVectReqV2::~XLosVectReqV2()
{

}


void XLosVectReqV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosVectReqV2 *InPckt = (CigiLosVectReqV2 *)Packet;

   bool ok = true;

   printf("Line of Site Vector Request:\n");

   printf("\tLine of Site ID = %d\n",InPckt->GetLosID());
   printf("\tVector Azimuth = %f\n",InPckt->GetVectAz());
   printf("\tVector Elevation = %f\n",InPckt->GetVectEl());
   printf("\tMinimum Range = %f\n",InPckt->GetMinRange());
   printf("\tMax Range = %f\n",InPckt->GetMaxRange());
   printf("\tSource Lat = %f\n",InPckt->GetSrcLat());
   printf("\tSource Lon = %f\n",InPckt->GetSrcLon());
   printf("\tSource Alt = %f\n",InPckt->GetSrcAlt());

}

