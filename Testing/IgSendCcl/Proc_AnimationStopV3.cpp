// Proc_AnimationStopV3.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_AnimationStopV3.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_AnimationStopV3::Proc_AnimationStopV3()
{
   PcktID = "AnimationStopV3";
}

Proc_AnimationStopV3::~Proc_AnimationStopV3()
{

}


void Proc_AnimationStopV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Animation Stop V3:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_AnimationStopV3.SetEntityID(pPV->GetUShort(),true);
         printf("\tEntity ID = %u\n",pPV->GetUShort());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_AnimationStopV3;


}


