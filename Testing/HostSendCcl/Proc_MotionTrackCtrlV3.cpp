// Proc_MotionTrackCtrlV3.cpp: implementation of the Proc_MotionTrackCtrlV3 Parsing
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


#include "Proc_MotionTrackCtrlV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_MotionTrackCtrlV3::Proc_MotionTrackCtrlV3()
{
   PcktID = "MotionTrackCtrl";
}

Proc_MotionTrackCtrlV3::~Proc_MotionTrackCtrlV3()
{
}


void Proc_MotionTrackCtrlV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("Motion Tracker Control:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_MotionTrackCtrl.SetViewID(pPV->GetUShort(),true);
         printf("\tView ID = %d\n",pPV->GetUShort());
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
         Om_MotionTrackCtrl.SetTrackerID(pPV->GetUChar(),true);
         printf("\tTracker ID = %d\n",pPV->GetUChar());
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
         Om_MotionTrackCtrl.SetTrackerEn(pPV->GetBool(),true);
         printf("\tTracker Enable = %d\n",pPV->GetBool());
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
         Om_MotionTrackCtrl.SetBoresightEn(pPV->GetBool(),true);
         printf("\tBoresight Enable = %d\n",pPV->GetBool());
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
         Om_MotionTrackCtrl.SetXEn(pPV->GetBool(),true);
         printf("\tX Enable = %d\n",pPV->GetBool());
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
         Om_MotionTrackCtrl.SetYEn(pPV->GetBool(),true);
         printf("\tY Enable = %d\n",pPV->GetBool());
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
         Om_MotionTrackCtrl.SetZEn(pPV->GetBool(),true);
         printf("\tZ Enable = %d\n",pPV->GetBool());
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
         Om_MotionTrackCtrl.SetRollEn(pPV->GetBool(),true);
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
         Om_MotionTrackCtrl.SetPitchEn(pPV->GetBool(),true);
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
         Om_MotionTrackCtrl.SetYawEn(pPV->GetBool(),true);
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
         if(strcmp("View",pPV->GetStr()) == 0)
         {
            Om_MotionTrackCtrl.SetScope(CigiBaseMotionTrackCtrl::View,true);
            printf("\tScope = 0 : View\n");
         }
         else if(strcmp("ViewGrp",pPV->GetStr()) == 0)
         {
            Om_MotionTrackCtrl.SetScope(CigiBaseMotionTrackCtrl::ViewGrp,true);
            printf("\tScope = 1 : ViewGrp\n");
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
      DefHex = pPV->GetStr();


   *Omsg << Om_MotionTrackCtrl;

}


