// Proc_AerosolRespV3.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_AerosolRespV3.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_AerosolRespV3::Proc_AerosolRespV3()
{
   PcktID = "AerosolRespV3";
}

Proc_AerosolRespV3::~Proc_AerosolRespV3()
{

}


void Proc_AerosolRespV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Aerosol Response V3:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_AerosolRespV3.SetRequestID(pPV->GetUChar(),true);
         printf("\tRequest ID = %u\n",pPV->GetUChar());
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
         Om_AerosolRespV3.SetLayerID(pPV->GetUChar(),true);
         printf("\tLayer ID = %u\n",pPV->GetUChar());
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
         Om_AerosolRespV3.SetAerosolConcentration(pPV->Getfloat(),true);
         printf("\tAerosol Concentration = %f\n",pPV->Getfloat());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_AerosolRespV3;


}


