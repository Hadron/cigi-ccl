// Proc_TerrestrialSurfaceRespV3.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_TerrestrialSurfaceRespV3.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_TerrestrialSurfaceRespV3::Proc_TerrestrialSurfaceRespV3()
{
   PcktID = "TerrestrialSurfaceRespV3";
}

Proc_TerrestrialSurfaceRespV3::~Proc_TerrestrialSurfaceRespV3()
{

}


void Proc_TerrestrialSurfaceRespV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Terrestrial Surface Response V3:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_TerrestrialSurfaceRespV3.SetRequestID(pPV->GetUChar(),true);
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
         Om_TerrestrialSurfaceRespV3.SetSurfaceConditionID(pPV->GetULong(),true);
         printf("\tSurface Condition ID = %u\n",pPV->GetULong());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_TerrestrialSurfaceRespV3;


}


