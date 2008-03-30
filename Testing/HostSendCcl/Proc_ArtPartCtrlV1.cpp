// Proc_ArtPartCtrlV1.cpp: implementation of the Proc_ArtPartCtrlV1 Parsing
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


#include "Proc_ArtPartCtrlV1.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_ArtPartCtrlV1::Proc_ArtPartCtrlV1()
{
   PcktID = "ArtPartCtrl";
}

Proc_ArtPartCtrlV1::~Proc_ArtPartCtrlV1()
{
}


void Proc_ArtPartCtrlV1::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Articulated Part Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_ArtPartCtrl.SetEntityID(pPV->GetUShort(),true);
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
         Om_ArtPartCtrl.SetArtPartID(pPV->GetUChar(),true);
         printf("\tArticulated Part ID = %d\n",pPV->GetUChar());
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
         Om_ArtPartCtrl.SetArtPartEn(pPV->GetBool(),true);
         printf("\tArticulated Part Enable = %d\n",pPV->GetBool());
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
         Om_ArtPartCtrl.SetXOffEn(pPV->GetBool(),true);
         printf("\tX Offset Enable = %d\n",pPV->GetBool());
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
         Om_ArtPartCtrl.SetYOffEn(pPV->GetBool(),true);
         printf("\tY Offset Enable = %d\n",pPV->GetBool());
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
         Om_ArtPartCtrl.SetZOffEn(pPV->GetBool(),true);
         printf("\tZ Offset Enable = %d\n",pPV->GetBool());
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
         Om_ArtPartCtrl.SetRollEn(pPV->GetBool(),true);
         printf("\tRoll Enable = %d\n",pPV->GetBool());
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
         Om_ArtPartCtrl.SetPitchEn(pPV->GetBool(),true);
         printf("\tPitch Enable = %d\n",pPV->GetBool());
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
         Om_ArtPartCtrl.SetYawEn(pPV->GetBool(),true);
         printf("\tYaw Enable = %d\n",pPV->GetBool());
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
         Om_ArtPartCtrl.SetXOff(tf,true);
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
         Om_ArtPartCtrl.SetYOff(tf,true);
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
         Om_ArtPartCtrl.SetZOff(tf,true);
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
         // Because Roll gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_ArtPartCtrl.SetRoll(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.0054931654f);
         float df = ((float)ti) * 0.0054931654f;
         printf("\tRoll = %f\n",df);
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
         // Because Pitch gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_ArtPartCtrl.SetPitch(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.0054931654f);
         float df = ((float)ti) * 0.0054931654f;
         printf("\tPitch = %f\n",df);
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
         // Because Yaw gets converted to a fixed point number
         //  the output print needs to be adjusted to give the actual
         //  value put into the packet
         float tf = pPV->Getfloat();
         Om_ArtPartCtrl.SetYaw(tf,true);
         Cigi_int16 ti = (Cigi_int16)(tf / 0.0054931654f);
         float df = ((float)ti) * 0.0054931654f;
         printf("\tYaw = %f\n",df);
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


   *Omsg << Om_ArtPartCtrl;

}


