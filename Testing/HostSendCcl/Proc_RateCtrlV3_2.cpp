// Proc_RateCtrlV3_2.cpp: implementation of the Proc_RateCtrlV3_2 Parsing
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


#include "Proc_RateCtrlV3_2.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_RateCtrlV3_2::Proc_RateCtrlV3_2()
{
   PcktID = "RateCtrl";
}

Proc_RateCtrlV3_2::~Proc_RateCtrlV3_2()
{
}


void Proc_RateCtrlV3_2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Rate Control\n");

   if(pPV != NULL)
   {
      try
      {
         Om_RateCtrl.SetEntityID(pPV->GetUShort(),true);
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
         Om_RateCtrl.SetArtPartID(pPV->GetUChar(),true);
         printf("\tArticulated Part ID = %d\n",pPV->GetUChar());
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
         Om_RateCtrl.SetApplyToArtPart(pPV->GetBool(),true);
         printf("\tApply to Articulated Part = %d\n",pPV->GetBool());
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
         if(strcmp("World",pPV->GetStr()) == 0)
         {
            Om_RateCtrl.SetCoordSys(CigiBaseRateCtrl::World,true);
            printf("\tCoordinate System = 0 : World\n");
         }
         else if(strcmp("Parent",pPV->GetStr()) == 0)
         {
            Om_RateCtrl.SetCoordSys(CigiBaseRateCtrl::Parent,true);
            printf("\tCoordinate System = 0 : World\n");
         }
         else if(strcmp("Local",pPV->GetStr()) == 0)
         {
            Om_RateCtrl.SetCoordSys(CigiBaseRateCtrl::Local,true);
            printf("\tCoordinate System = 1 : Local\n");
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
         Om_RateCtrl.SetXRate(pPV->Getfloat(),true);
         printf("\tX Rate = %f\n",pPV->Getfloat());
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
         Om_RateCtrl.SetYRate(pPV->Getfloat(),true);
         printf("\tY Rate = %f\n",pPV->Getfloat());
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
         Om_RateCtrl.SetZRate(pPV->Getfloat(),true);
         printf("\tZ Rate = %f\n",pPV->Getfloat());
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
         Om_RateCtrl.SetRollRate(pPV->Getfloat(),true);
         printf("\tRoll Rate = %f\n",pPV->Getfloat());
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
         Om_RateCtrl.SetPitchRate(pPV->Getfloat(),true);
         printf("\tPitch Rate = %f\n",pPV->Getfloat());
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
         Om_RateCtrl.SetYawRate(pPV->Getfloat(),true);
         printf("\tYaw Rate = %f\n",pPV->Getfloat());
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


   *Omsg << Om_RateCtrl;

}


