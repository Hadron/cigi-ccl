// XSensorResp.cpp: Body of the XSensorResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XSensorResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSensorResp::XSensorResp()
{

}

XSensorResp::~XSensorResp()
{

}


void XSensorResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiSensorRespV3 *InPckt = (CigiSensorRespV3 *)Packet;

   printf("ViewID ==> %d\n",InPckt->GetViewID());
   printf("SensorID ==> %d\n",InPckt->GetSensorID());
   printf("SensorStat ==> %d\n",InPckt->GetSensorStat());
   printf("GateSzX ==> %d\n",InPckt->GetGateSzX());
   printf("GateSzY ==> %d\n",InPckt->GetGateSzY());
   printf("GateXoff ==> %f\n",InPckt->GetGateXoff());
   printf("GateYoff ==> %f\n",InPckt->GetGateYoff());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());


}
