// XLosRespV3_2.cpp: Body of the XLosRespV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosRespV3_2.h"
#include <CigiLosRespV3_2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosRespV3_2::XLosRespV3_2()
{

}

XLosRespV3_2::~XLosRespV3_2()
{

}


void XLosRespV3_2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosRespV3_2 *InPckt = (CigiLosRespV3_2 *)Packet;


   printf("Line Of Sight Response V3_2:\n");
   printf("\tLine Of Sight ID = %u\n",InPckt->GetLosID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tEntity ID Valid = %d\n",InPckt->GetEntityIDValid());
   printf("\tVisible = %d\n",InPckt->GetVisible());
   printf("\tHost Frame = %u\n",InPckt->GetHostFrame());
   printf("\tResponse Count = %u\n",InPckt->GetRespCount());
   printf("\tEntity ID = %u\n",InPckt->GetEntityID());
   printf("\tRange = %f\n",InPckt->GetRange());

}


