// Proc_ShortArtPartCtrlV3.cpp: implementation of the Proc_ShortArtPartCtrlV3 Parsing
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


#include "Proc_ShortArtPartCtrlV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_ShortArtPartCtrlV3::Proc_ShortArtPartCtrlV3()
{
   PcktID = "ShortArtPartCtrl";
}

Proc_ShortArtPartCtrlV3::~Proc_ShortArtPartCtrlV3()
{
}


void Proc_ShortArtPartCtrlV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Short Articulated Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_ShortArtPartCtrl.SetEntityID(pPV->GetUShort(),true);
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
         Om_ShortArtPartCtrl.SetArtPart1(pPV->GetUChar(),true);
         printf("\tArticulated Part ID 1 = %d\n",pPV->GetUChar());
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
         Om_ShortArtPartCtrl.SetArtPart2(pPV->GetUChar(),true);
         printf("\tArticulated Part ID 2 = %d\n",pPV->GetUChar());
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
         if(strcmp("NotUsed",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::NotUsed,true);
            printf("\tDegree of Freedom Select 1 = 0 : Not Used\n");
         }
         else if(strcmp("Xoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Xoff,true);
            printf("\tDegree of Freedom Select 1 = 1 : X Offset\n");
         }
         else if(strcmp("Yoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Yoff,true);
            printf("\tDegree of Freedom Select 1 = 2 : Y Offset\n");
         }
         else if(strcmp("Zoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Zoff,true);
            printf("\tDegree of Freedom Select 1 = 3 : Z Offset\n");
         }
         else if(strcmp("Yaw",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Yaw,true);
            printf("\tDegree of Freedom Select 1 = 4 : Yaw\n");
         }
         else if(strcmp("Pitch",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Pitch,true);
            printf("\tDegree of Freedom Select 1 = 5 : Pitch\n");
         }
         else if(strcmp("Roll",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect1(CigiBaseShortArtPartCtrl::Roll,true);
            printf("\tDegree of Freedom Select 1 = 6 : Roll\n");
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
         if(strcmp("NotUsed",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::NotUsed,true);
            printf("\tDegree of Freedom Select 2 = 0 : Not Used\n");
         }
         else if(strcmp("Xoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Xoff,true);
            printf("\tDegree of Freedom Select 2 = 1 : X Offset\n");
         }
         else if(strcmp("Yoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Yoff,true);
            printf("\tDegree of Freedom Select 2 = 2 : Y Offset\n");
         }
         else if(strcmp("Zoff",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Zoff,true);
            printf("\tDegree of Freedom Select 2 = 3 : Z Offset\n");
         }
         else if(strcmp("Yaw",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Yaw,true);
            printf("\tDegree of Freedom Select 2 = 4 : Yaw\n");
         }
         else if(strcmp("Pitch",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Pitch,true);
            printf("\tDegree of Freedom Select 2 = 5 : Pitch\n");
         }
         else if(strcmp("Roll",pPV->GetStr()) == 0)
         {
            Om_ShortArtPartCtrl.SetDofSelect2(CigiBaseShortArtPartCtrl::Roll,true);
            printf("\tDegree of Freedom Select 2 = 6 : Roll\n");
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
         Om_ShortArtPartCtrl.SetArtPart1En(pPV->GetBool(),true);
         printf("\tArticulated Part 1 Enable = %d\n",pPV->GetBool());
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
         Om_ShortArtPartCtrl.SetArtPart2En(pPV->GetBool(),true);
         printf("\tArticulated Part 2 Enable = %d\n",pPV->GetBool());
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
         Om_ShortArtPartCtrl.SetDof1(pPV->Getfloat(),true);
         printf("\tDegree of Freedom 1 = %f\n",pPV->Getfloat());
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
         Om_ShortArtPartCtrl.SetDof2(pPV->Getfloat(),true);
         printf("\tDegree of Freedom 2 = %f\n",pPV->Getfloat());
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


   *Omsg << Om_ShortArtPartCtrl;

}


