// XWaveCtrlV3.cpp: Body of the XWaveCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XWaveCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XWaveCtrlV3::XWaveCtrlV3()
{

}

XWaveCtrlV3::~XWaveCtrlV3()
{

}


void XWaveCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiWaveCtrlV3 *InPckt = (CigiWaveCtrlV3 *)Packet;

   printf("Wave Control:\n");

   printf("\tEntity Region ID = %d\n",InPckt->GetEntityRgnID());
   printf("\tWave ID = %d\n",InPckt->GetWaveID());
   printf("\tWave Enable = %d\n",InPckt->GetWaveEn());

   printf("\tScope = %d : ",InPckt->GetScope());
   switch(InPckt->GetScope())
   {
   case 0:
      printf("Global\n");
      break;
   case 1:
      printf("Regional\n");
      break;
   case 2:
      printf("Entity\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tBreaker = %d : ",InPckt->GetBreaker());
   switch(InPckt->GetBreaker())
   {
   case 0:
      printf("Plunging\n");
      break;
   case 1:
      printf("Spilling\n");
      break;
   case 2:
      printf("Surging\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tWave Height = %f\n",InPckt->GetWaveHt());
   printf("\tWavelength = %f\n",InPckt->GetWaveLen());
   printf("\tPeriod = %f\n",InPckt->GetPeriod());
   printf("\tDirection = %f\n",InPckt->GetDirection());
   printf("\tPhase Offset = %f\n",InPckt->GetPhaseOff());
   printf("\tLeading = %f\n",InPckt->GetLeading());


}
