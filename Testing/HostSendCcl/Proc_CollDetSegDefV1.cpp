// Proc_CollDetSegDefV1.cpp: implementation of the Proc_CollDetSegDefV1 Parsing
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


#include "Proc_CollDetSegDefV1.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_CollDetSegDefV1::Proc_CollDetSegDefV1()
{
   PcktID = "CollDetSegDef";
}

Proc_CollDetSegDefV1::~Proc_CollDetSegDefV1()
{
}


void Proc_CollDetSegDefV1::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Collision Detection Segment Definition:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_CollDetSegDef.SetEntityID(pPV->GetUShort(),true);
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
         Om_CollDetSegDef.SetSegmentID(pPV->GetUChar(),true);
         printf("\tSegment ID = %d\n",pPV->GetUChar());
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
         Om_CollDetSegDef.SetSegmentEn(pPV->GetBool(),true);
         printf("\tSegment Enable = %d\n",pPV->GetBool());
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
         // Because Start X gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetSegDef.SetX1(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tStart X = %f\n",df);
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
         // Because Start Y gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetSegDef.SetY1(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tStart Y = %f\n",df);
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
         // Because Start Z gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetSegDef.SetZ1(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tStart Z = %f\n",df);
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
         // Because End X gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetSegDef.SetX2(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tEnding X = %f\n",df);
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
         // Because End Y gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetSegDef.SetY2(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tEnding Y = %f\n",df);
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
         // Because End Z gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_CollDetSegDef.SetZ2(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.015625f);
         float df = ((float)ti) * 0.015625f;
         printf("\tEnding Z = %f\n",df);
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
         Om_CollDetSegDef.SetMask(pPV->GetULong(),true);
         printf("\tMask = %d\n",pPV->GetULong());
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


   *Omsg << Om_CollDetSegDef;

}


