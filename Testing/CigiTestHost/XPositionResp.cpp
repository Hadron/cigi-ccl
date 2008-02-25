// XPositionResp.cpp: Body of the XPositionResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XPositionResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XPositionResp::XPositionResp()
{

}

XPositionResp::~XPositionResp()
{

}


void XPositionResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiPositionRespV3 *InPckt = (CigiPositionRespV3 *)Packet;

   printf("ObjectID ==> %d\n",InPckt->GetObjectID());
   printf("ArtPartID ==> %d\n",InPckt->GetArtPartID());
   printf("ObjectClass ==> %d\n",InPckt->GetObjectClass());
   printf("CoordSys ==> %d\n",InPckt->GetCoordSys());
   printf("LatOrXoff ==> %f\n",InPckt->GetLatOrXoff());
   printf("LonOrYoff ==> %f\n",InPckt->GetLonOrYoff());
   printf("AltOrZoff ==> %f\n",InPckt->GetAltOrZoff());
   printf("Roll ==> %f\n",InPckt->GetRoll());
   printf("Pitch ==> %f\n",InPckt->GetPitch());
   printf("Yaw ==> %f\n",InPckt->GetYaw());



}
