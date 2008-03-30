// Proc_TerrestrialSurfaceCtrlV3.cpp: implementation of the Proc_TerrestrialSurfaceCtrlV3 Parsing
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


#include "Proc_TerrestrialSurfaceCtrlV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_TerrestrialSurfaceCtrlV3::Proc_TerrestrialSurfaceCtrlV3()
{
   PcktID = "TerrestrialSurfaceCtrl";
}

Proc_TerrestrialSurfaceCtrlV3::~Proc_TerrestrialSurfaceCtrlV3()
{
}


void Proc_TerrestrialSurfaceCtrlV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Terrestrial Surface Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_TerrestrialSurfaceCtrl.SetEntityRgnID(pPV->GetUShort(),true);
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
         Om_TerrestrialSurfaceCtrl.SetSurfaceCondID(pPV->GetUShort(),true);
         printf("\tSurface Condition ID = %d\n",pPV->GetUShort());
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
         Om_TerrestrialSurfaceCtrl.SetSurfaceCondEn(pPV->GetBool(),true);
         printf("\tSurface Condition Enable = %d\n",pPV->GetBool());
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
            Om_TerrestrialSurfaceCtrl.SetScope(CigiBaseTerrestrialSurfaceCtrl::Global,true);
            printf("\tScope = 0 : Global\n");
         }
         else if(strcmp("Regional",pPV->GetStr()) == 0)
         {
            Om_TerrestrialSurfaceCtrl.SetScope(CigiBaseTerrestrialSurfaceCtrl::Regional,true);
            printf("\tScope = 1 : Regional\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_TerrestrialSurfaceCtrl.SetScope(CigiBaseTerrestrialSurfaceCtrl::Entity,true);
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
         Om_TerrestrialSurfaceCtrl.SetSeverity(pPV->GetUChar(),true);
         printf("\tSeverity = %d\n",pPV->GetUChar());
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
         Om_TerrestrialSurfaceCtrl.SetCoverage(pPV->GetUChar(),true);
         printf("\tCoverage = %d\n",pPV->GetUChar());
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


   *Omsg << Om_TerrestrialSurfaceCtrl;

}


