// XHatHotXRespV3.cpp: Body of the XHatHotXRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XHatHotXRespV3.h"
#include <CigiHatHotXRespV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XHatHotXRespV3::XHatHotXRespV3()
{

}

XHatHotXRespV3::~XHatHotXRespV3()
{

}


void XHatHotXRespV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiHatHotXRespV3 *InPckt = (CigiHatHotXRespV3 *)Packet;


   printf("HAT HOT Extended Response V3:\n");
   printf("\tHat Hot ID = %u\n",InPckt->GetHatHotID());
   printf("\tValid = %d\n",InPckt->GetValid());
   printf("\tHat = %f\n",InPckt->GetHat());
   printf("\tHot = %f\n",InPckt->GetHot());
   printf("\tMaterial = %u\n",InPckt->GetMaterial());
   printf("\tNormal Azimuth = %f\n",InPckt->GetNormAz());
   printf("\tNormal Elevation = %f\n",InPckt->GetNormEl());

}


