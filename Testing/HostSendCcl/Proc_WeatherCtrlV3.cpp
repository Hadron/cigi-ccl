// Proc_WeatherCtrlV3.cpp: implementation of the Proc_WeatherCtrlV3 Parsing
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


#include "Proc_WeatherCtrlV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_WeatherCtrlV3::Proc_WeatherCtrlV3()
{
   PcktID = "WeatherCtrl";
}

Proc_WeatherCtrlV3::~Proc_WeatherCtrlV3()
{
}


void Proc_WeatherCtrlV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Weather Control:\n");

   if(pPV != NULL)
   {
      try
      {
         unsigned short ts = pPV->GetUShort();
         Om_WeatherCtrl.SetEntityID(ts,true);
         Om_WeatherCtrl.SetRegionID(ts,true);
         printf("\tID = %d\n",pPV->GetUShort());
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
         Om_WeatherCtrl.SetLayerID(pPV->GetUChar(),true);
         printf("\tLayer ID = %d\n",pPV->GetUChar());
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
         Om_WeatherCtrl.SetHumidity(pPV->GetUChar(),true);
         printf("\tHumidity = %d\n",pPV->GetUChar());
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
         Om_WeatherCtrl.SetWeatherEn(pPV->GetBool(),true);
         printf("\tWeather Enable = %d\n",pPV->GetBool());
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
         Om_WeatherCtrl.SetScudEn(pPV->GetBool(),true);
         printf("\tScud Enable = %d\n",pPV->GetBool());
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
         Om_WeatherCtrl.SetRandomWindsEn(pPV->GetBool(),true);
         printf("\tRandom Winds Enable = %d\n",pPV->GetBool());
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
         Om_WeatherCtrl.SetRandomLightningEn(pPV->GetBool(),true);
         printf("\tRandom Lightning Enable = %d\n",pPV->GetBool());
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
         if(strcmp("None",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::None,true);
            printf("\tCloud Type = 0 : None\n");
         }
         else if(strcmp("Altocumulus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Altocumulus,true);
            printf("\tCloud Type = 1 : Altocumulus\n");
         }
         else if(strcmp("Altostratus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Altostratus,true);
            printf("\tCloud Type = 2 : Altostratus\n");
         }
         else if(strcmp("Cirrocumulus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cirrocumulus,true);
            printf("\tCloud Type = 3 : Cirrocumulus\n");
         }
         else if(strcmp("Cirrostratus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cirrostratus,true);
            printf("\tCloud Type = 4 : Cirrostratus\n");
         }
         else if(strcmp("Cirrus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cirrus,true);
            printf("\tCloud Type = 5 : Cirrus\n");
         }
         else if(strcmp("Cumulonimbus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cumulonimbus,true);
            printf("\tCloud Type = 6 : Cumulonimbus\n");
         }
         else if(strcmp("Cumulus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Cumulus,true);
            printf("\tCloud Type = 7 : Cumulus\n");
         }
         else if(strcmp("Nimbostratus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Nimbostratus,true);
            printf("\tCloud Type = 8 : Nimbostratus\n");
         }
         else if(strcmp("Stratocumulus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Stratocumulus,true);
            printf("\tCloud Type = 9 : Stratocumulus\n");
         }
         else if(strcmp("Stratus",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::Stratus,true);
            printf("\tCloud Type = 10 : Stratus\n");
         }
         else if(strcmp("DefA",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefA,true);
            printf("\tCloud Type = 11 : DefA\n");
         }
         else if(strcmp("DefB",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefB,true);
            printf("\tCloud Type = 12 : DefB\n");
         }
         else if(strcmp("DefC",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefC,true);
            printf("\tCloud Type = 13 : DefC\n");
         }
         else if(strcmp("DefD",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefD,true);
            printf("\tCloud Type = 14 : DefD\n");
         }
         else if(strcmp("DefE",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetCloudType(CigiBaseWeatherCtrl::DefE,true);
            printf("\tCloud Type = 15 : DefE\n");
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
         if(strcmp("Global",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetScope(CigiBaseWeatherCtrl::Global,true);
            printf("\tScope = 0 : Global\n");
         }
         else if(strcmp("Regional",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetScope(CigiBaseWeatherCtrl::Regional,true);
            printf("\tScope = 1 : Regional\n");
         }
         else if(strcmp("Entity",pPV->GetStr()) == 0)
         {
            Om_WeatherCtrl.SetScope(CigiBaseWeatherCtrl::Entity,true);
            printf("\tScope = 2 : Entity\n");
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
         Om_WeatherCtrl.SetSeverity(pPV->GetUChar(),true);
         printf("\tSeverity = %d\n",pPV->GetUChar());
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
         Om_WeatherCtrl.SetAirTemp(pPV->Getfloat(),true);
         printf("\tAir Temperature = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetVisibilityRng(pPV->Getfloat(),true);
         printf("\tVisibility Range = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetScudFreq(pPV->Getfloat(),true);
         printf("\tScud Frequency = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetCoverage(pPV->Getfloat(),true);
         printf("\tCoverage = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetBaseElev(pPV->Getfloat(),true);
         printf("\tBase Elevation = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetThickness(pPV->Getfloat(),true);
         printf("\tThickness = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetTransition(pPV->Getfloat(),true);
         printf("\tTransition = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetHorizWindSp(pPV->Getfloat(),true);
         printf("\tHorizontal Wind Speed = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetVertWindSp(pPV->Getfloat(),true);
         printf("\tVertical Wind Speed = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetWindDir(pPV->Getfloat(),true);
         printf("\tWind Direction = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetBaroPress(pPV->Getfloat(),true);
         printf("\tBarometric Pressure = %f\n",pPV->Getfloat());
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
         Om_WeatherCtrl.SetAerosol(pPV->Getfloat(),true);
         printf("\tAerosol = %f\n",pPV->Getfloat());
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


   *Omsg << Om_WeatherCtrl;

}


