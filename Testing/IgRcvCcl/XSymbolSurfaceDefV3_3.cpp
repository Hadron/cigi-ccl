// XSymbolSurfaceDefV3_3.cpp: Body of the XSymbolSurfaceDefV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSymbolSurfaceDefV3_3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSymbolSurfaceDefV3_3::XSymbolSurfaceDefV3_3()
{

}

XSymbolSurfaceDefV3_3::~XSymbolSurfaceDefV3_3()
{

}


void XSymbolSurfaceDefV3_3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSymbolSurfaceDefV3_3 *InPckt = (CigiSymbolSurfaceDefV3_3 *)Packet;

   printf("Symbol Surface Definition:\n");

   printf("\tSurface ID = %d\n",InPckt->GetSurfaceID());

   printf("\tSurface State = %d : ",InPckt->GetSurfaceState());
   switch(InPckt->GetSurfaceState())
   {
   case 0:
      printf("Active\n");
      break;
   case 1:
      printf("Destroyed\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tAttach State = %d : ",InPckt->GetAttached());
   switch(InPckt->GetAttached())
   {
   case 0:
      printf("EntityAttached\n");
      break;
   case 1:
      printf("ViewAttached\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tBillBoard State = %d : ",InPckt->GetBillboardState());
   switch(InPckt->GetBillboardState())
   {
   case 0:
      printf("NotBillboard\n");
      break;
   case 1:
      printf("Billboard\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tPerspective Growth = %d : ",InPckt->GetPerspectiveGrowth());
   switch(InPckt->GetPerspectiveGrowth())
   {
   case 0:
      printf("Disable\n");
      break;
   case 1:
      printf("Enable\n");
      break;
   default:
      printf("\n");
      break;
   }

   if(InPckt->GetAttached() == CigiBaseSymbolSurfaceDef::EntityAttached)
   {
      printf("\tEntity ID = %d\n",InPckt->GetEntityID());
      printf("\tX Offset = %f\n",InPckt->GetXOffset());
      printf("\tY Offset = %f\n",InPckt->GetYOffset());
      printf("\tZ Offset = %f\n",InPckt->GetZOffset());
      printf("\tYaw = %f\n",InPckt->GetYaw());
      printf("\tPitch = %f\n",InPckt->GetPitch());
      printf("\tRoll = %f\n",InPckt->GetRoll());
      printf("\tWidth = %f\n",InPckt->GetWidth());
      printf("\tHeight = %f\n",InPckt->GetHeight());
   }
   else
   {
      printf("\tView ID = %d\n",InPckt->GetViewID());
      printf("\tLeft Edge Position = %f\n",InPckt->GetLeftEdgePosition());
      printf("\tRight Edge Position = %f\n",InPckt->GetRightEdgePosition());
      printf("\tTop Edge Position = %f\n",InPckt->GetTopEdgePosition());
      printf("\tBottom Edge Position = %f\n",InPckt->GetBottomEdgePosition());
   }

   printf("\tMinimum U Coordinate = %f\n",InPckt->GetMinU());
   printf("\tMaximum U Coordinate = %f\n",InPckt->GetMaxU());
   printf("\tMinimum V Coordinate = %f\n",InPckt->GetMinV());
   printf("\tMaximum V Coordinate = %f\n",InPckt->GetMaxV());

}

