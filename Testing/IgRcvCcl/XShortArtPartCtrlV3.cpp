// XShortArtPartCtrlV3.cpp: Body of the XShortArtPartCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XShortArtPartCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XShortArtPartCtrlV3::XShortArtPartCtrlV3()
{

}

XShortArtPartCtrlV3::~XShortArtPartCtrlV3()
{

}


void XShortArtPartCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiShortArtPartCtrlV3 *InPckt = (CigiShortArtPartCtrlV3 *)Packet;

   printf("Short Articulated Control:\n");

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tArticulated Part ID 1 = %d\n",InPckt->GetArtPart1());
   printf("\tArticulated Part ID 2 = %d\n",InPckt->GetArtPart2());

   printf("\tDegree of Freedom Select 1 = %d : ",InPckt->GetDofSelect1());
   switch(InPckt->GetDofSelect1())
   {
   case 0:
      printf("Not Used\n");
      break;
   case 1:
      printf("X Offset\n");
      break;
   case 2:
      printf("Y Offset\n");
      break;
   case 3:
      printf("Z Offset\n");
      break;
   case 4:
      printf("Yaw\n");
      break;
   case 5:
      printf("Pitch\n");
      break;
   case 6:
      printf("Roll\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tDegree of Freedom Select 2 = %d : ",InPckt->GetDofSelect2());
   switch(InPckt->GetDofSelect2())
   {
   case 0:
      printf("Not Used\n");
      break;
   case 1:
      printf("X Offset\n");
      break;
   case 2:
      printf("Y Offset\n");
      break;
   case 3:
      printf("Z Offset\n");
      break;
   case 4:
      printf("Yaw\n");
      break;
   case 5:
      printf("Pitch\n");
      break;
   case 6:
      printf("Roll\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tArticulated Part 1 Enable = %d\n",InPckt->GetArtPart1En());
   printf("\tArticulated Part 2 Enable = %d\n",InPckt->GetArtPart2En());
   printf("\tDegree of Freedom 1 = %f\n",InPckt->GetDof1());
   printf("\tDegree of Freedom 2 = %f\n",InPckt->GetDof2());

}
