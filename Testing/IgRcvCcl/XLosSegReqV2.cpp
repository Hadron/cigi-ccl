// XLosSegReqV2.cpp: Body of the XLosSegReqV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosSegReqV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosSegReqV2::XLosSegReqV2()
{

}

XLosSegReqV2::~XLosSegReqV2()
{

}


void XLosSegReqV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosSegReqV2 *InPckt = (CigiLosSegReqV2 *)Packet;

   printf("Line of Sight Segment Request\n");

   printf("\tLine of Sight ID = %d\n",InPckt->GetLosID());

   printf("\tSource Lat = %f\n",InPckt->GetSrcLat());
   printf("\tSource Lon = %f\n",InPckt->GetSrcLon());
   printf("\tSource Alt = %f\n",InPckt->GetSrcAlt());
   printf("\tDestination Lat = %f\n",InPckt->GetDstLat());
   printf("\tDestination Lon = %f\n",InPckt->GetDstLon());
   printf("\tDestination Alt = %f\n",InPckt->GetDstAlt());

}
