// Proc_MaritimeSurfaceCtrlV3.cpp: implementation of the Proc_MaritimeSurfaceCtrlV3 Parsing
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


#include "Proc_MaritimeSurfaceCtrlV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_MaritimeSurfaceCtrlV3::Proc_MaritimeSurfaceCtrlV3()
{
   PcktID = "MaritimeSurfaceCtrl";
}

Proc_MaritimeSurfaceCtrlV3::~Proc_MaritimeSurfaceCtrlV3()
{
}


void Proc_MaritimeSurfaceCtrlV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Maritime Surface Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_MaritimeSurfaceCtrl.SetEntityRgnID(pPV->GetUShort(),true);
         printf("\tEntity Region ID = %d\n",pPV->GetUShort());
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
         Om_MaritimeSurfaceCtrl.SetSurfaceCondEn(pPV->GetBool(),true);
         printf("\tSurface Conditions Enable = %d\n",pPV->GetBool());
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
         Om_MaritimeSurfaceCtrl.SetWhitecapEn(pPV->GetBool(),true);
         printf("\tWhite Cap Enable = %d\n",pPV->GetBool());
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
         if(strcmp("Global",pPV->GetStr()) == 0)
         {
            Om_MaritimeSurfaceCtrl.SetScope(CigiBaseMaritimeSurfaceCtrl::Global,true);
            printf("\tScope = 0 : Global\n");
         }
         else if(strcmp("Regional",pPV->GetStr()) == 0)
         {
            Om_MaritimeSurfaceCtrl.SetScope(CigiBaseMaritimeSurfaceCtrl::Regional,true);
            printf("\tScope = 1 : Regional\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_MaritimeSurfaceCtrl.SetScope(CigiBaseMaritimeSurfaceCtrl::Entity,true);
            printf("\tScope = 2 : Entity\n");
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
         Om_MaritimeSurfaceCtrl.SetSurfaceHeight(pPV->Getfloat(),true);
         printf("\tSurface Height = %f\n",pPV->Getfloat());
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
         Om_MaritimeSurfaceCtrl.SetWaterTemp(pPV->Getfloat(),true);
         printf("\tWater Temperature = %f\n",pPV->Getfloat());
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
         Om_MaritimeSurfaceCtrl.SetClarity(pPV->Getfloat(),true);
         printf("\tClarity = %f\n",pPV->Getfloat());
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


   *Omsg << Om_MaritimeSurfaceCtrl;

}


