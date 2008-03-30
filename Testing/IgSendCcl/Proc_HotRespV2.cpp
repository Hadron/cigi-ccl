// Proc_HotRespV2.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_HotRespV2.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_HotRespV2::Proc_HotRespV2()
{
   PcktID = "HotRespV2";
}

Proc_HotRespV2::~Proc_HotRespV2()
{

}


void Proc_HotRespV2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("HOT Response V2:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_HotRespV2.SetHatHotID(pPV->GetUShort(),true);
         printf("\tHot ID = %u\n",pPV->GetUShort());
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
         Om_HotRespV2.SetValid(pPV->GetBool(),true);
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
         Om_HotRespV2.SetMaterial(pPV->GetULong(),true);
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
         Om_HotRespV2.SetHot(pPV->Getdouble(),true);
         printf("\tHot = %f\n",pPV->Getdouble());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_HotRespV2;


}


