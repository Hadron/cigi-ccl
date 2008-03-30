// XHatHotRespV3_2.cpp: Body of the XHatHotRespV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatHotRespV3_2.h"
#include <CigiHatHotRespV3_2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatHotRespV3_2::XHatHotRespV3_2()
{

}

XHatHotRespV3_2::~XHatHotRespV3_2()
{

}


void XHatHotRespV3_2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatHotRespV3_2 *InPckt = (CigiHatHotRespV3_2 *)Packet;


   printf("HAT HOT Response V3_2:\n");
   printf("\tHat Hot ID = %u\n",InPckt->GetHatHotID());
   printf("\tValid = %d\n",InPckt->GetValid());

   int tType = (int)InPckt->GetReqType();
   printf("\tRequest Type = %d : ",tType);
   switch(tType)
   {
   case 0:
      printf("HAT\n");
      break;
   case 1:
      printf("HOT\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tHost Frame ID = %d\n",InPckt->GetHostFrame());

   if(tType == 0)
      printf("\tHat = %f\n",InPckt->GetHat());
   else if(tType == 1)
      printf("\tHot = %f\n",InPckt->GetHot());

}


