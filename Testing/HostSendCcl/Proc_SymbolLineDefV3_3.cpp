// Proc_SymbolLineDefV3_3.cpp: implementation of the Proc_SymbolLineDefV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"


#ifndef _WIN32
    #include <fstream>
#elif _MSC_VER > 1300
    #include <fstream>
#else
    #include <fstream.h>
#endif


#include "Proc_SymbolLineDefV3_3.h"
#include "CigiVertexSymbolDataV3_3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SymbolLineDefV3_3::Proc_SymbolLineDefV3_3()
{
   PcktID = "SymbolLineDef";
}

Proc_SymbolLineDefV3_3::~Proc_SymbolLineDefV3_3()
{
}


void Proc_SymbolLineDefV3_3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;

   bool EntAt = true;

   pPV = pPV->nxt();  // skip the cmd name

   printf("Symbol Line Definition:\n");

   Om_SymbolLineDef.ClearVertices();

   if(pPV != NULL)
   {
      try
      {
         Om_SymbolLineDef.SetSymbolID(pPV->GetUShort(),true);
         printf("\tSymbol ID = %d\n",pPV->GetUShort());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         if(strcmp("Points",pPV->GetStr()) == 0)
         {
            Om_SymbolLineDef.SetPrimitive(CigiBaseSymbolLineDef::Points,true);
            printf("\tDrawing Primitive = 0 : Points\n");
         }
         else if(strcmp("Lines",pPV->GetStr()) == 0)
         {
            Om_SymbolLineDef.SetPrimitive(CigiBaseSymbolLineDef::Lines,true);
            printf("\tDrawing Primitive = 1 : Lines\n");
         }
         else if(strcmp("LineStrip",pPV->GetStr()) == 0)
         {
            Om_SymbolLineDef.SetPrimitive(CigiBaseSymbolLineDef::LineStrip,true);
            printf("\tDrawing Primitive = 2 : LineStrip\n");
         }
         else if(strcmp("LineLoop",pPV->GetStr()) == 0)
         {
            Om_SymbolLineDef.SetPrimitive(CigiBaseSymbolLineDef::LineLoop,true);
            printf("\tDrawing Primitive = 3 : LineLoop\n");
         }
         else if(strcmp("Triangles",pPV->GetStr()) == 0)
         {
            Om_SymbolLineDef.SetPrimitive(CigiBaseSymbolLineDef::Triangles,true);
            printf("\tDrawing Primitive = 4 : Triangles\n");
         }
         else if(strcmp("TriangleStrip",pPV->GetStr()) == 0)
         {
            Om_SymbolLineDef.SetPrimitive(CigiBaseSymbolLineDef::TriangleStrip,true);
            printf("\tDrawing Primitive = 5 : TriangleStrip\n");
         }
         else if(strcmp("TriangleFan",pPV->GetStr()) == 0)
         {
            Om_SymbolLineDef.SetPrimitive(CigiBaseSymbolLineDef::TriangleFan,true);
            printf("\tDrawing Primitive = 6 : TriangleFan\n");
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SymbolLineDef.SetStipplePattern(pPV->GetUShort(),true);
         printf("\tStipple Pattern = %d\n",pPV->GetUShort());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SymbolLineDef.SetLineWidth(pPV->Getfloat(),true);
         printf("\tLine Width = %f\n",pPV->Getfloat());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      try
      {
         Om_SymbolLineDef.SetStipplePatternLen(pPV->Getfloat(),true);
         printf("\tStipple Pattern Length = %f\n",pPV->Getfloat());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   CigiVertexSymbolDataV3_3 *VertexDta;

   while((pPV != NULL)&&(*(pPV->GetStr()) != 0))
   {
      VertexDta = (CigiVertexSymbolDataV3_3 *)Om_SymbolLineDef.AddVertex();

      if(pPV != NULL)
      {
         try
         {
            VertexDta->SetVertexU(pPV->Getfloat(),true);
            printf("\tVertex U Position = %f\n",pPV->Getfloat());
         }
         catch(CigiValueOutOfRangeException ORX)
         {
            if(ORX.HasMessage())
               printf("%s\n",ORX.what());
         }

         pPV = pPV->nxt();
      }

      if(pPV != NULL)
      {
         try
         {
            VertexDta->SetVertexV(pPV->Getfloat(),true);
            printf("\tVertex V Position = %f\n",pPV->Getfloat());
         }
         catch(CigiValueOutOfRangeException ORX)
         {
            if(ORX.HasMessage())
               printf("%s\n",ORX.what());
         }

         pPV = pPV->nxt();
      }

   }


   if(pPV != NULL)
      DefHex = pPV->GetStr();


   *Omsg << Om_SymbolLineDef;

}


