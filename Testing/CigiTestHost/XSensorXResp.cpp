// XSensorXResp.cpp: Body of the XSensorXResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XSensorXResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSensorXResp::XSensorXResp()
{

}

XSensorXResp::~XSensorXResp()
{

}


void XSensorXResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiSensorXRespV3 *InPckt = (CigiSensorXRespV3 *)Packet;

   printf("ViewID ==> %d\n",InPckt->GetViewID());
   printf("SensorID ==> %d\n",InPckt->GetSensorID());
   printf("SensorStat ==> %d\n",InPckt->GetSensorStat());
   printf("EntityTgt ==> %d\n",InPckt->GetEntityTgt());
   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("GateSzX ==> %d\n",InPckt->GetGateSzX());
   printf("GateSzY ==> %d\n",InPckt->GetGateSzY());
   printf("GateXoff ==> %f\n",InPckt->GetGateXoff());
   printf("GateYoff ==> %f\n",InPckt->GetGateYoff());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());
   printf("TrackPntLat ==> %f\n",InPckt->GetTrackPntLat());
   printf("TrackPntLon ==> %f\n",InPckt->GetTrackPntLon());
   printf("TrackPntAlt ==> %f\n",InPckt->GetTrackPntAlt());



}
