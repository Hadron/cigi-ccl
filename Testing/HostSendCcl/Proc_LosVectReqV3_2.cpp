// Proc_LosVectReqV3_2.cpp: implementation of the Proc_LosVectReqV3_2 Parsing
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


#include "Proc_LosVectReqV3_2.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_LosVectReqV3_2::Proc_LosVectReqV3_2()
{
   PcktID = "LosVectReq";
}

Proc_LosVectReqV3_2::~Proc_LosVectReqV3_2()
{
}


void Proc_LosVectReqV3_2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Line of Site Vector Request:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_LosVectReq.SetLosID(pPV->GetUShort(),true);
         printf("\tLine of Site ID = %d\n",pPV->GetUShort());
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
            Om_LosVectReq.SetReqType(CigiBaseLosVectReq::Basic,true);
            printf("\tRequest Type = 0 : Basic\n");
         }
         else if(strcmp("Extended",pPV->GetStr()) == 0)
         {
            Om_LosVectReq.SetReqType(CigiBaseLosVectReq::Extended,true);
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
            Om_LosVectReq.SetSrcCoordSys(CigiBaseLosVectReq::Geodetic,true);
            printf("\tSource Coordinate System = 0 : Geodetic\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosVectReq.SetSrcCoordSys(CigiBaseLosVectReq::Entity,true);
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
            Om_LosVectReq.SetResponseCoordSys(CigiBaseLosVectReq::Geodetic,true);
            printf("\tResponse Coordinate System = 0 : Geodetic\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_LosVectReq.SetResponseCoordSys(CigiBaseLosVectReq::Entity,true);
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
         Om_LosVectReq.SetAlphaThresh(pPV->GetUChar(),true);
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
         Om_LosVectReq.SetEntityID(pPV->GetUShort(),true);
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
         Om_LosVectReq.SetVectAz(pPV->Getfloat(),true);
         printf("\tVector Azimuth = %f\n",pPV->Getfloat());
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
         Om_LosVectReq.SetVectEl(pPV->Getfloat(),true);
         printf("\tVector Elevation = %f\n",pPV->Getfloat());
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
         Om_LosVectReq.SetMinRange(pPV->Getfloat(),true);
         printf("\tMinimum Range = %f\n",pPV->Getfloat());
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
         Om_LosVectReq.SetMaxRange(pPV->Getfloat(),true);
         printf("\tMax Range = %f\n",pPV->Getfloat());
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
         Om_LosVectReq.SetSrcXoff(pPV->Getdouble(),true);
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
         Om_LosVectReq.SetSrcYoff(pPV->Getdouble(),true);
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
         Om_LosVectReq.SetSrcZoff(pPV->Getdouble(),true);
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
         Om_LosVectReq.SetMask(pPV->GetULong(),true);
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
   {
      try
      {
         Om_LosVectReq.SetUpdatePeriod(pPV->GetUChar(),true);
         printf("\tUpdate Period = %d\n",pPV->GetUChar());
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


   *Omsg << Om_LosVectReq;

}


