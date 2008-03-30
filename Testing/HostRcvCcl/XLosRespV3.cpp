// XLosRespV3.cpp: Body of the XLosRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosRespV3.h"
#include <CigiLosRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosRespV3::XLosRespV3()
{

}

XLosRespV3::~XLosRespV3()
{

}


void XLosRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosRespV3 *InPckt = (CigiLosRespV3 *)Packet;


   printf("Line Of Sight Response V3:\n");
   printf("\tLine Of Sight ID = %u\n",InPckt->GetLosID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tEntity ID Valid = %d\n",InPckt->GetEntityIDValid());
   printf("\tVisible = %d\n",InPckt->GetVisible());
   printf("\tResponse Count = %u\n",InPckt->GetRespCount());
   printf("\tEntity ID = %u\n",InPckt->GetEntityID());
   printf("\tRange = %f\n",InPckt->GetRange());

}


