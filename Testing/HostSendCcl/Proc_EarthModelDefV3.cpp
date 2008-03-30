// Proc_EarthModelDefV3.cpp: implementation of the Proc_EarthModelDefV3 Parsing
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


#include "Proc_EarthModelDefV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_EarthModelDefV3::Proc_EarthModelDefV3()
{
   PcktID = "EarthModelDef";
}

Proc_EarthModelDefV3::~Proc_EarthModelDefV3()
{
}


void Proc_EarthModelDefV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Earth Reference Model Definition:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_EarthModelDef.SetCustomERMEn(pPV->GetBool(),true);
         printf("\tCustom Earth Reference Model Enable = %d\n",pPV->GetBool());
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
         Om_EarthModelDef.SetEquatorialRadius(pPV->Getdouble(),true);
         printf("\tEquatorial Radius = %f\n",pPV->Getdouble());
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
         Om_EarthModelDef.SetFlattening(pPV->Getdouble(),true);
         printf("\tFlattening = %f\n",pPV->Getdouble());
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


   *Omsg << Om_EarthModelDef;

}


