// Proc_IGMsgV2.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_IGMsgV2.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_IGMsgV2::Proc_IGMsgV2()
{
   PcktID = "IGMsgV2";
}

Proc_IGMsgV2::~Proc_IGMsgV2()
{

}


void Proc_IGMsgV2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("IG Message V2:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_IGMsgV2.SetMsgID(pPV->GetUShort(),true);
         printf("\tMessage ID = %u\n",pPV->GetUShort());
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
         Om_IGMsgV2.SetMsg(pPV->GetStr(),true);
         printf("\tMessage = %s\n",pPV->GetStr());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_IGMsgV2;


}


