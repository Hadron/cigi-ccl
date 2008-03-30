// XLosSegReqV1.cpp: Body of the XLosSegReqV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosSegReqV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosSegReqV1::XLosSegReqV1()
{

}

XLosSegReqV1::~XLosSegReqV1()
{

}


void XLosSegReqV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosSegReqV1 *InPckt = (CigiLosSegReqV1 *)Packet;

   printf("Line of Sight Segment Request\n");

   printf("\tLine of Sight ID = %d\n",InPckt->GetLosID());

   printf("\tSource Lat = %f\n",InPckt->GetSrcLat());
   printf("\tSource Lon = %f\n",InPckt->GetSrcLon());
   printf("\tSource Alt = %f\n",InPckt->GetSrcAlt());
   printf("\tDestination Lat = %f\n",InPckt->GetDstLat());
   printf("\tDestination Lon = %f\n",InPckt->GetDstLon());
   printf("\tDestination Alt = %f\n",InPckt->GetDstAlt());

}
