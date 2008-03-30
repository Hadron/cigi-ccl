// Proc_CollDetVolDefV3.cpp: implementation of the Proc_CollDetVolDefV3 Parsing
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


#include "Proc_CollDetVolDefV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_CollDetVolDefV3::Proc_CollDetVolDefV3()
{
   PcktID = "CollDetVolDef";
}

Proc_CollDetVolDefV3::~Proc_CollDetVolDefV3()
{
}


void Proc_CollDetVolDefV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Collision Detection Volume Definition:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetVolDef.SetEntityID(pPV->GetUShort(),true);
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
         Om_CollDetVolDef.SetVolID(pPV->GetUChar(),true);
         printf("\tVolume ID = %d\n",pPV->GetUChar());
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
         Om_CollDetVolDef.SetVolEn(pPV->GetBool(),true);
         printf("\tVolume Enable = %d\n",pPV->GetBool());
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
         if(strcmp("Sphere",pPV->GetStr()) == 0)
         {
            Om_CollDetVolDef.SetVolType(CigiBaseCollDetVolDef::Sphere,true);
            printf("\tVolume Type = 0 : Sphere\n");
         }
         else if(strcmp("Cuboid",pPV->GetStr()) == 0)
         {
            Om_CollDetVolDef.SetVolType(CigiBaseCollDetVolDef::Cuboid,true);
            printf("\tVolume Type = 1 : Cuboid\n");
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
         Om_CollDetVolDef.SetXoff(pPV->Getfloat(),true);
         printf("\tX Offset = %f\n",pPV->Getfloat());
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
         Om_CollDetVolDef.SetYoff(pPV->Getfloat(),true);
         printf("\tY Offset = %f\n",pPV->Getfloat());
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
         Om_CollDetVolDef.SetZoff(pPV->Getfloat(),true);
         printf("\tZ Offset = %f\n",pPV->Getfloat());
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
         Om_CollDetVolDef.SetHeightOrRadius(pPV->Getfloat(),true);
         printf("\tHeight or Radius = %f\n",pPV->Getfloat());
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
         Om_CollDetVolDef.SetWidth(pPV->Getfloat(),true);
         printf("\tWidth = %f\n",pPV->Getfloat());
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
         Om_CollDetVolDef.SetDepth(pPV->Getfloat(),true);
         printf("\tDepth = %f\n",pPV->Getfloat());
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
         Om_CollDetVolDef.SetRoll(pPV->Getfloat(),true);
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
         Om_CollDetVolDef.SetPitch(pPV->Getfloat(),true);
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
         Om_CollDetVolDef.SetYaw(pPV->Getfloat(),true);
         printf("\tYaw = %f\n",pPV->Getfloat());
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



   *Omsg << Om_CollDetVolDef;

}


