// XSymbolTextDefV3_3.cpp: Body of the XSymbolTextDefV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSymbolTextDefV3_3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSymbolTextDefV3_3::XSymbolTextDefV3_3()
{

}

XSymbolTextDefV3_3::~XSymbolTextDefV3_3()
{

}


void XSymbolTextDefV3_3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSymbolTextDefV3_3 *InPckt = (CigiSymbolTextDefV3_3 *)Packet;

   printf("Symbol Text Definition:\n");

   printf("\tSymbol ID = %d\n",InPckt->GetSymbolID());

   printf("\tAlignment State = %d : ",InPckt->GetAlignment());
   switch(InPckt->GetAlignment())
   {
   case 0:
      printf("TopLeft\n");
      break;
   case 1:
      printf("TopCenter\n");
      break;
   case 2:
      printf("TopRight\n");
      break;
   case 3:
      printf("CenterLeft\n");
      break;
   case 4:
      printf("Center\n");
      break;
   case 5:
      printf("CenterRight\n");
      break;
   case 6:
      printf("BottomLeft\n");
      break;
   case 7:
      printf("BottomCenter\n");
      break;
   case 8:
      printf("BottomRight\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tOrientation State = %d : ",InPckt->GetOrientation());
   switch(InPckt->GetOrientation())
   {
   case 0:
      printf("LeftToRight\n");
      break;
   case 1:
      printf("TopToBottom\n");
      break;
   case 2:
      printf("RightToLeft\n");
      break;
   case 3:
      printf("BottomToTop\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tFont ID = %d\n",InPckt->GetFontID());
   printf("\tFont Size = %f\n",InPckt->GetFontSize());
   printf("\tText = %s\n",(InPckt->GetText()).c_str());

}

