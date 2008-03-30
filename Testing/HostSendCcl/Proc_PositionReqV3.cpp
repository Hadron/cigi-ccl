// Proc_PositionReqV3.cpp: implementation of the Proc_PositionReqV3 Parsing
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


#include "Proc_PositionReqV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_PositionReqV3::Proc_PositionReqV3()
{
   PcktID = "PositionReq";
}

Proc_PositionReqV3::~Proc_PositionReqV3()
{
}


void Proc_PositionReqV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Position Request\n");

   if(pPV != NULL)
   {
      try
      {
         Om_PositionReq.SetObjectID(pPV->GetUShort(),true);
         printf("\tObject ID = %d\n",pPV->GetUShort());
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
         Om_PositionReq.SetArtPartID(pPV->GetUChar(),true);
         printf("\tArticulated Part ID = %d\n",pPV->GetUChar());
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
         if(strcmp("OneShot",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetUpdateMode(CigiBasePositionReq::OneShot,true);
            printf("\tUpdate Mode = 0 : OneShot\n");
         }
         else if(strcmp("Continuous",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetUpdateMode(CigiBasePositionReq::Continuous,true);
            printf("\tUpdate Mode = 1 : Continuous\n");
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
         if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::Entity,true);
            printf("\tObject Class = 0 : Entity\n");
         }
         else if(strcmp("ArtPart",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::ArtPart,true);
            printf("\tObject Class = 1 : ArtPart\n");
         }
         else if(strcmp("View",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::View,true);
            printf("\tObject Class = 2 : View\n");
         }
         else if(strcmp("ViewGrp",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::ViewGrp,true);
            printf("\tObject Class = 3 : ViewGrp\n");
         }
         else if(strcmp("MotionTracker",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetObjectClass(CigiBasePositionReq::MotionTracker,true);
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
            Om_PositionReq.SetCoordSys(CigiBasePositionReq::Geodetic,true);
            printf("\tCoordinate System = 0 : Geodetic\n");
         }
         else if(strcmp("ParentEntity",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetCoordSys(CigiBasePositionReq::ParentEntity,true);
            printf("\tCoordinate System = 1 : ParentEntity\n");
         }
         else if(strcmp("Submodel",pPV->GetStr()) == 0)
         {
            Om_PositionReq.SetCoordSys(CigiBasePositionReq::Submodel,true);
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
      DefHex = pPV->GetStr();


   *Omsg << Om_PositionReq;

}


