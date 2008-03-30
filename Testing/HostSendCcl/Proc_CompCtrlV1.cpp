// Proc_CompCtrlV1.cpp: implementation of the Proc_CompCtrlV1 Parsing
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


#include "Proc_CompCtrlV1.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_CompCtrlV1::Proc_CompCtrlV1()
{
   PcktID = "CompCtrl";
}

Proc_CompCtrlV1::~Proc_CompCtrlV1()
{
}


void Proc_CompCtrlV1::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Component Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_CompCtrl.SetCompID(pPV->GetUShort(),true);
         printf("\tComp ID = %d\n",pPV->GetUShort());
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
         Om_CompCtrl.SetEntityID(pPV->GetUShort(),true);
         printf("\tEntity ID = %d\n",pPV->GetUShort());
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
         Om_CompCtrl.SetViewID(pPV->GetUChar(),true);
         printf("\tView ID = %d\n",pPV->GetUShort());
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
         if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompAssoc(CigiBaseCompCtrl::Entity,true);
            printf("\tComp Class = 0 : Entity\n");
         }
         else if(strcmp("Environment",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompAssoc(CigiBaseCompCtrl::Environment,true);
            printf("\tComp Class = 1 : Environment\n");
         }
         else if(strcmp("View",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompAssoc(CigiBaseCompCtrl::View,true);
            printf("\tComp Class = 2 : View\n");
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
         Om_CompCtrl.SetCompState(pPV->GetUShort(),true);
         printf("\tComponent State = %d\n",pPV->GetUShort());
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
         Om_CompCtrl.SetCompData(pPV->GetULong(),0,true);
         printf("\tComponent Data 0 = %d\n",pPV->GetULong());
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
         Om_CompCtrl.SetCompData(pPV->GetULong(),1,true);
         printf("\tComponent Data 1 = %d\n",pPV->GetULong());
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


   *Omsg << Om_CompCtrl;

}


