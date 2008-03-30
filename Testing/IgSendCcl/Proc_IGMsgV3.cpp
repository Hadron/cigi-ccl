// Proc_IGMsgV3.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_IGMsgV3.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_IGMsgV3::Proc_IGMsgV3()
{
   PcktID = "IGMsgV3";
}

Proc_IGMsgV3::~Proc_IGMsgV3()
{

}


void Proc_IGMsgV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("IG Message V3:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_IGMsgV3.SetMsgID(pPV->GetUShort(),true);
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
         Om_IGMsgV3.SetMsg(pPV->GetStr(),true);
         printf("\tMessage = %s\n",pPV->GetStr());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_IGMsgV3;


}


