// Proc_PositionRespV3.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_PositionRespV3.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_PositionRespV3::Proc_PositionRespV3()
{
   PcktID = "PositionRespV3";
}

Proc_PositionRespV3::~Proc_PositionRespV3()
{

}


void Proc_PositionRespV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Position Response V3:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_PositionRespV3.SetObjectID(pPV->GetUShort(),true);
         printf("\tObject ID = %u\n",pPV->GetUShort());
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
         Om_PositionRespV3.SetArtPartID(pPV->GetUChar(),true);
         printf("\tArticulated Part ID = %u\n",pPV->GetUChar());
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
            Om_PositionRespV3.SetObjectClass(CigiBasePositionResp::Entity,true);
            printf("\tObject Class = 0 : Entity\n");
         }
         else if(strcmp("ArtPart",pPV->GetStr()) == 0)
         {
            Om_PositionRespV3.SetObjectClass(CigiBasePositionResp::ArtPart,true);
            printf("\tObject Class = 1 : ArtPart\n");
         }
         else if(strcmp("View",pPV->GetStr()) == 0)
         {
            Om_PositionRespV3.SetObjectClass(CigiBasePositionResp::View,true);
            printf("\tObject Class = 2 : View\n");
         }
         else if(strcmp("ViewGrp",pPV->GetStr()) == 0)
         {
            Om_PositionRespV3.SetObjectClass(CigiBasePositionResp::ViewGrp,true);
            printf("\tObject Class = 3 : ViewGrp\n");
         }
         else if(strcmp("MotionTracker",pPV->GetStr()) == 0)
         {
            Om_PositionRespV3.SetObjectClass(CigiBasePositionResp::MotionTracker,true);
            printf("\tObject Class = 4 : MotionTracker\n");
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
         if(strcmp("Geodetic",pPV->GetStr()) == 0)
         {
            Om_PositionRespV3.SetCoordSys(CigiBasePositionResp::Geodetic,true);
            printf("\tCoordinate System = 0 : Geodetic\n");
         }
         else if(strcmp("ParentEntity",pPV->GetStr()) == 0)
         {
            Om_PositionRespV3.SetCoordSys(CigiBasePositionResp::ParentEntity,true);
            printf("\tCoordinate System = 1 : ParentEntity\n");
         }
         else if(strcmp("Submodel",pPV->GetStr()) == 0)
         {
            Om_PositionRespV3.SetCoordSys(CigiBasePositionResp::Submodel,true);
            printf("\tCoordinate System = 2 : Submodel\n");
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
         Om_PositionRespV3.SetLatOrXoff(pPV->Getdouble(),true);
         printf("\tLat or X offset = %f\n",pPV->Getdouble());
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
         Om_PositionRespV3.SetLonOrYoff(pPV->Getdouble(),true);
         printf("\tLon or Y offset = %f\n",pPV->Getdouble());
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
         Om_PositionRespV3.SetAltOrZoff(pPV->Getdouble(),true);
         printf("\tAlt or Z offset = %f\n",pPV->Getdouble());
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
         Om_PositionRespV3.SetRoll(pPV->Getfloat(),true);
         printf("\tRoll = %f\n",pPV->Getfloat());
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
         Om_PositionRespV3.SetPitch(pPV->Getfloat(),true);
         printf("\tPitch = %f\n",pPV->Getfloat());
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
         Om_PositionRespV3.SetYaw(pPV->Getfloat(),true);
         printf("\tYaw = %f\n",pPV->Getfloat());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_PositionRespV3;


}


