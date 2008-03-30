// Proc_EntityCtrlV2.cpp: implementation of the Proc_EntityCtrlV2 Parsing
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


#include "Proc_EntityCtrlV2.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_EntityCtrlV2::Proc_EntityCtrlV2()
{
   PcktID = "EntityCtrl";
}

Proc_EntityCtrlV2::~Proc_EntityCtrlV2()
{
}


void Proc_EntityCtrlV2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Entity Control\n");

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_EntityCtrl.SetEntityID(pPV->GetUShort(),true);
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
         if(strcmp("Standby",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiEntityCtrlV2::LoadHideV2,true);
            printf("\tEntity State = 0 : LoadHideV2\n");
         }
         else if(strcmp("Active",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiEntityCtrlV2::LoadShowV2,true);
            printf("\tEntity State = 1 : LoadShowV2\n");
         }
         else if(strcmp("Remove",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiEntityCtrlV2::UnloadV2,true);
            printf("\tEntity State = 2 : UnloadV2\n");
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
            Om_EntityCtrl.SetAttachState(CigiBaseEntityCtrl::Detach,true);
            printf("\tAttach State = 0 : Detach\n");
         }
         else if(strcmp("Attach",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAttachState(CigiBaseEntityCtrl::Attach,true);
            printf("\tAttach State = 1 : Attach\n");
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
            Om_EntityCtrl.SetCollisionDetectEn(CigiBaseEntityCtrl::Disable,true);
            printf("\tCollision Detection Enable = 0 : Disable\n");
         }
         else if(strcmp("Enable",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetCollisionDetectEn(CigiBaseEntityCtrl::Enable,true);
            printf("\tCollision Detection Enable = 1 : Enable\n");
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
         if(strcmp("Stop",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEffectState(CigiEntityCtrlV2::StopV2,true);
            printf("\tAnimation State = 0 : StopV2\n");
         }
         else if(strcmp("Play",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEffectState(CigiEntityCtrlV2::PlayV2,true);
            printf("\tAnimation State = 1 : PlayV2\n");
         }
         else if(strcmp("Restart",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEffectState(CigiEntityCtrlV2::RestartV2,true);
            printf("\tAnimation State = 2 : RestartV2\n");
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
         Om_EntityCtrl.SetEntityType(pPV->GetUShort(),true);
         printf("\tEntity Type = %d\n",pPV->GetUShort());
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
         Om_EntityCtrl.SetParentID(pPV->GetUShort(),true);
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
         Om_EntityCtrl.SetOpacity(pPV->Getfloat(),true);
         printf("\tOpacity = %f\n",pPV->Getfloat());
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
         Om_EntityCtrl.SetTemp(pPV->Getfloat(),true);
         printf("\tTemperature = %f\n",pPV->Getfloat());
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
         Om_EntityCtrl.SetRoll(pPV->Getfloat(),true);
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
         Om_EntityCtrl.SetPitch(pPV->Getfloat(),true);
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
         Om_EntityCtrl.SetHeading(pPV->Getfloat(),true);
         printf("\tHeading = %f\n",pPV->Getfloat());
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
         Om_EntityCtrl.SetXoff(pPV->Getdouble(),true);
         printf("\tX Offset = %f\n",pPV->Getdouble());
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
         Om_EntityCtrl.SetYoff(pPV->Getdouble(),true);
         printf("\tY Offset = %f\n",pPV->Getdouble());
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
         Om_EntityCtrl.SetZoff(pPV->Getdouble(),true);
         printf("\tZ Offset = %f\n",pPV->Getdouble());
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


   *Omsg << Om_EntityCtrl;

}


