// Proc_CollDetVolRespV2.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_CollDetVolRespV2.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_CollDetVolRespV2::Proc_CollDetVolRespV2()
{
   PcktID = "CollDetVolRespV2";
}

Proc_CollDetVolRespV2::~Proc_CollDetVolRespV2()
{

}


void Proc_CollDetVolRespV2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Collision Detection Volume Response V2:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolRespV2.SetEntityID(pPV->GetUShort(),true);
         printf("\tEntity ID = %u\n",pPV->GetUShort());
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
         Om_CollDetVolRespV2.SetVolID(pPV->GetUChar(),true);
         printf("\tVolume ID = %u\n",pPV->GetUChar());
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
         if(strcmp("NonEntity",pPV->GetStr()) == 0)
         {
            Om_CollDetVolRespV2.SetCollType(CigiBaseCollDetVolResp::NonEntity,true);
            printf("\tCollision Type = 0 : NonEntity\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_CollDetVolRespV2.SetCollType(CigiBaseCollDetVolResp::Entity,true);
            printf("\tCollision Type = 1 : Entity\n");
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
         Om_CollDetVolRespV2.SetCollEntityID(pPV->GetUShort(),true);
         printf("\tCollision Entity ID = %u\n",pPV->GetUShort());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_CollDetVolRespV2;


}


