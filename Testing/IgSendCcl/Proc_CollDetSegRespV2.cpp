// Proc_CollDetSegRespV2.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_CollDetSegRespV2.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_CollDetSegRespV2::Proc_CollDetSegRespV2()
{
   PcktID = "CollDetSegRespV2";
}

Proc_CollDetSegRespV2::~Proc_CollDetSegRespV2()
{

}


void Proc_CollDetSegRespV2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Collision Detection Segment Response V2:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetSegRespV2.SetEntityID(pPV->GetUShort(),true);
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
         Om_CollDetSegRespV2.SetSegID(pPV->GetUChar(),true);
         printf("\tSegment ID = %u\n",pPV->GetUChar());
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
            Om_CollDetSegRespV2.SetCollType(CigiBaseCollDetSegResp::NonEntity,true);
            printf("\tCollision Type = 0 : NonEntity\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_CollDetSegRespV2.SetCollType(CigiBaseCollDetSegResp::Entity,true);
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
         Om_CollDetSegRespV2.SetCollEntityID(pPV->GetUShort(),true);
         printf("\tCollision Entity ID = %u\n",pPV->GetUShort());
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
         Om_CollDetSegRespV2.SetMaterial(pPV->GetULong(),true);
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
         Om_CollDetSegRespV2.SetX(pPV->Getfloat(),true);
         printf("\tX = %f\n",pPV->Getfloat());
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
         Om_CollDetSegRespV2.SetY(pPV->Getfloat(),true);
         printf("\tY = %f\n",pPV->Getfloat());
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
         Om_CollDetSegRespV2.SetZ(pPV->Getfloat(),true);
         printf("\tZ = %f\n",pPV->Getfloat());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_CollDetSegRespV2;


}


