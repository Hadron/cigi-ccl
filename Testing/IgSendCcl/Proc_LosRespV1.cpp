// Proc_LosRespV1.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_LosRespV1.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_LosRespV1::Proc_LosRespV1()
{
   PcktID = "LosRespV1";
}

Proc_LosRespV1::~Proc_LosRespV1()
{

}


void Proc_LosRespV1::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Line Of Sight Response V1:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_LosRespV1.SetLosID(pPV->GetUShort(),true);
         printf("\tLine Of Sight ID = %u\n",pPV->GetUShort());
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
         Om_LosRespV1.SetValid(pPV->GetBool(),true);
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
         Om_LosRespV1.SetVisible(pPV->GetBool(),true);
         printf("\tVisible = %d\n",pPV->GetBool());
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
         Om_LosRespV1.SetMaterial(pPV->GetULong(),true);
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
         Om_LosRespV1.SetRange(pPV->Getdouble(),true);
         printf("\tRange = %f\n",pPV->Getdouble());
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
         Om_LosRespV1.SetLatitude(pPV->Getdouble(),true);
         printf("\tLatitude = %f\n",pPV->Getdouble());
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
         Om_LosRespV1.SetLongitude(pPV->Getdouble(),true);
         printf("\tLongitude = %f\n",pPV->Getdouble());
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
         Om_LosRespV1.SetAltitude(pPV->Getdouble(),true);
         printf("\tAltitude = %f\n",pPV->Getdouble());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_LosRespV1;


}


