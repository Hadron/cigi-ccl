// XSensorCtrlV2.cpp: Body of the XSensorCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#include "XSensorCtrlV2.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSensorCtrlV2::XSensorCtrlV2()
{

}

XSensorCtrlV2::~XSensorCtrlV2()
{

}


void XSensorCtrlV2::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiSensorCtrlV2 *InPckt = (CigiSensorCtrlV2 *)Packet;

   bool ok = true;

   printf("Sensor Control:\n");

   printf("\tView ID = %d\n",InPckt->GetViewID());
   printf("\tSensor ID = %d\n",InPckt->GetSensorID());
   printf("\tSensor On = %d\n",InPckt->GetSensorOn());

   printf("\tPolarity = %d : ",InPckt->GetPolarity());
   switch(InPckt->GetPolarity())
   {
   case 0:
      printf("WhiteHot\n");
      break;
   case 1:
      printf("BlackHot\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tLine Drop Enable = %d\n",InPckt->GetLineDropEn());

   printf("\tTrack Mode = %d : ",InPckt->GetTrackMode());
   switch(InPckt->GetTrackMode())
   {
   case 0:
      printf("TrackOff\n");
      break;
   case 1:
      printf("ForceCorrelate\n");
      break;
   case 2:
      printf("Scene\n");
      break;
   case 3:
      printf("Target\n");
      break;
   case 4:
      printf("Ship\n");
      break;
   case 5:
      printf("TMDefA\n");
      break;
   case 6:
      printf("TMDefB\n");
      break;
   case 7:
      printf("TMDefC\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tAuto Gain Enable = %d\n",InPckt->GetAutoGainEn());

   printf("\tTrack Polarity = %d : ",InPckt->GetTrackPolarity());
   switch(InPckt->GetTrackPolarity())
   {
   case 0:
      printf("TrackWhite\n");
      break;
   case 1:
      printf("TrackBlack\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tGain = %f\n",InPckt->GetGain());
   printf("\tLevel = %f\n",InPckt->GetLevel());
   printf("\tAC Coupling = %f\n",InPckt->GetACCoupling());
   printf("\tNoise = %f\n",InPckt->GetNoise());


}
