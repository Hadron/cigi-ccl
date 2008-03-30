// XLosSegReqV3_2.cpp: Body of the XLosSegReqV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XLosSegReqV3_2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XLosSegReqV3_2::XLosSegReqV3_2()
{

}

XLosSegReqV3_2::~XLosSegReqV3_2()
{

}


void XLosSegReqV3_2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiLosSegReqV3_2 *InPckt = (CigiLosSegReqV3_2 *)Packet;

   printf("Line of Sight Segment Request\n");

   printf("\tLine of Sight ID = %d\n",InPckt->GetLosID());

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

   printf("\tDestination Coordinate System = %d : ",InPckt->GetDstCoordSys());
   switch(InPckt->GetDstCoordSys())
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

   printf("\tDestination Entity ID Valid = %d\n",InPckt->GetDestEntityIDValid());
   printf("\tAlpha Threshold = %d\n",InPckt->GetAlphaThresh());
   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tSource X Offset = %f\n",InPckt->GetSrcXoff());
   printf("\tSource Y Offset = %f\n",InPckt->GetSrcYoff());
   printf("\tSource Z Offset = %f\n",InPckt->GetSrcZoff());
   printf("\tDestination X Offset = %f\n",InPckt->GetDstXoff());
   printf("\tDestination Y Offset = %f\n",InPckt->GetDstYoff());
   printf("\tDestination Z Offset = %f\n",InPckt->GetDstZoff());
   printf("\tMask = %d\n",InPckt->GetMask());
   printf("\tUpdate Period = %d\n",InPckt->GetUpdatePeriod());
   printf("\tDestination Entity ID = %d\n",InPckt->GetDestEntityID());


}
