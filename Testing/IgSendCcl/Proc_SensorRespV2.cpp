// Proc_SensorRespV2.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_SensorRespV2.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SensorRespV2::Proc_SensorRespV2()
{
   PcktID = "SensorRespV2";
}

Proc_SensorRespV2::~Proc_SensorRespV2()
{

}


void Proc_SensorRespV2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Sensor Response V2:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_SensorRespV2.SetViewID(pPV->GetUShort(),true);
         printf("\tView ID = %u\n",pPV->GetUShort());
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
         Om_SensorRespV2.SetSensorID(pPV->GetUChar(),true);
         printf("\tSensor ID = %u\n",pPV->GetUChar());
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
         if(strcmp("Searching",pPV->GetStr()) == 0)
         {
            Om_SensorRespV2.SetSensorStat(CigiBaseSensorResp::Searching,true);
            printf("\tSensor Status = 0 : Searching\n");
         }
         else if(strcmp("Tracking",pPV->GetStr()) == 0)
         {
            Om_SensorRespV2.SetSensorStat(CigiBaseSensorResp::Tracking,true);
            printf("\tSensor Status = 1 : Tracking\n");
         }
         else if(strcmp("NearBrakeLock",pPV->GetStr()) == 0)
         {
            Om_SensorRespV2.SetSensorStat(CigiBaseSensorResp::NearBrakeLock,true);
            printf("\tSensor Status = 2 : NearBrakeLock\n");
         }
         else if(strcmp("BrakeLock",pPV->GetStr()) == 0)
         {
            Om_SensorRespV2.SetSensorStat(CigiBaseSensorResp::BrakeLock,true);
            printf("\tSensor Status = 3 : BrakeLock\n");
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
         Om_SensorRespV2.SetGateSzX(pPV->GetUShort(),true);
         printf("\tGate Size X = %u\n",pPV->GetUShort());
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
         Om_SensorRespV2.SetGateSzY(pPV->GetUShort(),true);
         printf("\tGate Size Y = %u\n",pPV->GetUShort());
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
         Om_SensorRespV2.SetGateXoff(pPV->Getfloat(),true);
         printf("\tGate X offset = %f\n",pPV->Getfloat());
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
         Om_SensorRespV2.SetGateYoff(pPV->Getfloat(),true);
         printf("\tGate Y offset = %f\n",pPV->Getfloat());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_SensorRespV2;


}


