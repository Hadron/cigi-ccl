// Proc_SymbolCircleDefV3_3.cpp: implementation of the Proc_SymbolCircleDefV3_3 Parsing
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


#include "Proc_SymbolCircleDefV3_3.h"
#include "CigiCircleSymbolDataV3_3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SymbolCircleDefV3_3::Proc_SymbolCircleDefV3_3()
{
   PcktID = "SymbolCircleDef";
}

Proc_SymbolCircleDefV3_3::~Proc_SymbolCircleDefV3_3()
{
}


void Proc_SymbolCircleDefV3_3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;

   bool EntAt = true;

   pPV = pPV->nxt();  // skip the cmd name

   printf("Symbol Circle Definition:\n");

   Om_SymbolCircleDef.ClearCircles();

   if(pPV != NULL)
   {
      try
      {
         Om_SymbolCircleDef.SetSymbolID(pPV->GetUShort(),true);
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
         if(strcmp("Line",pPV->GetStr()) == 0)
         {
            Om_SymbolCircleDef.SetDrawingStyle(CigiBaseSymbolCircleDef::Line,true);
            printf("\tDrawing Style = 0 : Line\n");
         }
         else if(strcmp("Fill",pPV->GetStr()) == 0)
         {
            Om_SymbolCircleDef.SetDrawingStyle(CigiBaseSymbolCircleDef::Fill,true);
            printf("\tDrawing Style = 1 : Fill\n");
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
         Om_SymbolCircleDef.SetStipplePattern(pPV->GetUShort(),true);
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
         Om_SymbolCircleDef.SetLineWidth(pPV->Getfloat(),true);
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
         Om_SymbolCircleDef.SetStipplePatternLen(pPV->Getfloat(),true);
         printf("\tStipple Pattern Length = %f\n",pPV->Getfloat());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   CigiCircleSymbolDataV3_3 *CircleDta;

   while((pPV != NULL)&&(*(pPV->GetStr()) != 0))
   {
      CircleDta = (CigiCircleSymbolDataV3_3 *)Om_SymbolCircleDef.AddCircle();

      if(pPV != NULL)
      {
         try
         {
            CircleDta->SetCenterUPosition(pPV->Getfloat(),true);
            printf("\tCenter U Position = %f\n",pPV->Getfloat());
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
            CircleDta->SetCenterVPosition(pPV->Getfloat(),true);
            printf("\tCenter V Position = %f\n",pPV->Getfloat());
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
            CircleDta->SetRadius(pPV->Getfloat(),true);
            printf("\tRadius = %f\n",pPV->Getfloat());
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
            CircleDta->SetInnerRadius(pPV->Getfloat(),true);
            printf("\tInner Radius = %f\n",pPV->Getfloat());
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
            CircleDta->SetStartAngle(pPV->Getfloat(),true);
            printf("\tStart Angle = %f\n",pPV->Getfloat());
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
            CircleDta->SetEndAngle(pPV->Getfloat(),true);
            printf("\tEnd Angle = %f\n",pPV->Getfloat());
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


   *Omsg << Om_SymbolCircleDef;

}


