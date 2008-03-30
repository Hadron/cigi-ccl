// XCompCtrlV3_3.cpp: Body of the XCompCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XCompCtrlV3_3.h"

#include "CigiExceptions.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCompCtrlV3_3::XCompCtrlV3_3()
{

}

XCompCtrlV3_3::~XCompCtrlV3_3()
{

}


void XCompCtrlV3_3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiCompCtrlV3_3 *InPckt = (CigiCompCtrlV3_3 *)Packet;

   bool ok = true;

   printf("Component Control:\n");

   printf("\tComp ID = %d\n",InPckt->GetCompID());
   printf("\tInstance ID = %d\n",InPckt->GetInstanceID());

   printf("\tComp Class = %d : ",InPckt->GetCompClassV3());
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
   case 14:
      printf("SymbolSurfaceV3_3\n");
      break;
   case 15:
      printf("SymbolV3_3\n");
      break;
   default:
      printf("\n");
      break;
   }

   printf("\tComponent State = %d\n",InPckt->GetCompState());
   printf("\tComponent Data 0 = %d\n",InPckt->GetLongCompData(0));
   printf("\tComponent Data 1 = %d\n",InPckt->GetLongCompData(1));
   printf("\tComponent Data 2 = %d\n",InPckt->GetLongCompData(2));
   printf("\tComponent Data 3 = %d\n",InPckt->GetLongCompData(3));
   printf("\tComponent Data 4 = %d\n",InPckt->GetLongCompData(4));
   printf("\tComponent Data 5 = %d\n",InPckt->GetLongCompData(5));

}
