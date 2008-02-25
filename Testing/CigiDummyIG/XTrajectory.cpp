// XTrajectory.cpp: Body of the XTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#include "XTrajectory.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XTrajectory::XTrajectory()
{

}

XTrajectory::~XTrajectory()
{

}


void XTrajectory::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiTrajectoryDefV3 *InPckt = (CigiTrajectoryDefV3 *)Packet;

   printf("===> Trajectory <===\n");

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("AccelX ==> %f\n",InPckt->GetAccelX());
   printf("AccelY ==> %f\n",InPckt->GetAccelY());
   printf("AccelZ ==> %f\n",InPckt->GetAccelZ());
   printf("RetardationRate ==> %f\n",InPckt->GetRetardationRate());
   printf("TermVel ==> %f\n",InPckt->GetTermVel());


}
