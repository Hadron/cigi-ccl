// Proc_HatRespV1.cpp: implementation of the Proc_EntityCtrlV3 Parsing
//   Processor class..
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


#include "Proc_HatRespV1.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_HatRespV1::Proc_HatRespV1()
{
   PcktID = "HatRespV1";
}

Proc_HatRespV1::~Proc_HatRespV1()
{

}


void Proc_HatRespV1::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("HAT Response V1:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_HatRespV1.SetHatHotID(pPV->GetUShort(),true);
         printf("\tHat ID = %u\n",pPV->GetUShort());
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
         Om_HatRespV1.SetValid(pPV->GetBool(),true);
         printf("\tValid = %d\n",pPV->GetBool());
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
         Om_HatRespV1.SetMaterial(pPV->GetULong(),true);
         printf("\tMaterial = %u\n",pPV->GetULong());
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
         Om_HatRespV1.SetHat(pPV->Getdouble(),true);
         printf("\tHat = %f\n",pPV->Getdouble());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_HatRespV1;


}


