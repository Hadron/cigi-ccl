// XTrajectoryV1.cpp: Body of the XTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#include "XTrajectoryV1.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XTrajectoryV1::XTrajectoryV1()
{

}

XTrajectoryV1::~XTrajectoryV1()
{

}


void XTrajectoryV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiTrajectoryDefV1 *InPckt = (CigiTrajectoryDefV1 *)Packet;

   printf("Trajectory:\n");

   printf("\tEntityID = %d\n",InPckt->GetEntityID());
   printf("\tAcceleration = %f\n",InPckt->GetAccel());
   printf("\tRetardation Rate = %f\n",InPckt->GetRetardationRate());
   printf("\tTerminal Velocity = %f\n",InPckt->GetTermVel());
   printf("\tX Offset = %f\n",InPckt->GetXoff());
   printf("\tY Offset = %f\n",InPckt->GetYoff());
   printf("\tZ Offset = %f\n",InPckt->GetZoff());


}
