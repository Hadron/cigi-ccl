// XSymbolLineDefV3_3.cpp: Body of the XSymbolLineDefV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSymbolLineDefV3_3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSymbolLineDefV3_3::XSymbolLineDefV3_3()
{

}

XSymbolLineDefV3_3::~XSymbolLineDefV3_3()
{

}


void XSymbolLineDefV3_3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSymbolLineDefV3_3 *InPckt = (CigiSymbolLineDefV3_3 *)Packet;

   printf("Symbol Line Definition:\n");

   printf("\tSymbol ID = %d\n",InPckt->GetSymbolID());

   printf("\tDrawing Primitive = %d : ",InPckt->GetPrimitive());
   switch(InPckt->GetPrimitive())
   {
   case 0:
      printf("Points\n");
      break;
   case 1:
      printf("Lines\n");
      break;
   case 2:
      printf("LineStrip\n");
      break;
   case 3:
      printf("LineLoop\n");
      break;
   case 4:
      printf("Triangles\n");
      break;
   case 5:
      printf("TriangleStrip\n");
      break;
   case 6:
      printf("TriangleFan\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tStipple Pattern = %d\n",InPckt->GetStipplePattern());
   printf("\tLine Width = %f\n",InPckt->GetLineWidth());
   printf("\tStipple Pattern Length = %f\n",InPckt->GetStipplePatternLen());


   //   Circle Data
   int VtxCnt = InPckt->GetVertexCount();
   int ndx = 0;
   for(ndx=0;ndx<VtxCnt;ndx++)
   {
      CigiVertexSymbolDataV3_3 *Vtx =
         (CigiVertexSymbolDataV3_3 *)InPckt->GetVertex(ndx);

      printf("\tVertex U Position = %f\n",Vtx->GetVertexU());
      printf("\tVertex V Position = %f\n",Vtx->GetVertexV());
   }

}

