// XLosXRespV3_2.cpp: Body of the XLosXRespV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosXRespV3_2.h"
#include <CigiLosXRespV3_2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosXRespV3_2::XLosXRespV3_2()
{

}

XLosXRespV3_2::~XLosXRespV3_2()
{

}


void XLosXRespV3_2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosXRespV3_2 *InPckt = (CigiLosXRespV3_2 *)Packet;


   printf("Line Of Sight Extended Response V3_2:\n");
   printf("\tLine Of Sight ID = %u\n",InPckt->GetLosID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tEntity ID Valid = %d\n",InPckt->GetEntityIDValid());
   printf("\tRange Valid = %d\n",InPckt->GetRangeValid());
   printf("\tVisible = %d\n",InPckt->GetVisible());
   printf("\tHost Frame = %u\n",InPckt->GetHostFrame());
   printf("\tResponse Count = %u\n",InPckt->GetRespCount());
   printf("\tEntity ID = %u\n",InPckt->GetEntityID());
   printf("\tRange = %f\n",InPckt->GetRange());
   printf("\tX Offset = %f\n",InPckt->GetXoff());
   printf("\tY Offset = %f\n",InPckt->GetYoff());
   printf("\tZ Offset = %f\n",InPckt->GetZoff());
   printf("\tRed = %u\n",InPckt->GetRed());
   printf("\tGreen = %u\n",InPckt->GetGreen());
   printf("\tBlue = %u\n",InPckt->GetBlue());
   printf("\tAlpha = %u\n",InPckt->GetAlpha());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tNormal Azimuth = %f\n",InPckt->GetNormalAz());
   printf("\tNormal Elevation = %f\n",InPckt->GetNormalEl());

}


