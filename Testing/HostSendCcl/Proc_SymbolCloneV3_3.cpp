// Proc_SymbolCloneV3_3.cpp: implementation of the Proc_SymbolCloneV3_3 Parsing
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


#include "Proc_SymbolCloneV3_3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SymbolCloneV3_3::Proc_SymbolCloneV3_3()
{
   PcktID = "SymbolClone";
}

Proc_SymbolCloneV3_3::~Proc_SymbolCloneV3_3()
{
}


void Proc_SymbolCloneV3_3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;

   bool EntAt = true;

   pPV = pPV->nxt();  // skip the cmd name

   printf("Symbol Clone:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_SymbolClone.SetSymbolID(pPV->GetUShort(),true);
         printf("\tSymbol ID = %d\n",pPV->GetUShort());
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
         if(strcmp("Symbol",pPV->GetStr()) == 0)
         {
            Om_SymbolClone.SetSourceType(CigiBaseSymbolClone::SymbolSrc,true);
            printf("\tSource Type = 0 : Symbol\n");
         }
         else if(strcmp("SymbolTemplate",pPV->GetStr()) == 0)
         {
            Om_SymbolClone.SetSourceType(CigiBaseSymbolClone::SymbolTemplateSrc,true);
            printf("\tSource Type = 1 : Symbol Template\n");
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
         Om_SymbolClone.SetSourceID(pPV->GetUShort(),true);
         printf("\tSource ID = %d\n",pPV->GetUShort());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }
   }


   *Omsg << Om_SymbolClone;

}


