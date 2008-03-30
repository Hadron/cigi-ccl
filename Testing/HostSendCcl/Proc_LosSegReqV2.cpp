// Proc_LosSegReqV2.cpp: implementation of the Proc_LosSegReqV2 Parsing
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


#include "Proc_LosSegReqV2.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_LosSegReqV2::Proc_LosSegReqV2()
{
   PcktID = "LosSegReq";
}

Proc_LosSegReqV2::~Proc_LosSegReqV2()
{
}


void Proc_LosSegReqV2::ProcPckt(ParseValue *pPV)
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
         Om_LosSegReq.SetSrcLat(pPV->Getdouble(),true);
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
         Om_LosSegReq.SetSrcLon(pPV->Getdouble(),true);
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
         Om_LosSegReq.SetSrcAlt(pPV->Getdouble(),true);
         printf("\tSource Alt = %f\n",pPV->Getdouble());
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
         Om_LosSegReq.SetDstLat(pPV->Getdouble(),true);
         printf("\tDestination Lat = %f\n",pPV->Getdouble());
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
         Om_LosSegReq.SetDstLon(pPV->Getdouble(),true);
         printf("\tDestination Lon = %f\n",pPV->Getdouble());
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
         Om_LosSegReq.SetDstAlt(pPV->Getdouble(),true);
         printf("\tDestination Alt = %f\n",pPV->Getdouble());
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


