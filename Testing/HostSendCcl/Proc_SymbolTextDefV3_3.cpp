// Proc_SymbolTextDefV3_3.cpp: implementation of the Proc_SymbolTextDefV3_3 Parsing
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


#include "Proc_SymbolTextDefV3_3.h"

#include "ParseValue.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Proc_SymbolTextDefV3_3::Proc_SymbolTextDefV3_3()
{
   PcktID = "SymbolTextDef";
}

Proc_SymbolTextDefV3_3::~Proc_SymbolTextDefV3_3()
{
}


void Proc_SymbolTextDefV3_3::ProcPckt(ParseValue *pPV)
{

   if(Omsg == NULL)
      return;

   bool EntAt = true;

   pPV = pPV->nxt();  // skip the cmd name

   printf("Symbol Text Definition:\n");


   if(pPV != NULL)
   {
      try
      {
         Om_SymbolTextDef.SetSymbolID(pPV->GetUShort(),true);
         printf("\tSymbol ID = %d\n",pPV->GetUShort());
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
         if(strcmp("TopLeft",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetAlignment(CigiBaseSymbolTextDef::TopLeft,true);
            printf("\tAlignment State = 0 : TopLeft\n");
         }
         else if(strcmp("TopCenter",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetAlignment(CigiBaseSymbolTextDef::TopCenter,true);
            printf("\tAlignment State = 1 : TopCenter\n");
         }
         else if(strcmp("TopRight",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetAlignment(CigiBaseSymbolTextDef::TopRight,true);
            printf("\tAlignment State = 2 : TopRight\n");
         }
         else if(strcmp("CenterLeft",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetAlignment(CigiBaseSymbolTextDef::CenterLeft,true);
            printf("\tAlignment State = 3 : CenterLeft\n");
         }
         else if(strcmp("Center",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetAlignment(CigiBaseSymbolTextDef::Center,true);
            printf("\tAlignment State = 4 : Center\n");
         }
         else if(strcmp("CenterRight",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetAlignment(CigiBaseSymbolTextDef::CenterRight,true);
            printf("\tAlignment State = 5 : CenterRight\n");
         }
         else if(strcmp("BottomLeft",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetAlignment(CigiBaseSymbolTextDef::BottomLeft,true);
            printf("\tAlignment State = 6 : BottomLeft\n");
         }
         else if(strcmp("BottomCenter",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetAlignment(CigiBaseSymbolTextDef::BottomCenter,true);
            printf("\tAlignment State = 7 : BottomCenter\n");
         }
         else if(strcmp("BottomRight",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetAlignment(CigiBaseSymbolTextDef::BottomRight,true);
            printf("\tAlignment State = 8 : BottomRight\n");
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
         if(strcmp("LeftToRight",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetOrientation(CigiBaseSymbolTextDef::LeftToRight,true);
            printf("\tOrientation State = 0 : LeftToRight\n");
         }
         else if(strcmp("TopToBottom",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetOrientation(CigiBaseSymbolTextDef::TopToBottom,true);
            printf("\tOrientation State = 1 : TopToBottom\n");
         }
         else if(strcmp("RightToLeft",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetOrientation(CigiBaseSymbolTextDef::RightToLeft,true);
            printf("\tOrientation State = 2 : RightToLeft\n");
         }
         else if(strcmp("BottomToTop",pPV->GetStr()) == 0)
         {
            Om_SymbolTextDef.SetOrientation(CigiBaseSymbolTextDef::BottomToTop,true);
            printf("\tOrientation State = 3 : BottomToTop\n");
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
         Om_SymbolTextDef.SetFontID(pPV->GetUChar(),true);
         printf("\tFont ID = %d\n",pPV->GetUChar());
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
         Om_SymbolTextDef.SetFontSize(pPV->Getfloat(),true);
         printf("\tFont Size = %f\n",pPV->Getfloat());
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
         std::string txt(pPV->GetStr());
         Om_SymbolTextDef.SetText(txt,true);
         printf("\tText = %s\n",txt.c_str());
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


   *Omsg << Om_SymbolTextDef;

}


