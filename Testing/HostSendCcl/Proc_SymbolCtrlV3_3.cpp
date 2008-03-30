// Proc_SymbolCtrlV3_3.cpp: implementation of the Proc_SymbolCtrlV3_3 Parsing
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


#include "Proc_SymbolCtrlV3_3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SymbolCtrlV3_3::Proc_SymbolCtrlV3_3()
{
   PcktID = "SymbolCtrl";
}

Proc_SymbolCtrlV3_3::~Proc_SymbolCtrlV3_3()
{
}


void Proc_SymbolCtrlV3_3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;

   bool EntAt = true;

   pPV = pPV->nxt();  // skip the cmd name

   printf("Symbol Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_SymbolCtrl.SetSymbolID(pPV->GetUShort(),true);
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
         if(strcmp("Hidden",pPV->GetStr()) == 0)
         {
            Om_SymbolCtrl.SetSymbolState(CigiBaseSymbolCtrl::Hidden,true);
            printf("\tSymbol State = 0 : Hidden\n");
         }
         else if(strcmp("Visible",pPV->GetStr()) == 0)
         {
            Om_SymbolCtrl.SetSymbolState(CigiBaseSymbolCtrl::Visible,true);
            printf("\tSymbol State = 1 : Visible\n");
         }
         else if(strcmp("Destroyed",pPV->GetStr()) == 0)
         {
            Om_SymbolCtrl.SetSymbolState(CigiBaseSymbolCtrl::Destroyed,true);
            printf("\tSymbol State = 2 : Destroyed\n");
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
         if(strcmp("Detach",pPV->GetStr()) == 0)
         {
            Om_SymbolCtrl.SetAttachState(CigiBaseSymbolCtrl::Detach,true);
            printf("\tAttach State = 0 : Detach\n");
         }
         else if(strcmp("Attach",pPV->GetStr()) == 0)
         {
            Om_SymbolCtrl.SetAttachState(CigiBaseSymbolCtrl::Attach,true);
            printf("\tAttach State = 1 : Attach\n");
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
         if(strcmp("Continue",pPV->GetStr()) == 0)
         {
            Om_SymbolCtrl.SetFlashCtrl(CigiBaseSymbolCtrl::Continue,true);
            printf("\tFlash Control = 0 : Continue\n");
         }
         else if(strcmp("Reset",pPV->GetStr()) == 0)
         {
            Om_SymbolCtrl.SetFlashCtrl(CigiBaseSymbolCtrl::Reset,true);
            printf("\tFlash Control = 1 : Reset\n");
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
         if(strcmp("NotInherit",pPV->GetStr()) == 0)
         {
            Om_SymbolCtrl.SetInheritColor(CigiBaseSymbolCtrl::NotInherit,true);
            printf("\tInherit Color = 0 : NotInherit\n");
         }
         else if(strcmp("Inherit",pPV->GetStr()) == 0)
         {
            Om_SymbolCtrl.SetInheritColor(CigiBaseSymbolCtrl::Inherit,true);
            printf("\tInherit Color = 1 : Inherit\n");
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
         Om_SymbolCtrl.SetParentSymbolID(pPV->GetUShort(),true);
         printf("\tParent ID = %d\n",pPV->GetUShort());
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
         Om_SymbolCtrl.SetSurfaceID(pPV->GetUShort(),true);
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
         Om_SymbolCtrl.SetLayer(pPV->GetUChar(),true);
         printf("\tLayer ID = %d\n",pPV->GetUChar());
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
         Om_SymbolCtrl.SetFlashDutyCycle(pPV->GetUChar(),true);
         printf("\tFlash Duty Cycle percentage = %d\n",pPV->GetUChar());
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
         Om_SymbolCtrl.SetFlashPeriod(pPV->Getfloat(),true);
         printf("\tFlash Period = %f\n",pPV->Getfloat());
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
         Om_SymbolCtrl.SetUPosition(pPV->Getfloat(),true);
         printf("\tU Position = %f\n",pPV->Getfloat());
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
         Om_SymbolCtrl.SetVPosition(pPV->Getfloat(),true);
         printf("\tV Position = %f\n",pPV->Getfloat());
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
         Om_SymbolCtrl.SetRotation(pPV->Getfloat(),true);
         printf("\tRotation = %f\n",pPV->Getfloat());
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
         Om_SymbolCtrl.SetRed(pPV->GetUChar(),true);
         printf("\tRed = %d\n",pPV->GetUChar());
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
         Om_SymbolCtrl.SetGreen(pPV->GetUChar(),true);
         printf("\tGreen = %d\n",pPV->GetUChar());
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
         Om_SymbolCtrl.SetBlue(pPV->GetUChar(),true);
         printf("\tBlue = %d\n",pPV->GetUChar());
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
         Om_SymbolCtrl.SetAlpha(pPV->GetUChar(),true);
         printf("\tAlpha = %d\n",pPV->GetUChar());
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
         Om_SymbolCtrl.SetScaleU(pPV->Getfloat(),true);
         printf("\tU Scale = %f\n",pPV->Getfloat());
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
         Om_SymbolCtrl.SetScaleV(pPV->Getfloat(),true);
         printf("\tV Scale = %f\n",pPV->Getfloat());
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


   *Omsg << Om_SymbolCtrl;

}


