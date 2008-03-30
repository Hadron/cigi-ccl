// Proc_LosSegReqV3.cpp: implementation of the Proc_LosSegReqV3 Parsing
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


#include "Proc_LosSegReqV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_LosSegReqV3::Proc_LosSegReqV3()
{
   PcktID = "LosSegReq";
}

Proc_LosSegReqV3::~Proc_LosSegReqV3()
{
}


void Proc_LosSegReqV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Line of Sight Segment Request\n");

   if(pPV != NULL)
   {
      try
      {
         Om_LosSegReq.SetLosID(pPV->GetUShort(),true);
         printf("\tLine of Sight ID = %d\n",pPV->GetUShort());
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
         if(strcmp("Basic",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetReqType(CigiBaseLosSegReq::Basic,true);
            printf("\tRequest Type = 0 : Basic\n");
         }
         else if(strcmp("Extended",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetReqType(CigiBaseLosSegReq::Extended,true);
            printf("\tRequest Type = 1 : Extended\n");
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
            Om_LosSegReq.SetSrcCoordSys(CigiBaseLosSegReq::Geodetic,true);
            printf("\tSource Coordinate System = 0 : Geodetic\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetSrcCoordSys(CigiBaseLosSegReq::Entity,true);
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
         if(strcmp("Geodetic",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetDstCoordSys(CigiBaseLosSegReq::Geodetic,true);
            printf("\tDestination Coordinate System = 0 : Geodetic\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetDstCoordSys(CigiBaseLosSegReq::Entity,true);
            printf("\tDestination Coordinate System = 1 : Entity\n");
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
            Om_LosSegReq.SetResponseCoordSys(CigiBaseLosSegReq::Geodetic,true);
            printf("\tResponse Coordinate System = 0 : Geodetic\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosSegReq.SetResponseCoordSys(CigiBaseLosSegReq::Entity,true);
            printf("\tResponse Coordinate System = 1 : Entity\n");
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
         Om_LosSegReq.SetAlphaThresh(pPV->GetUChar(),true);
         printf("\tAlpha Threshold = %d\n",pPV->GetUChar());
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
         Om_LosSegReq.SetEntityID(pPV->GetUShort(),true);
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
         Om_LosSegReq.SetSrcXoff(pPV->Getdouble(),true);
         printf("\tSource X Offset = %f\n",pPV->Getdouble());
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
         Om_LosSegReq.SetSrcYoff(pPV->Getdouble(),true);
         printf("\tSource Y Offset = %f\n",pPV->Getdouble());
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
         Om_LosSegReq.SetSrcZoff(pPV->Getdouble(),true);
         printf("\tSource Z Offset = %f\n",pPV->Getdouble());
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
         Om_LosSegReq.SetDstXoff(pPV->Getdouble(),true);
         printf("\tDestination X Offset = %f\n",pPV->Getdouble());
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
         Om_LosSegReq.SetDstYoff(pPV->Getdouble(),true);
         printf("\tDestination Y Offset = %f\n",pPV->Getdouble());
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
         Om_LosSegReq.SetDstZoff(pPV->Getdouble(),true);
         printf("\tDestination Z Offset = %f\n",pPV->Getdouble());
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
         Om_LosSegReq.SetMask(pPV->GetULong(),true);
         printf("\tMask = %d\n",pPV->GetULong());
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


   *Omsg << Om_LosSegReq;

}


