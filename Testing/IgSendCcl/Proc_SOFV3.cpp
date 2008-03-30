// Proc_SOFV3.cpp: implementation of the Proc_EntityCtrlV3 Parsing
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


#include "Proc_SOFV3.h"
#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SOFV3::Proc_SOFV3()
{
   PcktID = "SOFV3";
}

Proc_SOFV3::~Proc_SOFV3()
{

}


void Proc_SOFV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   printf("Start Of Frame V3:\n");
   pPV = pPV->nxt();  // skip the cmd name

   if(pPV != NULL)
   {
      try
      {
         Om_SOFV3.SetDatabaseID(pPV->GetChar(),true);
         printf("\tDatabase ID = %d\n",pPV->GetChar());
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
         Om_SOFV3.SetIGStatus(pPV->GetUChar(),true);
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
            Om_SOFV3.SetIGMode(CigiBaseSOF::Reset,true);
            printf("\tIG Mode = 0 : Reset\n");
         }
         else if(strcmp("Operate",pPV->GetStr()) == 0)
         {
            Om_SOFV3.SetIGMode(CigiBaseSOF::Operate,true);
            printf("\tIG Mode = 1 : Operate\n");
         }
         else if(strcmp("debug",pPV->GetStr()) == 0)
         {
            Om_SOFV3.SetIGMode(CigiBaseSOF::debug,true);
            printf("\tIG Mode = 2 : debug\n");
         }
         else if(strcmp("OfflineMaint",pPV->GetStr()) == 0)
         {
            Om_SOFV3.SetIGMode(CigiBaseSOF::OfflineMaint,true);
            printf("\tIG Mode = 3 : OfflineMaint\n");
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
         Om_SOFV3.SetTimeStampValid(pPV->GetBool(),true);
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
            Om_SOFV3.SetEarthRefModel(CigiBaseSOF::WGS84,true);
            printf("\tEarth Reference Model = 0 : WGS84\n");
         }
         else if(strcmp("HostDefined",pPV->GetStr()) == 0)
         {
            Om_SOFV3.SetEarthRefModel(CigiBaseSOF::HostDefined,true);
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
         Om_SOFV3.SetFrameCntr(pPV->GetULong(),true);
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
         Om_SOFV3.SetTimeStamp(pPV->GetULong(),true);
         printf("\tTime Stamp = %u\n",pPV->GetULong());
      }
      catch(CigiValueOutOfRangeException ORX)
      {
         if(ORX.HasMessage())
            printf("%s\n",ORX.what());
      }

      pPV = pPV->nxt();
   }

   *Omsg << Om_SOFV3;


}


