// Proc_LosVectReqV1.cpp: implementation of the Proc_LosVectReqV1 Parsing
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


#include "Proc_LosVectReqV1.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_LosVectReqV1::Proc_LosVectReqV1()
{
   PcktID = "LosVectReq";
}

Proc_LosVectReqV1::~Proc_LosVectReqV1()
{
}


void Proc_LosVectReqV1::ProcPckt(ParseValue *pPV)
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
         Om_LosVectReq.SetSrcLat(pPV->Getdouble(),true);
         printf("\tSource Lat = %f\n",pPV->Getdouble());
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
         Om_LosVectReq.SetSrcLon(pPV->Getdouble(),true);
         printf("\tSource Lon = %f\n",pPV->Getdouble());
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
         Om_LosVectReq.SetSrcAlt(pPV->Getfloat(),true);
         printf("\tSource Alt = %f\n",pPV->Getfloat());
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


