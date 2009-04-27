// Proc_CompCtrlV3_3.cpp: implementation of the Proc_CompCtrlV3_3 Parsing
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


#include "Proc_CompCtrlV3_3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_CompCtrlV3_3::Proc_CompCtrlV3_3()
{
   PcktID = "CompCtrl";
}

Proc_CompCtrlV3_3::~Proc_CompCtrlV3_3()
{
}


void Proc_CompCtrlV3_3::ProcPckt(ParseValue *pPV)
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
         if(strcmp("EntityV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::EntityV3,true);
            printf("\tComp Class = 0 : EntityV3\n");
         }
         else if(strcmp("ViewV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::ViewV3,true);
            printf("\tComp Class = 1 : ViewV3\n");
         }
         else if(strcmp("ViewGrpV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::ViewGrpV3,true);
            printf("\tComp Class = 2 : ViewGrpV3\n");
         }
         else if(strcmp("SensorV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::SensorV3,true);
            printf("\tComp Class = 3 : SensorV3\n");
         }
         else if(strcmp("RegionalSeaSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::RegionalSeaSurfaceV3,true);
            printf("\tComp Class = 4 : RegionalSeaSurfaceV3\n");
         }
         else if(strcmp("RegionalTerrainSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::RegionalTerrainSurfaceV3,true);
            printf("\tComp Class = 5 : RegionalTerrainSurfaceV3\n");
         }
         else if(strcmp("RegionalLayeredWeatherV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::RegionalLayeredWeatherV3,true);
            printf("\tComp Class = 6 : RegionalLayeredWeatherV3\n");
         }
         else if(strcmp("GlobalSeaSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::GlobalSeaSurfaceV3,true);
            printf("\tComp Class = 7 : GlobalSeaSurfaceV3\n");
         }
         else if(strcmp("GlobalTerrainSurfaceV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::GlobalTerrainSurfaceV3,true);
            printf("\tComp Class = 8 : GlobalTerrainSurfaceV3\n");
         }
         else if(strcmp("GlobalLayeredWeatherV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::GlobalLayeredWeatherV3,true);
            printf("\tComp Class = 9 : GlobalLayeredWeatherV3\n");
         }
         else if(strcmp("AtmosphereV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::AtmosphereV3,true);
            printf("\tComp Class = 10 : AtmosphereV3\n");
         }
         else if(strcmp("CelestialSphereV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::CelestialSphereV3,true);
            printf("\tComp Class = 11 : CelestialSphereV3\n");
         }
         else if(strcmp("EventV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::EventV3,true);
            printf("\tComp Class = 12 : EventV3\n");
         }
         else if(strcmp("SystemV3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::SystemV3,true);
            printf("\tComp Class = 13 : SystemV3\n");
         }
         else if(strcmp("SymbolSurfaceV3_3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::SymbolSurfaceV3_3,true);
            printf("\tComp Class = 14 : SymbolSurfaceV3_3\n");
         }
         else if(strcmp("SymbolV3_3",pPV->GetStr()) == 0)
         {
            Om_CompCtrl.SetCompClassV3(CigiBaseCompCtrl::SymbolV3_3,true);
            printf("\tComp Class = 15 : SymbolV3_3\n");
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
         Om_CompCtrl.SetCompState(pPV->GetUChar(),true);
         printf("\tComponent State = %d\n",pPV->GetUChar());
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
         Om_CompCtrl.SetCompData((Cigi_uint32)pPV->GetULong(),0,true);
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
         Om_CompCtrl.SetCompData((Cigi_uint32)pPV->GetULong(),1,true);
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
   {
      try
      {
         Om_CompCtrl.SetCompData((Cigi_uint32)pPV->GetULong(),2,true);
         printf("\tComponent Data 2 = %d\n",pPV->GetULong());
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
         Om_CompCtrl.SetCompData((Cigi_uint32)pPV->GetULong(),3,true);
         printf("\tComponent Data 3 = %d\n",pPV->GetULong());
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
         Om_CompCtrl.SetCompData((Cigi_uint32)pPV->GetULong(),4,true);
         printf("\tComponent Data 4 = %d\n",pPV->GetULong());
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
         Om_CompCtrl.SetCompData((Cigi_uint32)pPV->GetULong(),5,true);
         printf("\tComponent Data 5 = %d\n",pPV->GetULong());
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


