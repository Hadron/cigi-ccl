// XEnvCondReqV3.cpp: Body of the XEnvCondReqV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEnvCondReqV3.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEnvCondReqV3::XEnvCondReqV3()
{

}

XEnvCondReqV3::~XEnvCondReqV3()
{

}


void XEnvCondReqV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEnvCondReqV3 *InPckt = (CigiEnvCondReqV3 *)Packet;

   bool ok = true;

   printf("Environmental Condition Request:\n");

   if((InPckt->GetReqType() & (unsigned char)CigiBaseEnvCondReq::Maritime) != 0)
      printf("\tRequest Type = 1 : Maritime\n");

   if((InPckt->GetReqType() & (unsigned char)CigiBaseEnvCondReq::Terrestrial) != 0)
      printf("\tRequest Type = 2 : Terrestrial\n");

   if((InPckt->GetReqType() & (unsigned char)CigiBaseEnvCondReq::Weather) != 0)
      printf("\tRequest Type = 4 : Weather\n");

   if((InPckt->GetReqType() & (unsigned char)CigiBaseEnvCondReq::Aerosol) != 0)
      printf("\tRequest Type = 8 : Aerosol\n");

   printf("\tRequest ID = %d\n",InPckt->GetReqID());

   printf("\tLatitude = %f\n",InPckt->GetLat());
   printf("\tLongitude = %f\n",InPckt->GetLon());
   printf("\tAltitude = %f\n",InPckt->GetAlt());


}
