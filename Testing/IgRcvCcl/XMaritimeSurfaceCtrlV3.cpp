// XMaritimeSurfaceCtrlV3.cpp: Body of the XMaritimeSurfaceCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XMaritimeSurfaceCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XMaritimeSurfaceCtrlV3::XMaritimeSurfaceCtrlV3()
{

}

XMaritimeSurfaceCtrlV3::~XMaritimeSurfaceCtrlV3()
{

}


void XMaritimeSurfaceCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiMaritimeSurfaceCtrlV3 *InPckt = (CigiMaritimeSurfaceCtrlV3 *)Packet;

   bool ok = true;

   printf("Maritime Surface Control:\n");

   printf("\tEntity Region ID = %d\n",InPckt->GetEntityRgnID());
   printf("\tSurface Conditions Enable = %d\n",InPckt->GetSurfaceCondEn());
   printf("\tWhite Cap Enable = %d\n",InPckt->GetWhitecapEn());

   printf("\tScope = %d : ",InPckt->GetScope());
   switch(InPckt->GetScope())
   {
   case 0:
      printf("Global\n");
      break;
   case 1:
      printf("Regional\n");
      break;
   case 2:
      printf("Entity\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tSurface Height = %f\n",InPckt->GetSurfaceHeight());
   printf("\tWater Temperature = %f\n",InPckt->GetWaterTemp());
   printf("\tClarity = %f\n",InPckt->GetClarity());

}
