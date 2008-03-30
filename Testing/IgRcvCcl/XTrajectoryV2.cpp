// XTrajectoryV2.cpp: Body of the XTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#include "XTrajectoryV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XTrajectoryV2::XTrajectoryV2()
{

}

XTrajectoryV2::~XTrajectoryV2()
{

}


void XTrajectoryV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiTrajectoryDefV2 *InPckt = (CigiTrajectoryDefV2 *)Packet;

   printf("Trajectory:\n");

   printf("\tEntityID = %d\n",InPckt->GetEntityID());
   printf("\tAcceleration = %f\n",InPckt->GetAccel());
   printf("\tRetardation Rate = %f\n",InPckt->GetRetardationRate());
   printf("\tTerminal Velocity = %f\n",InPckt->GetTermVel());


}
