// XTrajectoryV3.cpp: Body of the XTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#include "XTrajectoryV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XTrajectoryV3::XTrajectoryV3()
{

}

XTrajectoryV3::~XTrajectoryV3()
{

}


void XTrajectoryV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiTrajectoryDefV3 *InPckt = (CigiTrajectoryDefV3 *)Packet;

   printf("Trajectory:\n");

   printf("\tEntityID = %d\n",InPckt->GetEntityID());
   printf("\tX Acceleration = %f\n",InPckt->GetAccelX());
   printf("\tY Acceleration = %f\n",InPckt->GetAccelY());
   printf("\tZ Acceleration = %f\n",InPckt->GetAccelZ());
   printf("\tRetardation Rate = %f\n",InPckt->GetRetardationRate());
   printf("\tTerminal Velocity = %f\n",InPckt->GetTermVel());


}
