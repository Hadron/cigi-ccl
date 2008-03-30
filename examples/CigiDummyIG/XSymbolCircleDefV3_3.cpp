// XSymbolCircleDefV3_3.cpp: Body of the XSymbolCircleDefV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSymbolCircleDefV3_3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSymbolCircleDefV3_3::XSymbolCircleDefV3_3()
{

}

XSymbolCircleDefV3_3::~XSymbolCircleDefV3_3()
{

}


void XSymbolCircleDefV3_3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSymbolCircleDefV3_3 *InPckt = (CigiSymbolCircleDefV3_3 *)Packet;

   printf("Symbol Circle Definition:\n");

   printf("\tSymbol ID = %d\n",InPckt->GetSymbolID());

   printf("\tDrawing Style = %d : ",InPckt->GetDrawingStyle());
   switch(InPckt->GetDrawingStyle())
   {
   case 0:
      printf("Line\n");
      break;
   case 1:
      printf("Fill\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tStipple Pattern = %d\n",InPckt->GetStipplePattern());
   printf("\tLine Width = %f\n",InPckt->GetLineWidth());
   printf("\tStipple Pattern Length = %f\n",InPckt->GetStipplePatternLen());


   //   Circle Data
   int CircleCnt = InPckt->GetCircleCount();
   int ndx = 0;
   for(ndx=0;ndx<CircleCnt;ndx++)
   {
      CigiCircleSymbolDataV3_3 *Circle =
         (CigiCircleSymbolDataV3_3 *)InPckt->GetCircle(ndx);

      printf("\tCenter U Position = %f\n",Circle->GetCenterUPosition());
      printf("\tCenter V Position = %f\n",Circle->GetCenterVPosition());
      printf("\tRadius = %f\n",Circle->GetRadius());
      printf("\tInner Radius = %f\n",Circle->GetInnerRadius());
      printf("\tStart Angle = %f\n",Circle->GetStartAngle());
      printf("\tEnd Angle = %f\n",Circle->GetEndAngle());
   }

}

