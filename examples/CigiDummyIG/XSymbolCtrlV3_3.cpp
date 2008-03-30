// XSymbolCtrlV3_3.cpp: Body of the XSymbolCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSymbolCtrlV3_3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSymbolCtrlV3_3::XSymbolCtrlV3_3()
{

}

XSymbolCtrlV3_3::~XSymbolCtrlV3_3()
{

}


void XSymbolCtrlV3_3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSymbolCtrlV3_3 *InPckt = (CigiSymbolCtrlV3_3 *)Packet;

   printf("Symbol Control:\n");

   printf("\tSymbol ID = %d\n",InPckt->GetSymbolID());

   printf("\tSymbol State = %d : ",InPckt->GetSymbolState());
   switch(InPckt->GetSymbolState())
   {
   case 0:
      printf("Hidden\n");
      break;
   case 1:
      printf("Visible\n");
      break;
   case 2:
      printf("Destroyed\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tAttach State = %d : ",InPckt->GetAttachState());
   switch(InPckt->GetAttachState())
   {
   case 0:
      printf("Detach\n");
      break;
   case 1:
      printf("Attach\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tFlash Control = %d : ",InPckt->GetFlashCtrl());
   switch(InPckt->GetFlashCtrl())
   {
   case 0:
      printf("Continue\n");
      break;
   case 1:
      printf("Reset\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tInherit Color = %d : ",InPckt->GetInheritColor());
   switch(InPckt->GetInheritColor())
   {
   case 0:
      printf("NotInherit\n");
      break;
   case 1:
      printf("Inherit\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tParent ID = %d\n",InPckt->GetParentSymbolID());
   printf("\tSurface ID = %d\n",InPckt->GetSurfaceID());
   printf("\tLayer ID = %d\n",InPckt->GetLayer());
   printf("\tFlash Duty Cycle percentage = %d\n",InPckt->GetFlashDutyCycle());
   printf("\tFlash Period = %f\n",InPckt->GetFlashPeriod());
   printf("\tU Position = %f\n",InPckt->GetUPosition());
   printf("\tV Position = %f\n",InPckt->GetVPosition());
   printf("\tRotation = %f\n",InPckt->GetRotation());
   printf("\tRed = %d\n",InPckt->GetRed());
   printf("\tGreen = %d\n",InPckt->GetGreen());
   printf("\tBlue = %d\n",InPckt->GetBlue());
   printf("\tAlpha = %d\n",InPckt->GetAlpha());
   printf("\tU Scale = %f\n",InPckt->GetScaleU());
   printf("\tV Scale = %f\n",InPckt->GetScaleV());

}

