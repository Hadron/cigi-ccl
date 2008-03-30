// XPositionReqV3.cpp: Body of the XPostionReqV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XPositionReqV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XPositionReqV3::XPositionReqV3()
{

}

XPositionReqV3::~XPositionReqV3()
{

}


void XPositionReqV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiPositionReqV3 *InPckt = (CigiPositionReqV3 *)Packet;

   bool ok = true;

   printf("Position Request\n");

   printf("\tObject ID = %d\n",InPckt->GetObjectID());
   printf("\tArticulated Part ID = %d\n",InPckt->GetArtPartID());

   printf("\tUpdate Mode = %d : ",InPckt->GetUpdateMode());
   switch(InPckt->GetUpdateMode())
   {
   case 0:
      printf("OneShot\n");
      break;
   case 1:
      printf("Continuous\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tObject Class = %d : ",InPckt->GetObjectClass());
   switch(InPckt->GetObjectClass())
   {
   case 0:
      printf("Entity\n");
      break;
   case 1:
      printf("ArtPart\n");
      break;
   case 2:
      printf("View\n");
      break;
   case 3:
      printf("ViewGrp\n");
      break;
   case 4:
      printf("MotionTracker\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tCoordinate System = %d : ",InPckt->GetCoordSys());
   switch(InPckt->GetCoordSys())
   {
   case 0:
      printf("Geodetic\n");
      break;
   case 1:
      printf("ParentEntity\n");
      break;
   case 2:
      printf("Submodel\n");
      break;
   default:
      printf("\n");
      break;
   }

}
