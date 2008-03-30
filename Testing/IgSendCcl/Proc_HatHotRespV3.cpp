// Proc_HatHotRespV3.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_HatHotRespV3.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_HatHotRespV3::Proc_HatHotRespV3()
{
   PcktID = "HatHotRespV3";
}

Proc_HatHotRespV3::~Proc_HatHotRespV3()
{

}


void Proc_HatHotRespV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("HAT HOT Response V3:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotRespV3.SetHatHotID(pPV->GetUShort(),true);
         printf("\tHat Hot ID = %u\n",pPV->GetUShort());
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
         Om_HatHotRespV3.SetValid(pPV->GetBool(),true);
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
         if(strcmp("HAT",pPV->GetStr()) == 0)
         {
            Om_HatHotRespV3.SetReqType(CigiBaseHatHotResp::HAT,true);
            printf("\tRequest Type = 0 : HAT\n");
         }
         else if(strcmp("HOT",pPV->GetStr()) == 0)
         {
            Om_HatHotRespV3.SetReqType(CigiBaseHatHotResp::HOT,true);
            printf("\tRequest Type = 1 : HOT\n");
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
         if(Om_HatHotRespV3.GetReqType() == CigiBaseHatHotResp::HAT)
         {
            Om_HatHotRespV3.SetHat(pPV->Getdouble(),true);
            printf("\tHat = %f\n",pPV->Getdouble());
         }
         else if(Om_HatHotRespV3.GetReqType() == CigiBaseHatHotResp::HOT)
         {
            Om_HatHotRespV3.SetHot(pPV->Getdouble(),true);
            printf("\tHot = %f\n",pPV->Getdouble());
         }
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_HatHotRespV3;


}


