// XLosXRespV3.cpp: Body of the XLosXRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosXRespV3.h"
#include <CigiLosXRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosXRespV3::XLosXRespV3()
{

}

XLosXRespV3::~XLosXRespV3()
{

}


void XLosXRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosXRespV3 *InPckt = (CigiLosXRespV3 *)Packet;


   printf("Line Of Sight Extended Response V3:\n");
   printf("\tLine Of Sight ID = %u\n",InPckt->GetLosID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tEntity ID Valid = %d\n",InPckt->GetEntityIDValid());
   printf("\tRange Valid = %d\n",InPckt->GetRangeValid());
   printf("\tVisible = %d\n",InPckt->GetVisible());

   printf("\tIntersectionCoordSys = %d : ",InPckt->GetIntersectionCoordSys());
   switch(InPckt->GetIntersectionCoordSys())
   {
   case 0:
      printf("Geodetic\n");
      break;
   case 1:
      printf("Entity\n");
      break;
   default:
      printf("\n");
      break;
   }

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


