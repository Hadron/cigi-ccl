// XMaritimeSurfaceCtrl.cpp: Body of the XMaritimeSurfaceCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XMaritimeSurfaceCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XMaritimeSurfaceCtrl::XMaritimeSurfaceCtrl()
{

}

XMaritimeSurfaceCtrl::~XMaritimeSurfaceCtrl()
{

}


void XMaritimeSurfaceCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiMaritimeSurfaceCtrlV3 *InPckt = (CigiMaritimeSurfaceCtrlV3 *)Packet;

   bool ok = true;

   printf("===> MaritimeSurfaceCtrl <===\n");

   printf("EntityRgnID ==> %d\n",InPckt->GetEntityRgnID());
   printf("SurfaceCondEn ==> %d\n",InPckt->GetSurfaceCondEn());
   printf("WhitecapEn ==> %d\n",InPckt->GetWhitecapEn());
   printf("Scope ==> %d\n",InPckt->GetScope());
   printf("SurfaceHeight ==> %f\n",InPckt->GetSurfaceHeight());
   printf("WaterTemp ==> %f\n",InPckt->GetWaterTemp());
   printf("Clarity ==> %f\n",InPckt->GetClarity());

}
