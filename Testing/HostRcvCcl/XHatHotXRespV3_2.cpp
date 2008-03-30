// XHatHotXRespV3_2.cpp: Body of the XHatHotXRespV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatHotXRespV3_2.h"
#include <CigiHatHotXRespV3_2.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatHotXRespV3_2::XHatHotXRespV3_2()
{

}

XHatHotXRespV3_2::~XHatHotXRespV3_2()
{

}


void XHatHotXRespV3_2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatHotXRespV3_2 *InPckt = (CigiHatHotXRespV3_2 *)Packet;


   printf("HAT HOT Extended Response V3_2:\n");
   printf("\tHat Hot ID = %u\n",InPckt->GetHatHotID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tHost Frame ID = %u\n",InPckt->GetHostFrame());
   printf("\tHat = %f\n",InPckt->GetHat());
   printf("\tHot = %f\n",InPckt->GetHot());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tNormal Azimuth = %f\n",InPckt->GetNormAz());
   printf("\tNormal Elevation = %f\n",InPckt->GetNormEl());

}


