// XHatHotReqV3.cpp: Body of the XHatHotReqV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatHotReqV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatHotReqV3::XHatHotReqV3()
{

}

XHatHotReqV3::~XHatHotReqV3()
{

}


void XHatHotReqV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatHotReqV3 *InPckt = (CigiHatHotReqV3 *)Packet;

   bool ok = true;

   printf("Hot/Hat Request:\n");

   printf("\tHat-Hot ID = %d\n",InPckt->GetHatHotID());

   printf("\tRequest Type = %d : ",InPckt->GetReqType());
   switch(InPckt->GetReqType())
   {
   case 0:
      printf("HAT\n");
      break;
   case 1:
      printf("HOT\n");
      break;
   case 2:
      printf("Extended\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tSource Coordinate System = %d : ",InPckt->GetSrcCoordSys());
   switch(InPckt->GetSrcCoordSys())
   {
   case 0:
      printf("Geodetic\n");
      break;
   case 1:
      printf("Entity\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tX Offset = %f\n",InPckt->GetXoff());
   printf("\tY Offset = %f\n",InPckt->GetYoff());
   printf("\tZ Offset = %f\n",InPckt->GetZoff());

}

