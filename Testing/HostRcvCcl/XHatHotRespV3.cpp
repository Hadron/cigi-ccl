// XHatHotRespV3.cpp: Body of the XHatHotRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatHotRespV3.h"
#include <CigiHatHotRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatHotRespV3::XHatHotRespV3()
{

}

XHatHotRespV3::~XHatHotRespV3()
{

}


void XHatHotRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatHotRespV3 *InPckt = (CigiHatHotRespV3 *)Packet;


   printf("HAT HOT Response V3:\n");
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

   if(tType == 0)
      printf("\tHat = %f\n",InPckt->GetHat());
   else if(tType == 1)
      printf("\tHot = %f\n",InPckt->GetHot());

}


