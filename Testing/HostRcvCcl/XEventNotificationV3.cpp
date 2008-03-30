// XEventNotificationV3.cpp: Body of the XEventNotificationV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEventNotificationV3.h"
#include <CigiEventNotificationV3.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEventNotificationV3::XEventNotificationV3()
{

}

XEventNotificationV3::~XEventNotificationV3()
{

}


void XEventNotificationV3::OnPacketReceived(CigiBasePacket *Packet)
{
   CigiEventNotificationV3 *InPckt = (CigiEventNotificationV3 *)Packet;


   printf("Event Notification V3:\n");
   printf("\tEventID = %u\n",InPckt->GetEventID());
   printf("\tEventData 1 = %u\n",InPckt->GetULEventData(0));
   printf("\tEventData 2 = %u\n",InPckt->GetULEventData(1));
   printf("\tEventData 3 = %u\n",InPckt->GetULEventData(2));

}


