// XAnimationStopV3.cpp: Body of the XAnimationStopV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XAnimationStopV3.h"
#include <CigiAnimationStopV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XAnimationStopV3::XAnimationStopV3()
{

}

XAnimationStopV3::~XAnimationStopV3()
{

}


void XAnimationStopV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiAnimationStopV3 *InPckt = (CigiAnimationStopV3 *)Packet;


   printf("Animation Stop V3:\n");
   printf("\tEntity ID = %u\n",InPckt->GetEntityID());

}


