// Proc_SOFV3_2.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_SOFV3_2.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SOFV3_2::Proc_SOFV3_2()
{
   PcktID = "SOFV3_2";
}

Proc_SOFV3_2::~Proc_SOFV3_2()
{

}


void Proc_SOFV3_2::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Start Of Frame V3_2:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_SOFV3_2.SetDatabaseID(pPV->GetUChar(),true);
         printf("\tDatabase ID = %u\n",pPV->GetUChar());
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
         Om_SOFV3_2.SetIGStatus(pPV->GetUChar(),true);
         printf("\tIG Status = %u\n",pPV->GetUChar());
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
         if(strcmp("Reset",pPV->GetStr()) == 0)
         {
            Om_SOFV3_2.SetIGMode(CigiBaseSOF::Reset,true);
            printf("\tIG Mode = 0 : Reset\n");
         }
         else if(strcmp("Standby",pPV->GetStr()) == 0)
         {
            Om_SOFV3_2.SetIGMode(CigiBaseSOF::Standby,true);
            printf("\tIG Mode = 1 : Standby\n");
         }
         else if(strcmp("Operate",pPV->GetStr()) == 0)
         {
            Om_SOFV3_2.SetIGMode(CigiBaseSOF::Operate,true);
            printf("\tIG Mode = 2 : Operate\n");
         }
         else if(strcmp("debug",pPV->GetStr()) == 0)
         {
            Om_SOFV3_2.SetIGMode(CigiBaseSOF::debug,true);
            printf("\tIG Mode = 3 : debug\n");
         }
         else if(strcmp("OfflineMaint",pPV->GetStr()) == 0)
         {
            Om_SOFV3_2.SetIGMode(CigiBaseSOF::OfflineMaint,true);
            printf("\tIG Mode = 4 : OfflineMaint\n");
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
         Om_SOFV3_2.SetTimeStampValid(pPV->GetBool(),true);
         printf("\tTime Stamp Valid = %d\n",pPV->GetBool());
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
         if(strcmp("WGS84",pPV->GetStr()) == 0)
         {
            Om_SOFV3_2.SetEarthRefModel(CigiBaseSOF::WGS84,true);
            printf("\tEarth Reference Model = 0 : WGS84\n");
         }
         else if(strcmp("HostDefined",pPV->GetStr()) == 0)
         {
            Om_SOFV3_2.SetEarthRefModel(CigiBaseSOF::HostDefined,true);
            printf("\tEarth Reference Model = 1 : HostDefined\n");
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
         Om_SOFV3_2.SetFrameCntr(pPV->GetULong(),true);
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
         Om_SOFV3_2.SetTimeStamp(pPV->GetULong(),true);
         printf("\tTime Stamp = %u\n",pPV->GetULong());
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
         Om_SOFV3_2.SetLastRcvdHostFrame(pPV->GetULong(),true);
         printf("\tLast Received Host Frame = %u\n",pPV->GetULong());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_SOFV3_2;


}


