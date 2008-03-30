// Proc_SensorXRespV3.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_SensorXRespV3.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SensorXRespV3::Proc_SensorXRespV3()
{
   PcktID = "SensorXRespV3";
}

Proc_SensorXRespV3::~Proc_SensorXRespV3()
{

}


void Proc_SensorXRespV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Sensor Extended Response V3:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_SensorXRespV3.SetViewID(pPV->GetUShort(),true);
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
         Om_SensorXRespV3.SetSensorID(pPV->GetUChar(),true);
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
            Om_SensorXRespV3.SetSensorStat(CigiBaseSensorResp::Searching,true);
            printf("\tSensor Status = 0 : Searching\n");
         }
         else if(strcmp("Tracking",pPV->GetStr()) == 0)
         {
            Om_SensorXRespV3.SetSensorStat(CigiBaseSensorResp::Tracking,true);
            printf("\tSensor Status = 1 : Tracking\n");
         }
         else if(strcmp("NearBrakeLock",pPV->GetStr()) == 0)
         {
            Om_SensorXRespV3.SetSensorStat(CigiBaseSensorResp::NearBrakeLock,true);
            printf("\tSensor Status = 2 : NearBrakeLock\n");
         }
         else if(strcmp("BrakeLock",pPV->GetStr()) == 0)
         {
            Om_SensorXRespV3.SetSensorStat(CigiBaseSensorResp::BrakeLock,true);
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
         Om_SensorXRespV3.SetEntityTgt(pPV->GetBool(),true);
         printf("\tEntity Target = %d\n",pPV->GetBool());
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
         Om_SensorXRespV3.SetEntityID(pPV->GetUShort(),true);
         printf("\tEntity ID = %u\n",pPV->GetUShort());
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
         Om_SensorXRespV3.SetGateSzX(pPV->GetUShort(),true);
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
         Om_SensorXRespV3.SetGateSzY(pPV->GetUShort(),true);
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
         Om_SensorXRespV3.SetGateXoff(pPV->Getfloat(),true);
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
         Om_SensorXRespV3.SetGateYoff(pPV->Getfloat(),true);
         printf("\tGate Y offset = %f\n",pPV->Getfloat());
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
         Om_SensorXRespV3.SetFrameCntr(pPV->GetULong(),true);
         printf("\tFrame Counter = %u\n",pPV->GetULong());
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
         Om_SensorXRespV3.SetTrackPntLat(pPV->Getdouble(),true);
         printf("\tTrack Point Latitude = %f\n",pPV->Getdouble());
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
         Om_SensorXRespV3.SetTrackPntLon(pPV->Getdouble(),true);
         printf("\tTrack Point Longitude = %f\n",pPV->Getdouble());
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
         Om_SensorXRespV3.SetTrackPntAlt(pPV->Getdouble(),true);
         printf("\tTrack Point Altitude = %f\n",pPV->Getdouble());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_SensorXRespV3;


}


