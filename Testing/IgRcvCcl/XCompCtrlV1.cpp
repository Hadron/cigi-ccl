// XCompCtrlV1.cpp: Body of the XCompCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCompCtrlV1.h"

#include "CigiExceptions.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCompCtrlV1::XCompCtrlV1()
{

}

XCompCtrlV1::~XCompCtrlV1()
{

}


void XCompCtrlV1::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCompCtrlV1 *InPckt = (CigiCompCtrlV1 *)Packet;

   bool ok = true;

   printf("Component Control:\n");

   printf("\tComp ID = %d\n",InPckt->GetCompID());
   printf("\tEntity ID = %d\n",InPckt->GetEntityID());
   printf("\tView ID = %d\n",InPckt->GetViewID());

   printf("\tComp Class = %d : ",InPckt->GetCompAssoc());
   switch(InPckt->GetCompAssoc())
   {
   case 0:
      printf("Entity\n");
      break;
   case 1:
      printf("Environment\n");
      break;
   case 2:
      printf("View\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tComponent State = %d\n",InPckt->GetCompState());
   printf("\tComponent Data 0 = %d\n",InPckt->GetLongCompData(0));
   printf("\tComponent Data 1 = %d\n",InPckt->GetLongCompData(1));

}
