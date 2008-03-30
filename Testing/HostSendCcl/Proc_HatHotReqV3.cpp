// Proc_HatHotReqV3.cpp: implementation of the Proc_HatHotReqV3 Parsing
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


#include "Proc_HatHotReqV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_HatHotReqV3::Proc_HatHotReqV3()
{
   PcktID = "HatHotReq";
}

Proc_HatHotReqV3::~Proc_HatHotReqV3()
{
}


void Proc_HatHotReqV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Hot/Hat Request:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_HatHotReq.SetHatHotID(pPV->GetUShort(),true);
         printf("\tHat-Hot ID = %d\n",pPV->GetUShort());
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
            Om_HatHotReq.SetReqType(CigiBaseHatHotReq::HAT,true);
            printf("\tRequest Type = 0 : HAT\n");
         }
         else if(strcmp("HOT",pPV->GetStr()) == 0)
         {
            Om_HatHotReq.SetReqType(CigiBaseHatHotReq::HOT,true);
            printf("\tRequest Type = 1 : HOT\n");
         }
         else if(strcmp("Extended",pPV->GetStr()) == 0)
         {
            Om_HatHotReq.SetReqType(CigiBaseHatHotReq::Extended,true);
            printf("\tRequest Type = 2 : Extended\n");
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
         if(strcmp("Geodetic",pPV->GetStr()) == 0)
         {
            Om_HatHotReq.SetSrcCoordSys(CigiBaseHatHotReq::Geodetic,true);
            printf("\tSource Coordinate System = 0 : Geodetic\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_HatHotReq.SetSrcCoordSys(CigiBaseHatHotReq::Entity,true);
            printf("\tSource Coordinate System = 1 : Entity\n");
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
         Om_HatHotReq.SetEntityID(pPV->GetUShort(),true);
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
         Om_HatHotReq.SetXoff(pPV->Getdouble(),true);
         printf("\tX Offset = %f\n",pPV->Getdouble());
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
         Om_HatHotReq.SetYoff(pPV->Getdouble(),true);
         printf("\tY Offset = %f\n",pPV->Getdouble());
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
         Om_HatHotReq.SetZoff(pPV->Getdouble(),true);
         printf("\tZ Offset = %f\n",pPV->Getdouble());
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


   *Omsg << Om_HatHotReq;

}


