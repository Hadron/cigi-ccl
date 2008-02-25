// XCollDetVolResp.cpp: Body of the XCollDetVolResp class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XCollDetVolResp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCollDetVolResp::XCollDetVolResp()
{

}

XCollDetVolResp::~XCollDetVolResp()
{

}


void XCollDetVolResp::OnPacketReceived(CigiBasePacket *Packet)
{
CigiCollDetVolRespV3 *InPckt = (CigiCollDetVolRespV3 *)Packet;

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("VolID ==> %d\n",InPckt->GetVolID());
   printf("CollType ==> %d\n",InPckt->GetCollType());
   printf("CollEntityID ==> %d\n",InPckt->GetCollEntityID());
   printf("CollVolID ==> %d\n",InPckt->GetCollVolID());


}
