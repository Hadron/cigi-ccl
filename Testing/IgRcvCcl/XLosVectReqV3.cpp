// XLosVectReqV3.cpp: Body of the XLosVectReqV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosVectReqV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosVectReqV3::XLosVectReqV3()
{

}

XLosVectReqV3::~XLosVectReqV3()
{

}


void XLosVectReqV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosVectReqV3 *InPckt = (CigiLosVectReqV3 *)Packet;

   bool ok = true;

   printf("Line of Site Vector Request:\n");

   printf("\tLine of Site ID = %d\n",InPckt->GetLosID());

   printf("\tRequest Type = %d : ",InPckt->GetReqType());
   switch(InPckt->GetReqType())
   {
   case 0:
      printf("Basic\n");
      break;
   case 1:
      printf("Extended\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tSource Coordinate System = %d : ",InPckt->GetSrcCoordSys());
   switch(InPckt->GetSrcCoordSys())
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

   printf("\tResponse Coordinate System = %d : ",InPckt->GetResponseCoordSys());
   switch(InPckt->GetResponseCoordSys())
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

   printf("\tAlpha Threshold = %d\n",InPckt->GetAlphaThresh());
   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tVector Azimuth = %f\n",InPckt->GetVectAz());
   printf("\tVector Elevation = %f\n",InPckt->GetVectEl());
   printf("\tMinimum Range = %f\n",InPckt->GetMinRange());
   printf("\tMax Range = %f\n",InPckt->GetMaxRange());
   printf("\tSource X Offset = %f\n",InPckt->GetSrcXoff());
   printf("\tSource Y Offset = %f\n",InPckt->GetSrcYoff());
   printf("\tSource Z Offset = %f\n",InPckt->GetSrcZoff());
   printf("\tMask = %d\n",InPckt->GetMask());

}

