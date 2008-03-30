// Proc_CollDetVolDefV2.cpp: implementation of the Proc_CollDetVolDefV2 Parsing
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


#include "Proc_CollDetVolDefV2.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_CollDetVolDefV2::Proc_CollDetVolDefV2()
{
   PcktID = "CollDetVolDef";
}

Proc_CollDetVolDefV2::~Proc_CollDetVolDefV2()
{
}


void Proc_CollDetVolDefV2::ProcPckt(ParseValue *pPV)
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
         // Because X Offset gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetVolDef.SetXoff(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tX Offset = %f\n",df);
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
         // Because Y Offset gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetVolDef.SetYoff(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tY Offset = %f\n",df);
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
         // Because Z Offset gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetVolDef.SetZoff(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tZ Offset = %f\n",df);
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
         // Because Height Or Radius gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetVolDef.SetHeightOrRadius(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tHeight or Radius = %f\n",df);
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
         // Because Width gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetVolDef.SetWidth(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tWidth = %f\n",df);
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
         // Because Depth gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetVolDef.SetDepth(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tDepth = %f\n",df);
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


