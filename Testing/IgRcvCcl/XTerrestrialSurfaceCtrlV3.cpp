// XTerrestrialSurfaceCtrlV3.cpp: Body of the XTerrestrialSurfaceCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XTerrestrialSurfaceCtrlV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XTerrestrialSurfaceCtrlV3::XTerrestrialSurfaceCtrlV3()
{

}

XTerrestrialSurfaceCtrlV3::~XTerrestrialSurfaceCtrlV3()
{

}


void XTerrestrialSurfaceCtrlV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiTerrestrialSurfaceCtrlV3 *InPckt = (CigiTerrestrialSurfaceCtrlV3 *)Packet;

   printf("Terrestrial Surface Control:\n");

   printf("\tEntity Region ID = %d\n",InPckt->GetEntityRgnID());
   printf("\tSurface Condition ID = %d\n",InPckt->GetSurfaceCondID());
   printf("\tSurface Condition Enable = %d\n",InPckt->GetSurfaceCondEn());

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

   printf("\tSeverity = %d\n",InPckt->GetSeverity());
   printf("\tCoverage = %d\n",InPckt->GetCoverage());


}
