// Proc_SpecialEffectV1.cpp: implementation of the Proc_SpecialEffectV1 Parsing
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


#include "Proc_SpecialEffectV1.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SpecialEffectV1::Proc_SpecialEffectV1()
{
   PcktID = "SpecialEffect";
}

Proc_SpecialEffectV1::~Proc_SpecialEffectV1()
{
}


void Proc_SpecialEffectV1::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Special Effect\n");

   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_SpecialEffect.SetEntityID(pPV->GetUShort(),true);
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
         if(strcmp("Forward",pPV->GetStr()) == 0)
         {
            Om_SpecialEffect.SetSeqDir(CigiBaseSpecEffDef::Forward,true);
            printf("\tSequence Direction = 0 : Forward\n");
         }
         else if(strcmp("Backward",pPV->GetStr()) == 0)
         {
            Om_SpecialEffect.SetSeqDir(CigiBaseSpecEffDef::Backward,true);
            printf("\tSequence Direction = 1 : Backward\n");
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
         Om_SpecialEffect.SetColorEn(pPV->GetBool(),true);
         printf("\tColor Enable = %d\n",pPV->GetBool());
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
         Om_SpecialEffect.SetRed(pPV->GetUChar(),true);
         printf("\tRed Component = %d\n",pPV->GetUChar());
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
         Om_SpecialEffect.SetGreen(pPV->GetUChar(),true);
         printf("\tGreen Component = %d\n",pPV->GetUChar());
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
         Om_SpecialEffect.SetBlue(pPV->GetUChar(),true);
         printf("\tBlue Component = %d\n",pPV->GetUChar());
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
         // Because X Scale gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_SpecialEffect.SetXScale(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tX Scale = %f\n",df);
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
         // Because Y Scale gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_SpecialEffect.SetYScale(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tY Scale = %f\n",df);
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
         // Because Z Scale gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_SpecialEffect.SetZScale(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tZ Scale = %f\n",df);
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
         // Because Time Scale gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_SpecialEffect.SetTimeScale(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tTime Scale = %f\n",df);
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
         Om_SpecialEffect.SetEffectCnt(pPV->GetUShort(),true);
         printf("\tEffect Count = %d\n",pPV->GetUShort());
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
         Om_SpecialEffect.SetSeparation(pPV->Getfloat(),true);
         printf("\tSeperation = %f\n",pPV->Getfloat());
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
         Om_SpecialEffect.SetBurstRate(pPV->Getfloat(),true);
         printf("\tBurst Rate = %f\n",pPV->Getfloat());
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
         Om_SpecialEffect.SetDuration(pPV->Getfloat(),true);
         printf("\tDuration = %f\n",pPV->Getfloat());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_SpecialEffect;

}


