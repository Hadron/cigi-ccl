// XWaveCtrl.cpp: Body of the XWaveCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "XWaveCtrl.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XWaveCtrl::XWaveCtrl()
{

}

XWaveCtrl::~XWaveCtrl()
{

}


void XWaveCtrl::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiWaveCtrlV3 *InPckt = (CigiWaveCtrlV3 *)Packet;

   printf("===> WaveCtrl <===\n");

   printf("EntityRgnID ==> %d\n",InPckt->GetEntityRgnID());
   printf("WaveID ==> %d\n",InPckt->GetWaveID());
   printf("WaveEn ==> %d\n",InPckt->GetWaveEn());
   printf("Scope ==> %d\n",InPckt->GetScope());
   printf("Breaker ==> %d\n",InPckt->GetBreaker());
   printf("WaveHt ==> %f\n",InPckt->GetWaveHt());
   printf("WaveLen ==> %f\n",InPckt->GetWaveLen());
   printf("Period ==> %f\n",InPckt->GetPeriod());
   printf("Direction ==> %f\n",InPckt->GetDirection());
   printf("PhaseOff ==> %f\n",InPckt->GetPhaseOff());
   printf("Leading ==> %f\n",InPckt->GetLeading());


}
