// XShortArtPartCtrl.cpp: Body of the XShortArtPartCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XShortArtPartCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XShortArtPartCtrl::XShortArtPartCtrl()
{

}

XShortArtPartCtrl::~XShortArtPartCtrl()
{

}


void XShortArtPartCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiShortArtPartCtrlV3 *InPckt = (CigiShortArtPartCtrlV3 *)Packet;

   printf("===> ShortArtPartCtrl <===\n");

   printf("EntityID ==> %d\n",InPckt->GetEntityID());
   printf("ArtPart1 ==> %d\n",InPckt->GetArtPart1());
   printf("ArtPart2 ==> %d\n",InPckt->GetArtPart2());
   printf("DofSelect1 ==> %d\n",InPckt->GetDofSelect1());
   printf("DofSelect2 ==> %d\n",InPckt->GetDofSelect2());
   printf("ArtPart1En ==> %d\n",InPckt->GetArtPart1En());
   printf("ArtPart2En ==> %d\n",InPckt->GetArtPart2En());
   printf("Dof1 ==> %f\n",InPckt->GetDof1());
   printf("Dof2 ==> %f\n",InPckt->GetDof2());


}
