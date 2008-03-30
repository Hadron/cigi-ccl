// XShortCompCtrlV3.cpp: Body of the XShortCompCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XShortCompCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XShortCompCtrlV3::XShortCompCtrlV3()
{

}

XShortCompCtrlV3::~XShortCompCtrlV3()
{

}


void XShortCompCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiShortCompCtrlV3 *InPckt = (CigiShortCompCtrlV3 *)Packet;

   bool ok = true;

   printf("Short Component Control:\n");

   printf("\tComponent ID = %d\n",InPckt->GetCompID());
   printf("\tInstance ID = %d\n",InPckt->GetInstanceID());

   printf("\tComponent Class = %d : ",InPckt->GetCompClassV3());
   switch(InPckt->GetCompClassV3())
   {
   case 0:
      printf("EntityV3\n");
      break;
   case 1:
      printf("ViewV3\n");
      break;
   case 2:
      printf("ViewGrpV3\n");
      break;
   case 3:
      printf("SensorV3\n");
      break;
   case 4:
      printf("RegionalSeaSurfaceV3\n");
      break;
   case 5:
      printf("RegionalTerrainSurfaceV3\n");
      break;
   case 6:
      printf("RegionalLayeredWeatherV3\n");
      break;
   case 7:
      printf("GlobalSeaSurfaceV3\n");
      break;
   case 8:
      printf("GlobalTerrainSurfaceV3\n");
      break;
   case 9:
      printf("GlobalLayeredWeatherV3\n");
      break;
   case 10:
      printf("AtmosphereV3\n");
      break;
   case 11:
      printf("CelestialSphereV3\n");
      break;
   case 12:
      printf("EventV3\n");
      break;
   case 13:
      printf("SystemV3\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tComponent State = %d\n",InPckt->GetCompState());
   printf("\tComponent Data 0 = %d\n",InPckt->GetLongCompData(0));
   printf("\tComponent Data 1 = %d\n",InPckt->GetLongCompData(1));

}

