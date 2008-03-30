// XPositionRespV3.cpp: Body of the XPositionRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XPositionRespV3.h"
#include <CigiPositionRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XPositionRespV3::XPositionRespV3()
{

}

XPositionRespV3::~XPositionRespV3()
{

}


void XPositionRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiPositionRespV3 *InPckt = (CigiPositionRespV3 *)Packet;


   printf("Position Response V3:\n");
   printf("\tObject ID = %u\n",InPckt->GetObjectID());
   printf("\tArticulated Part ID = %u\n",InPckt->GetArtPartID());

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

   printf("\tLat or X offset = %f\n",InPckt->GetLatOrXoff());
   printf("\tLon or Y offset = %f\n",InPckt->GetLonOrYoff());
   printf("\tAlt or Z offset = %f\n",InPckt->GetAltOrZoff());
   printf("\tRoll = %f\n",InPckt->GetRoll());
   printf("\tPitch = %f\n",InPckt->GetPitch());
   printf("\tYaw = %f\n",InPckt->GetYaw());

}


