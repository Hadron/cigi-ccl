// XCompCtrlV2.cpp: Body of the XCompCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCompCtrlV2.h"

#include "CigiExceptions.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCompCtrlV2::XCompCtrlV2()
{

}

XCompCtrlV2::~XCompCtrlV2()
{

}


void XCompCtrlV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCompCtrlV2 *InPckt = (CigiCompCtrlV2 *)Packet;

   bool ok = true;

   printf("Component Control:\n");

   printf("\tComp ID = %d\n",InPckt->GetCompID());
   printf("\tInstance ID = %d\n",InPckt->GetInstanceID());

   printf("\tComp Class = %d : ",InPckt->GetCompClassV2());
   switch(InPckt->GetCompClassV2())
   {
   case 0:
      printf("EntityV2\n");
      break;
   case 1:
      printf("EnvironmentV2\n");
      break;
   case 2:
      printf("ViewV2\n");
      break;
   case 3:
      printf("ViewGrpV2\n");
      break;
   case 4:
      printf("SensorV2\n");
      break;
   case 5:
      printf("SystemV2\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tComponent State = %d\n",InPckt->GetCompState());
   printf("\tComponent Data 0 = %d\n",InPckt->GetLongCompData(0));
   printf("\tComponent Data 1 = %d\n",InPckt->GetLongCompData(1));

}
