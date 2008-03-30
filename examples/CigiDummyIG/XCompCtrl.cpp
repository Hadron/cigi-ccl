// XCompCtrl.cpp: Body of the XCompCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XCompCtrl.h"

#include "CigiExceptions.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCompCtrl::XCompCtrl()
{

}

XCompCtrl::~XCompCtrl()
{

}


void XCompCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCompCtrlV3 *InPckt = (CigiCompCtrlV3 *)Packet;

   bool ok = true;

   printf("===> CompCtrl <===\n");

   printf("CompID ==> %d\n",InPckt->GetCompID());
   printf("InstanceID ==> %d\n",InPckt->GetInstanceID());
   printf("CompClassV3 ==> %d\n",InPckt->GetCompClassV3());
   printf("CompState ==> %d\n",InPckt->GetCompState());
   printf("CompData ==> %d\n",InPckt->GetLongCompData(0));
   printf("CompData ==> %d\n",InPckt->GetLongCompData(1));
   printf("CompData ==> %d\n",InPckt->GetLongCompData(2));
   printf("CompData ==> %d\n",InPckt->GetLongCompData(3));
   printf("CompData ==> %d\n",InPckt->GetLongCompData(4));
   printf("CompData ==> %d\n",InPckt->GetLongCompData(5));


}
