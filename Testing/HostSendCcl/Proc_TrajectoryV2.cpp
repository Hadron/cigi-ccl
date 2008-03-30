// Proc_TrajectoryV2.cpp: implementation of the Proc_TrajectoryV2 Parsing
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


#include "Proc_TrajectoryV2.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_TrajectoryV2::Proc_TrajectoryV2()
{
   PcktID = "Trajectory";
}

Proc_TrajectoryV2::~Proc_TrajectoryV2()
{
}


void Proc_TrajectoryV2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Trajectory:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_Trajectory.SetEntityID(pPV->GetUShort(),true);
         printf("\tEntityID = %d\n",pPV->GetUShort());
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
         Om_Trajectory.SetAccel(pPV->Getfloat(),true);
         printf("\tAcceleration = %f\n",pPV->Getfloat());
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
         Om_Trajectory.SetRetardationRate(pPV->Getfloat(),true);
         printf("\tRetardation Rate = %f\n",pPV->Getfloat());
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
         Om_Trajectory.SetTermVel(pPV->Getfloat(),true);
         printf("\tTerminal Velocity = %f\n",pPV->Getfloat());
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


   *Omsg << Om_Trajectory;

}


