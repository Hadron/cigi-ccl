// Proc_CompCtrlV2.cpp: implementation of the Proc_CompCtrlV2 Parsing
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


#include "Proc_CompCtrlV2.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_CompCtrlV2::Proc_CompCtrlV2()
{
   PcktID = "CompCtrl";
}

Proc_CompCtrlV2::~Proc_CompCtrlV2()
{
}


void Proc_CompCtrlV2::ProcPckt(ParseValue *pPV)
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
         Om_CompCtrl.SetInstanceID(pPV->GetUShort(),true);
         printf("\tInstance ID = %d\n",pPV->GetUShort());
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
         if(strcmp("EntityV2",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV2(CigiBaseCompCtrl::EntityV2,true);
            printf("\tComp Class = 0 : EntityV2\n");
         }
         else if(strcmp("EnvironmentV2",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV2(CigiBaseCompCtrl::EnvironmentV2,true);
            printf("\tComp Class = 1 : EnvironmentV2\n");
         }
         else if(strcmp("ViewV2",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV2(CigiBaseCompCtrl::ViewV2,true);
            printf("\tComp Class = 2 : ViewV2\n");
         }
         else if(strcmp("ViewGrpV2",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV2(CigiBaseCompCtrl::ViewGrpV2,true);
            printf("\tComp Class = 3 : ViewGrpV2\n");
         }
         else if(strcmp("SensorV2",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV2(CigiBaseCompCtrl::SensorV2,true);
            printf("\tComp Class = 4 : SensorV2\n");
         }
         else if(strcmp("SystemV2",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV2(CigiBaseCompCtrl::SystemV2,true);
            printf("\tComp Class = 5 : SystemV2\n");
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


