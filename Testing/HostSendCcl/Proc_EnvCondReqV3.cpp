// Proc_EnvCondReqV3.cpp: implementation of the Proc_EnvCondReqV3 Parsing
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


#include "Proc_EnvCondReqV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_EnvCondReqV3::Proc_EnvCondReqV3()
{
   PcktID = "EnvCondReq";
}

Proc_EnvCondReqV3::~Proc_EnvCondReqV3()
{
}


void Proc_EnvCondReqV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Environmental Condition Request:\n");

   unsigned char tReqType = 0;

   if(pPV != NULL)
   {
      if(strcmp("Maritime",pPV->GetStr()) == 0)
      {
         tReqType = (unsigned char)CigiBaseEnvCondReq::Maritime;
         printf("\tRequest Type = 1 : Maritime\n");
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      if(strcmp("Terrestrial",pPV->GetStr()) == 0)
      {
         tReqType |= (unsigned char)CigiBaseEnvCondReq::Terrestrial;
         printf("\tRequest Type = 2 : Terrestrial\n");
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      if(strcmp("Weather",pPV->GetStr()) == 0)
      {
         tReqType |= (unsigned char)CigiBaseEnvCondReq::Weather;
         printf("\tRequest Type = 4 : Weather\n");
      }

      pPV = pPV->nxt();
   }

   if(pPV != NULL)
   {
      if(strcmp("Aerosol",pPV->GetStr()) == 0)
      {
         tReqType |= (unsigned char)CigiBaseEnvCondReq::Aerosol;
         printf("\tRequest Type = 8 : Aerosol\n");
      }

      pPV = pPV->nxt();
   }

   try
   {
      Om_EnvCondReq.SetReqType(tReqType,true);
   }
   catch(CigiValueOutOfRangeException ORX)
   {
      if(ORX.HasMessage())
         printf("%s\n",ORX.what());
   }


   if(pPV != NULL)
   {
      try
      {
         Om_EnvCondReq.SetReqID(pPV->GetUChar(),true);
         printf("\tRequest ID = %d\n",pPV->GetUChar());
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
         Om_EnvCondReq.SetLat(pPV->Getdouble(),true);
         printf("\tLatitude = %f\n",pPV->Getdouble());
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
         Om_EnvCondReq.SetLon(pPV->Getdouble(),true);
         printf("\tLongitude = %f\n",pPV->Getdouble());
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
         Om_EnvCondReq.SetAlt(pPV->Getdouble(),true);
         printf("\tAltitude = %f\n",pPV->Getdouble());
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


   *Omsg << Om_EnvCondReq;

}


