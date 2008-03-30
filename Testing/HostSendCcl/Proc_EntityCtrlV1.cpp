// Proc_EntityCtrlV1.cpp: implementation of the Proc_EntityCtrlV1 Parsing
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


#include "Proc_EntityCtrlV1.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_EntityCtrlV1::Proc_EntityCtrlV1()
{
   PcktID = "EntityCtrl";
}

Proc_EntityCtrlV1::~Proc_EntityCtrlV1()
{
}


void Proc_EntityCtrlV1::ProcPckt(ParseValue *pPV)
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
         if(strcmp("Destruct",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiEntityCtrlV1::DestructV1,true);
            printf("\tEntity State = 0 : DestructV1\n");
         }
         else if(strcmp("Construct",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiEntityCtrlV1::ConstructV1,true);
            printf("\tEntity State = 1 : ConstructV1\n");
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
         if(strcmp("NoAction",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEffectState(CigiEntityCtrlV1::NoActionV1,true);
            printf("\tAnimation State = 0 : NoActionV1\n");
         }
         else if(strcmp("Load",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEffectState(CigiEntityCtrlV1::LoadV1,true);
            printf("\tAnimation State = 1 : LoadV1\n");
         }
         else if(strcmp("LoadActivate",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEffectState(CigiEntityCtrlV1::LoadActivateV1,true);
            printf("\tAnimation State = 2 : LoadActivateV1\n");
         }
         else if(strcmp("Activate",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEffectState(CigiEntityCtrlV1::ActivateV1,true);
            printf("\tAnimation State = 3 : ActivateV1\n");
         }
         else if(strcmp("Deactivate",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEffectState(CigiEntityCtrlV1::DeactivateV1,true);
            printf("\tAnimation State = 4 : DeactivateV1\n");
         }
         else if(strcmp("DeactivateUnload",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEffectState(CigiEntityCtrlV1::DeactivateUnloadV1,true);
            printf("\tAnimation State = 5 : DeactivateUnloadV1\n");
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
         Om_EntityCtrl.SetZoff(pPV->Getfloat(),true);
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
      DefHex = pPV->GetStr();


   *Omsg << Om_EntityCtrl;

}


