// Proc_SymbolSurfaceDefV3_3.cpp: implementation of the Proc_SymbolSurfaceDefV3_3 Parsing
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


#include "Proc_SymbolSurfaceDefV3_3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SymbolSurfaceDefV3_3::Proc_SymbolSurfaceDefV3_3()
{
   PcktID = "SymbolSurfaceDef";
}

Proc_SymbolSurfaceDefV3_3::~Proc_SymbolSurfaceDefV3_3()
{
}


void Proc_SymbolSurfaceDefV3_3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;

   bool EntAt = true;

   pPV = pPV->nxt();  // skip the cmd name

   printf("Symbol Surface Definition:\n");


   if(pPV != NULL)
   {
      try
      {
         Om_SymbolSurfaceDef.SetSurfaceID(pPV->GetUShort(),true);
         printf("\tSurface ID = %d\n",pPV->GetUShort());
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
         if(strcmp("Active",pPV->GetStr()) == 0)
         {
            Om_SymbolSurfaceDef.SetSurfaceState(CigiBaseSymbolSurfaceDef::Active,true);
            printf("\tSurface State = 0 : Active\n");
         }
         else if(strcmp("Destroyed",pPV->GetStr()) == 0)
         {
            Om_SymbolSurfaceDef.SetSurfaceState(CigiBaseSymbolSurfaceDef::Destroyed,true);
            printf("\tSurface State = 1 : Destroyed\n");
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
         if(strcmp("EntityAttached",pPV->GetStr()) == 0)
         {
            Om_SymbolSurfaceDef.SetAttached(CigiBaseSymbolSurfaceDef::EntityAttached,true);
            printf("\tAttach State = 0 : EntityAttached\n");
         }
         else if(strcmp("ViewAttached",pPV->GetStr()) == 0)
         {
            Om_SymbolSurfaceDef.SetAttached(CigiBaseSymbolSurfaceDef::ViewAttached,true);
            printf("\tAttach State = 1 : ViewAttached\n");
            EntAt = false;
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
         if(strcmp("NotBillboard",pPV->GetStr()) == 0)
         {
            Om_SymbolSurfaceDef.SetBillboardState(CigiBaseSymbolSurfaceDef::NotBillboard,true);
            printf("\tBillBoard State = 0 : NotBillboard\n");
         }
         else if(strcmp("Billboard",pPV->GetStr()) == 0)
         {
            Om_SymbolSurfaceDef.SetBillboardState(CigiBaseSymbolSurfaceDef::Billboard,true);
            printf("\tBillBoard State = 1 : Billboard\n");
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
         if(strcmp("Disable",pPV->GetStr()) == 0)
         {
            Om_SymbolSurfaceDef.SetPerspectiveGrowth(CigiBaseSymbolSurfaceDef::Disable,true);
            printf("\tPerspective Growth = 0 : Disable\n");
         }
         else if(strcmp("Enable",pPV->GetStr()) == 0)
         {
            Om_SymbolSurfaceDef.SetPerspectiveGrowth(CigiBaseSymbolSurfaceDef::Enable,true);
            printf("\tPerspective Growth = 1 : Enable\n");
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }



   if(EntAt)
   {
      if(pPV != NULL)
      {
         try
         {
            Om_SymbolSurfaceDef.SetEntityID(pPV->GetUShort(),true);
            printf("\tEntity ID = %d\n",pPV->GetUShort());
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
            Om_SymbolSurfaceDef.SetXOffset(pPV->Getfloat(),true);
            printf("\tX Offset = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetYOffset(pPV->Getfloat(),true);
            printf("\tY Offset = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetZOffset(pPV->Getfloat(),true);
            printf("\tZ Offset = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetYaw(pPV->Getfloat(),true);
            printf("\tYaw = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetPitch(pPV->Getfloat(),true);
            printf("\tPitch = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetRoll(pPV->Getfloat(),true);
            printf("\tRoll = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetWidth(pPV->Getfloat(),true);
            printf("\tWidth = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetHeight(pPV->Getfloat(),true);
            printf("\tHeight = %f\n",pPV->Getfloat());
         }
         catch(CigiValueOutOfRangeException ORX)
         {
            if(ORX.HasMessage())
               printf("%s\n",ORX.what());
         }

         pPV = pPV->nxt();
      }
   }
   else
   {
      if(pPV != NULL)
      {
         try
         {
            Om_SymbolSurfaceDef.SetViewID(pPV->GetUShort(),true);
            printf("\tView ID = %d\n",pPV->GetUShort());
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
            Om_SymbolSurfaceDef.SetLeftEdgePosition(pPV->Getfloat(),true);
            printf("\tLeft Edge Position = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetRightEdgePosition(pPV->Getfloat(),true);
            printf("\tRight Edge Position = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetTopEdgePosition(pPV->Getfloat(),true);
            printf("\tTop Edge Position = %f\n",pPV->Getfloat());
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
            Om_SymbolSurfaceDef.SetBottomEdgePosition(pPV->Getfloat(),true);
            printf("\tBottom Edge Position = %f\n",pPV->Getfloat());
         }
         catch(CigiValueOutOfRangeException ORX)
         {
            if(ORX.HasMessage())
               printf("%s\n",ORX.what());
         }

         pPV = pPV->nxt();
      }


      Om_SymbolSurfaceDef.SetPitch(0.0f,true);
      Om_SymbolSurfaceDef.SetRoll(0.0f,true);
      Om_SymbolSurfaceDef.SetWidth(0.0f,true);
      Om_SymbolSurfaceDef.SetHeight(0.0f,true);

   }


   if(pPV != NULL)
   {
      try
      {
         Om_SymbolSurfaceDef.SetMinU(pPV->Getfloat(),true);
         printf("\tMinimum U Coordinate = %f\n",pPV->Getfloat());
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
         Om_SymbolSurfaceDef.SetMaxU(pPV->Getfloat(),true);
         printf("\tMaximum U Coordinate = %f\n",pPV->Getfloat());
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
         Om_SymbolSurfaceDef.SetMinV(pPV->Getfloat(),true);
         printf("\tMinimum V Coordinate = %f\n",pPV->Getfloat());
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
         Om_SymbolSurfaceDef.SetMaxV(pPV->Getfloat(),true);
         printf("\tMaximum V Coordinate = %f\n",pPV->Getfloat());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }


   if(pPV != NULL)
      DefHex = pPV->GetStr();


   *Omsg << Om_SymbolSurfaceDef;

}


