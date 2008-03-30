// Proc_EnvRgnCtrlV3.cpp: implementation of the Proc_EnvRgnCtrlV3 Parsing
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


#include "Proc_EnvRgnCtrlV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_EnvRgnCtrlV3::Proc_EnvRgnCtrlV3()
{
   PcktID = "EnvRgnCtrl";
}

Proc_EnvRgnCtrlV3::~Proc_EnvRgnCtrlV3()
{
}


void Proc_EnvRgnCtrlV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Environmental Region Control\n");

   if(pPV != NULL)
   {
      try
      {
         Om_EnvRgnCtrl.SetRegionID(pPV->GetUShort(),true);
         printf("\tRegion ID = %d\n",pPV->GetUShort());
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
         if(strcmp("Inactive",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetRgnState(CigiBaseEnvRgnCtrl::Inactive,true);
            printf("\tRegion State = 0 : Inactive\n");
         }
         else if(strcmp("Active",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetRgnState(CigiBaseEnvRgnCtrl::Active,true);
            printf("\tRegion State = 1 : Active\n");
         }
         else if(strcmp("Destroyed",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetRgnState(CigiBaseEnvRgnCtrl::Destroyed,true);
            printf("\tRegion State = 2 : Destroyed\n");
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
         if(strcmp("UseLast",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetWeatherProp(CigiBaseEnvRgnCtrl::UseLast,true);
            printf("\tWeather Property = 0 : UseLast\n");
         }
         else if(strcmp("Merge",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetWeatherProp(CigiBaseEnvRgnCtrl::Merge,true);
            printf("\tWeather Property = 1 : Merge\n");
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
         if(strcmp("UseLast",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetAerosol(CigiBaseEnvRgnCtrl::UseLast,true);
            printf("\tAerosol = 0 : UseLast\n");
         }
         else if(strcmp("Merge",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetAerosol(CigiBaseEnvRgnCtrl::Merge,true);
            printf("\tAerosol = 1 : Merge\n");
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
         if(strcmp("UseLast",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetMaritimeSurface(CigiBaseEnvRgnCtrl::UseLast,true);
            printf("\tMaritime Surface = 0 : UseLast\n");
         }
         else if(strcmp("Merge",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetMaritimeSurface(CigiBaseEnvRgnCtrl::Merge,true);
            printf("\tMaritime Surface = 1 : Merge\n");
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
         if(strcmp("UseLast",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetTerrestrialSurface(CigiBaseEnvRgnCtrl::UseLast,true);
            printf("\tTerrestrial Surface = 0 : UseLast\n");
         }
         else if(strcmp("Merge",pPV->GetStr()) == 0)
         {
            Om_EnvRgnCtrl.SetTerrestrialSurface(CigiBaseEnvRgnCtrl::Merge,true);
            printf("\tTerrestrial Surface = 1 : Merge\n");
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
         Om_EnvRgnCtrl.SetLat(pPV->Getdouble(),true);
         printf("\tLat = %f\n",pPV->Getdouble());
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
         Om_EnvRgnCtrl.SetLon(pPV->Getdouble(),true);
         printf("\tLon = %f\n",pPV->Getdouble());
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
         Om_EnvRgnCtrl.SetXSize(pPV->Getfloat(),true);
         printf("\tX Size = %f\n",pPV->Getfloat());
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
         Om_EnvRgnCtrl.SetYSize(pPV->Getfloat(),true);
         printf("\tY Size = %f\n",pPV->Getfloat());
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
         Om_EnvRgnCtrl.SetCornerRadius(pPV->Getfloat(),true);
         printf("\tCorner Radius = %f\n",pPV->Getfloat());
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
         Om_EnvRgnCtrl.SetRotation(pPV->Getfloat(),true);
         printf("\tRotation = %f\n",pPV->Getfloat());
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
         Om_EnvRgnCtrl.SetTransition(pPV->Getfloat(),true);
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
      DefHex = pPV->GetStr();


   *Omsg << Om_EnvRgnCtrl;

}


