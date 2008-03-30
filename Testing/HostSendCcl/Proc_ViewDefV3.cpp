// Proc_ViewDefV3.cpp: implementation of the Proc_ViewDefV3 Parsing
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


#include "Proc_ViewDefV3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_ViewDefV3::Proc_ViewDefV3()
{
   PcktID = "ViewDef";
}

Proc_ViewDefV3::~Proc_ViewDefV3()
{
}


void Proc_ViewDefV3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;


   pPV = pPV->nxt();  // skip the cmd name

   printf("View Definition:\n");

   if(pPV != NULL)
   {
      try
      {
         Om_ViewDef.SetViewID(pPV->GetUShort(),true);
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
         Om_ViewDef.SetGroupID(pPV->GetUChar(),true);
         printf("\tGroup ID = %d\n",pPV->GetUChar());
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
         Om_ViewDef.SetFOVNearEn(pPV->GetBool(),true);
         printf("\tNear FOV Clipping Plane Enable = %d\n",pPV->GetBool());
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
         Om_ViewDef.SetFOVFarEn(pPV->GetBool(),true);
         printf("\tFar FOV Clipping Plane Enable = %d\n",pPV->GetBool());
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
         Om_ViewDef.SetFOVLeftEn(pPV->GetBool(),true);
         printf("\tLeft FOV Clipping Plane Enable = %d\n",pPV->GetBool());
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
         Om_ViewDef.SetFOVRightEn(pPV->GetBool(),true);
         printf("\tRight FOV Clipping Plane Enable = %d\n",pPV->GetBool());
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
         Om_ViewDef.SetFOVTopEn(pPV->GetBool(),true);
         printf("\tTop FOV Clipping Plane Enable = %d\n",pPV->GetBool());
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
         Om_ViewDef.SetFOVBottomEn(pPV->GetBool(),true);
         printf("\tBottom FOV Clipping Plane Enable = %d\n",pPV->GetBool());
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
         if(strcmp("MirrorNone",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetMirrorMode(CigiBaseViewDef::MirrorNone,true);
            printf("\tMirror Mode = 0 : MirrorNone\n");
         }
         else if(strcmp("Horizontal",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetMirrorMode(CigiBaseViewDef::Horizontal,true);
            printf("\tMirror Mode = 1 : Horizontal\n");
         }
         else if(strcmp("Vertical",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetMirrorMode(CigiBaseViewDef::Vertical,true);
            printf("\tMirror Mode = 2 : Vertical\n");
         }
         else if(strcmp("Horiz_Vert",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetMirrorMode(CigiBaseViewDef::Horiz_Vert,true);
            printf("\tMirror Mode = 3 : Horiz_Vert\n");
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
         if(strcmp("ReplicateNone",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateNone,true);
            printf("\tReplicate Mode = 0 : ReplicateNone\n");
         }
         else if(strcmp("Replicate1x2",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::Replicate1x2,true);
            printf("\tReplicate Mode = 1 : Replicate1x2\n");
         }
         else if(strcmp("Replicate2x1",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::Replicate2x1,true);
            printf("\tReplicate Mode = 2 : Replicate2x1\n");
         }
         else if(strcmp("Replicate2x2",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::Replicate2x2,true);
            printf("\tReplicate Mode = 3 : Replicate2x2\n");
         }
         else if(strcmp("ReplicateDefA",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateDefA,true);
            printf("\tReplicate Mode = 4 : ReplicateDefA\n");
         }
         else if(strcmp("ReplicateDefB",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateDefB,true);
            printf("\tReplicate Mode = 5 : ReplicateDefB\n");
         }
         else if(strcmp("ReplicateDefC",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateDefC,true);
            printf("\tReplicate Mode = 6 : ReplicateDefC\n");
         }
         else if(strcmp("ReplicateDefD",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetPixelReplicateMode(CigiBaseViewDef::ReplicateDefD,true);
            printf("\tReplicate Mode = 7 : ReplicateDefD\n");
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
         if(strcmp("Perspective",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetProjectionType(CigiBaseViewDef::Perspective,true);
            printf("\tProjection Type = 0 : Perspective\n");
         }
         else if(strcmp("Orthographic",pPV->GetStr()) == 0)
         {
            Om_ViewDef.SetProjectionType(CigiBaseViewDef::Orthographic,true);
            printf("\tProjection Type = 1 : Orthographic\n");
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
         Om_ViewDef.SetReorder(pPV->GetBool(),true);
         printf("\tReorder = %d\n",pPV->GetBool());
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
         Om_ViewDef.SetViewType(pPV->GetUChar(),true);
         printf("\tView Type = %d\n",pPV->GetUChar());
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
         Om_ViewDef.SetFOVNear(pPV->Getfloat(),true);
         printf("\tNear FOV Clipping Plane = %f\n",pPV->Getfloat());
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
         Om_ViewDef.SetFOVFar(pPV->Getfloat(),true);
         printf("\tFar FOV Clipping Plane = %f\n",pPV->Getfloat());
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
         Om_ViewDef.SetFOVLeft(pPV->Getfloat(),true);
         printf("\tLeft FOV Clipping Plane = %f\n",pPV->Getfloat());
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
         Om_ViewDef.SetFOVRight(pPV->Getfloat(),true);
         printf("\tRight FOV Clipping Plane = %f\n",pPV->Getfloat());
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
         Om_ViewDef.SetFOVTop(pPV->Getfloat(),true);
         printf("\tTop FOV Clipping Plane = %f\n",pPV->Getfloat());
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
         Om_ViewDef.SetFOVBottom(pPV->Getfloat(),true);
         printf("\tBottom FOV Clipping Plane = %f\n",pPV->Getfloat());
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


   *Omsg << Om_ViewDef;

}


