// XSymbolCloneV3_3.cpp: Body of the XSymbolCloneV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSymbolCloneV3_3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSymbolCloneV3_3::XSymbolCloneV3_3()
{

}

XSymbolCloneV3_3::~XSymbolCloneV3_3()
{

}


void XSymbolCloneV3_3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSymbolCloneV3_3 *InPckt = (CigiSymbolCloneV3_3 *)Packet;

   printf("Symbol Clone:\n");

   printf("\tSymbol ID = %d\n",InPckt->GetSymbolID());

   printf("\tSource Type = %d : ",InPckt->GetSourceType());
   switch(InPckt->GetSourceType())
   {
   case 0:
      printf("Symbol\n");
      break;
   case 1:
      printf("Symbol Template\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tSource ID = %d\n",InPckt->GetSourceID());

}

