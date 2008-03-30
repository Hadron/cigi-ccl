// Proc_SensorCtrlV1.cpp: implementation of the Proc_SensorCtrlV1 Parsing
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


#include "Proc_SensorCtrlV1.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SensorCtrlV1::Proc_SensorCtrlV1()
{
   PcktID = "SensorCtrl";
}

Proc_SensorCtrlV1::~Proc_SensorCtrlV1()
{
}


void Proc_SensorCtrlV1::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Sensor Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_SensorCtrl.SetViewID(pPV->GetUShort(),true);
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
         Om_SensorCtrl.SetSensorID(pPV->GetUChar(),true);
         printf("\tSensor ID = %d\n",pPV->GetUChar());
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
         Om_SensorCtrl.SetSensorOn(pPV->GetBool(),true);
         printf("\tSensor On = %d\n",pPV->GetBool());
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
         if(strcmp("WhiteHot",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetPolarity(CigiBaseSensorCtrl::WhiteHot,true);
            printf("\tPolarity = 0 : WhiteHot\n");
         }
         else if(strcmp("BlackHot",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetPolarity(CigiBaseSensorCtrl::BlackHot,true);
            printf("\tPolarity = 1 : BlackHot\n");
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
         Om_SensorCtrl.SetLineDropEn(pPV->GetBool(),true);
         printf("\tLine Drop Enable = %d\n",pPV->GetBool());
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
         if(strcmp("TrackOff",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::TrackOff,true);
            printf("\tTrack Mode = 0 : TrackOff\n");
         }
         else if(strcmp("ForceCorrelate",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::ForceCorrelate,true);
            printf("\tTrack Mode = 1 : ForceCorrelate\n");
         }
         else if(strcmp("Scene",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::Scene,true);
            printf("\tTrack Mode = 2 : Scene\n");
         }
         else if(strcmp("Target",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::Target,true);
            printf("\tTrack Mode = 3 : Target\n");
         }
         else if(strcmp("Ship",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::Ship,true);
            printf("\tTrack Mode = 4 : Ship\n");
         }
         else if(strcmp("TMDefA",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::TMDefA,true);
            printf("\tTrack Mode = 5 : TMDefA\n");
         }
         else if(strcmp("TMDefB",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::TMDefB,true);
            printf("\tTrack Mode = 6 : TMDefB\n");
         }
         else if(strcmp("TMDefC",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackMode(CigiBaseSensorCtrl::TMDefC,true);
            printf("\tTrack Mode = 7 : TMDefC\n");
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
         Om_SensorCtrl.SetAutoGainEn(pPV->GetBool(),true);
         printf("\tAuto Gain Enable = %d\n",pPV->GetBool());
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
         if(strcmp("TrackWhite",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackPolarity(CigiBaseSensorCtrl::TrackWhite,true);
            printf("\tTrack Polarity = 0 : TrackWhite\n");
         }
         else if(strcmp("TrackBlack",pPV->GetStr()) == 0)
         {
            Om_SensorCtrl.SetTrackPolarity(CigiBaseSensorCtrl::TrackBlack,true);
            printf("\tTrack Polarity = 1 : TrackBlack\n");
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
         Om_SensorCtrl.SetGain(pPV->Getfloat(),true);
         printf("\tGain = %f\n",pPV->Getfloat());
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
         Om_SensorCtrl.SetLevel(pPV->Getfloat(),true);
         printf("\tLevel = %f\n",pPV->Getfloat());
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
         Om_SensorCtrl.SetACCoupling(pPV->Getfloat(),true);
         printf("\tAC Coupling = %f\n",pPV->Getfloat());
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
         Om_SensorCtrl.SetNoise(pPV->Getfloat(),true);
         printf("\tNoise = %f\n",pPV->Getfloat());
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


   *Omsg << Om_SensorCtrl;

}


