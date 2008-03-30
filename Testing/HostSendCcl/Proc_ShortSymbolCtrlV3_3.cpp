// Proc_ShortSymbolCtrlV3_3.cpp: implementation of the Proc_ShortSymbolCtrlV3_3 Parsing
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


#include "Proc_ShortSymbolCtrlV3_3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_ShortSymbolCtrlV3_3::Proc_ShortSymbolCtrlV3_3()
{
   PcktID = "ShortSymbolCtrl";
}

Proc_ShortSymbolCtrlV3_3::~Proc_ShortSymbolCtrlV3_3()
{
}


void Proc_ShortSymbolCtrlV3_3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;

   bool EntAt = true;

   pPV = pPV->nxt();  // skip the cmd name

   printf("Short Symbol Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_ShortSymbolCtrl.SetSymbolID(pPV->GetUShort(),true);
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
            Om_ShortSymbolCtrl.SetSymbolState(CigiBaseSymbolCtrl::Hidden,true);
            printf("\tSymbol State = 0 : Hidden\n");
         }
         else if(strcmp("Visible",pPV->GetStr()) == 0)
         {
            Om_ShortSymbolCtrl.SetSymbolState(CigiBaseSymbolCtrl::Visible,true);
            printf("\tSymbol State = 1 : Visible\n");
         }
         else if(strcmp("Destroyed",pPV->GetStr()) == 0)
         {
            Om_ShortSymbolCtrl.SetSymbolState(CigiBaseSymbolCtrl::Destroyed,true);
            printf("\tSymbol State = 1 : Destroyed\n");
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
            Om_ShortSymbolCtrl.SetAttachState(CigiBaseSymbolCtrl::Detach,true);
            printf("\tAttach State = 0 : Detach\n");
         }
         else if(strcmp("Attach",pPV->GetStr()) == 0)
         {
            Om_ShortSymbolCtrl.SetAttachState(CigiBaseSymbolCtrl::Attach,true);
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
            Om_ShortSymbolCtrl.SetFlashCtrl(CigiBaseSymbolCtrl::Continue,true);
            printf("\tFlash Control = 0 : Continue\n");
         }
         else if(strcmp("Reset",pPV->GetStr()) == 0)
         {
            Om_ShortSymbolCtrl.SetFlashCtrl(CigiBaseSymbolCtrl::Reset,true);
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
            Om_ShortSymbolCtrl.SetInheritColor(CigiBaseSymbolCtrl::NotInherit,true);
            printf("\tInherit Color = 0 : NotInherit\n");
         }
         else if(strcmp("Inherit",pPV->GetStr()) == 0)
         {
            Om_ShortSymbolCtrl.SetInheritColor(CigiBaseSymbolCtrl::Inherit,true);
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


   int tDatumId = 0;

   for(tDatumId=0;tDatumId<2;tDatumId++)
   {
      if(pPV != NULL)
      {
         try
         {
            if(strcmp("None",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 0 : None\n",tDatumId);
               Om_ShortSymbolCtrl.SetDatumNone(tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
            }
            else if(strcmp("SurfaceIdDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 1 : SurfaceIdDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetSurfaceID(tDatumId,pPV->GetUShort());
               printf("\tDatum %d: Surface ID = %d\n",tDatumId,pPV->GetUShort());
            }
            else if(strcmp("ParentIdDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 2 : ParentIdDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetParentSymbolID(tDatumId,pPV->GetUShort());
               printf("\tDatum %d: Parent ID = %d\n",tDatumId,pPV->GetUShort());
            }
            else if(strcmp("LayerDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 3 : LayerDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetLayer(tDatumId,pPV->GetUChar());
               printf("\tDatum %d: Layer = %d\n",tDatumId,pPV->GetUChar());
            }
            else if(strcmp("FlashDutyCycleDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 4 : FlashDutyCycleDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetFlashDutyCycle(tDatumId,pPV->GetUChar());
               printf("\tDatum %d: Flash Duty Cycle = %d\n",tDatumId,pPV->GetUChar());
            }
            else if(strcmp("FlashPeriodDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 5 : FlashPeriodDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetFlashPeriod(tDatumId,pPV->Getfloat());
               printf("\tDatum %d: Flash Period = %f\n",tDatumId,pPV->Getfloat());
            }
            else if(strcmp("UPositionDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 6 : UPositionDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetUPosition(tDatumId,pPV->Getfloat());
               printf("\tDatum %d: U Position = %f\n",tDatumId,pPV->Getfloat());
            }
            else if(strcmp("VPositionDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 7 : VPositionDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetVPosition(tDatumId,pPV->Getfloat());
               printf("\tDatum %d: V Position = %f\n",tDatumId,pPV->Getfloat());
            }
            else if(strcmp("RotationDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 8 : RotationDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetRotation(tDatumId,pPV->Getfloat());
               printf("\tDatum %d: Rotation = %f\n",tDatumId,pPV->Getfloat());
            }
            else if(strcmp("ColorDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 9 : ColorDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Cigi_uint8 tRed,tGreen,tBlue,tAlpha;
               tRed = tGreen = tBlue = tAlpha = 0;
               tRed = pPV->GetUChar();
               if((pPV = pPV->nxt()) == NULL) break;
               tGreen = pPV->GetUChar();
               if((pPV = pPV->nxt()) == NULL) break;
               tBlue = pPV->GetUChar();
               if((pPV = pPV->nxt()) == NULL) break;
               tAlpha = pPV->GetUChar();

               Om_ShortSymbolCtrl.SetColor(tDatumId,
                  tRed,tGreen,tBlue,tAlpha);
               printf("\tDatum %d: Color:\n\t\t=> Red = %d\n\t\t=> Green = %d\n\t\t=> Blue = %d\n\t\t=> Alpha = %d\n",
                  tDatumId,tRed,tGreen,tBlue,tAlpha);
            }
            else if(strcmp("ScaleUDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 10 : ScaleUDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetScaleU(tDatumId,pPV->Getfloat());
               printf("\tDatum %d: U Scale = %f\n",tDatumId,pPV->Getfloat());
            }
            else if(strcmp("ScaleVDatumType",pPV->GetStr()) == 0)
            {
               printf("\tDatum %d type = 11 : ScaleVDatumType\n",tDatumId);
               if((pPV = pPV->nxt()) == NULL) break;
               Om_ShortSymbolCtrl.SetScaleV(tDatumId,pPV->Getfloat());
               printf("\tDatum %d: V Scale = %f\n",tDatumId,pPV->Getfloat());
            }
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


   *Omsg << Om_ShortSymbolCtrl;

}


