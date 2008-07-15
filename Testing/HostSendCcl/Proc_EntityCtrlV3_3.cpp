// Proc_EntityCtrlV3_3.cpp: implementation of the Proc_EntityCtrlV3_3 Parsing
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


#include "Proc_EntityCtrlV3_3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_EntityCtrlV3_3::Proc_EntityCtrlV3_3()
{
   PcktID = "EntityCtrl";
}

Proc_EntityCtrlV3_3::~Proc_EntityCtrlV3_3()
{
}


void Proc_EntityCtrlV3_3::ProcPckt(ParseValue *pPV)
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
            Om_EntityCtrl.SetEntityState(CigiBaseEntityCtrl::Standby,true);
            printf("\tEntity State = 0 : Standby\n");
         }
         else if(strcmp("Active",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiBaseEntityCtrl::Active,true);
            printf("\tEntity State = 1 : Active\n");
         }
         else if(strcmp("Remove",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetEntityState(CigiBaseEntityCtrl::Remove,true);
            printf("\tEntity State = 2 : Remove\n");
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
         if(strcmp("NoInherit",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetInheritAlpha(CigiBaseEntityCtrl::NoInherit,true);
            printf("\tInherit Alpha = 0 : NoInherit\n");
         }
         else if(strcmp("Inherit",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetInheritAlpha(CigiBaseEntityCtrl::Inherit,true);
            printf("\tInherit Alpha = 1 : Inherit\n");
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
         if(strcmp("NoClamp",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetGrndClamp(CigiBaseEntityCtrl::NoClamp,true);
            printf("\tGround Clamp = 0 : NoClamp\n");
         }
         else if(strcmp("AltClamp",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetGrndClamp(CigiBaseEntityCtrl::AltClamp,true);
            printf("\tGround Clamp = 1 : Altitude Clamp\n");
         }
         else if(strcmp("AltAttClamp",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetGrndClamp(CigiBaseEntityCtrl::AltAttClamp,true);
            printf("\tGround Clamp = 2 : Conformal Clamp\n");
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
         if(strcmp("Forward",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationDir(CigiBaseEntityCtrl::Forward,true);
            printf("\tAnimation Direction = 0 : Forward\n");
         }
         else if(strcmp("Backward",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationDir(CigiBaseEntityCtrl::Backward,true);
            printf("\tAnimation Direction = 1 : Backward\n");
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
         if(strcmp("OneShot",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationLoopMode(CigiBaseEntityCtrl::OneShot,true);
            printf("\tAnimation Loop Mode = 0 : OneShot\n");
         }
         else if(strcmp("Continuous",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationLoopMode(CigiBaseEntityCtrl::Continuous,true);
            printf("\tAnimation Loop Mode = 1 : Continuous\n");
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
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Stop,true);
            printf("\tAnimation State = 0 : Stop\n");
         }
         else if(strcmp("Pause",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Pause,true);
            printf("\tAnimation State = 1 : Pause\n");
         }
         else if(strcmp("Play",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Play,true);
            printf("\tAnimation State = 2 : Play\n");
         }
         else if(strcmp("Continue",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Continue,true);
            printf("\tAnimation State = 3 : Continue\n");
         }
         else if(strcmp("NoAction",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::NoAction,true);
            printf("\tAnimation State = NoAction\n");
         }
         else if(strcmp("Load",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Load,true);
            printf("\tAnimation State = Load\n");
         }
         else if(strcmp("LoadActivate",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::LoadActivate,true);
            printf("\tAnimation State = LoadActivate\n");
         }
         else if(strcmp("Activate",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Activate,true);
            printf("\tAnimation State = Activate\n");
         }
         else if(strcmp("Deactivate",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::Deactivate,true);
            printf("\tAnimation State = Deactivate\n");
         }
         else if(strcmp("DeactivateUnload",pPV->GetStr()) == 0)
         {
            Om_EntityCtrl.SetAnimationState(CigiBaseEntityCtrl::DeactivateUnload,true);
            printf("\tAnimation State = DeactivateUnload\n");
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
         Om_EntityCtrl.SetSmoothingEn(pPV->GetBool(),true);
         if(pPV->GetBool())
            printf("\tSmoothing Enabled\n");
         else
            printf("\tSmoothing Disabled\n");
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
         Om_EntityCtrl.SetAlpha(pPV->GetUChar(),true);
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
         Om_EntityCtrl.SetYaw(pPV->Getfloat(),true);
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


