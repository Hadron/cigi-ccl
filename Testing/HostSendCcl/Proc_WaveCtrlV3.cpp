// Proc_WaveCtrlV3.cpp: implementation of the Proc_WaveCtrlV3 Parsing
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


#include "Proc_WaveCtrlV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_WaveCtrlV3::Proc_WaveCtrlV3()
{
   PcktID = "WaveCtrl";
}

Proc_WaveCtrlV3::~Proc_WaveCtrlV3()
{
}


void Proc_WaveCtrlV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Wave Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_WaveCtrl.SetEntityRgnID(pPV->GetUShort(),true);
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
         Om_WaveCtrl.SetWaveID(pPV->GetUChar(),true);
         printf("\tWave ID = %d\n",pPV->GetUChar());
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
         Om_WaveCtrl.SetWaveEn(pPV->GetBool(),true);
         printf("\tWave Enable = %d\n",pPV->GetBool());
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
            Om_WaveCtrl.SetScope(CigiBaseWaveCtrl::Global,true);
            printf("\tScope = 0 : Global\n");
         }
         else if(strcmp("Regional",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetScope(CigiBaseWaveCtrl::Regional,true);
            printf("\tScope = 1 : Regional\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetScope(CigiBaseWaveCtrl::Entity,true);
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
         if(strcmp("Plunging",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetBreaker(CigiBaseWaveCtrl::Plunging,true);
            printf("\tBreaker = 0 : Plunging\n");
         }
         else if(strcmp("Spilling",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetBreaker(CigiBaseWaveCtrl::Spilling,true);
            printf("\tBreaker = 1 : Spilling\n");
         }
         else if(strcmp("Surging",pPV->GetStr()) == 0)
         {
            Om_WaveCtrl.SetBreaker(CigiBaseWaveCtrl::Surging,true);
            printf("\tBreaker = 2 : Surging\n");
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
         Om_WaveCtrl.SetWaveHt(pPV->Getfloat(),true);
         printf("\tWave Height = %f\n",pPV->Getfloat());
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
         Om_WaveCtrl.SetWaveLen(pPV->Getfloat(),true);
         printf("\tWavelength = %f\n",pPV->Getfloat());
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
         Om_WaveCtrl.SetPeriod(pPV->Getfloat(),true);
         printf("\tPeriod = %f\n",pPV->Getfloat());
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
         Om_WaveCtrl.SetDirection(pPV->Getfloat(),true);
         printf("\tDirection = %f\n",pPV->Getfloat());
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
         Om_WaveCtrl.SetPhaseOff(pPV->Getfloat(),true);
         printf("\tPhase Offset = %f\n",pPV->Getfloat());
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
         Om_WaveCtrl.SetLeading(pPV->Getfloat(),true);
         printf("\tLeading = %f\n",pPV->Getfloat());
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


   *Omsg << Om_WaveCtrl;

}


