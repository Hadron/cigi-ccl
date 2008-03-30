// XEventNotificationV3.cpp: Body of the XEventNotificationV3 class.
//
//////////////////////////////////////////////////////////////////////

#include "XEventNotificationV3.h"

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

   printf("===> EventNotification <===\n");

   printf("EventID ==> %d\n",InPckt->GetEventID());
   printf("EventData ==> %f\n",InPckt->GetLEventData(0));
   printf("EventData ==> %f\n",InPckt->GetLEventData(1));
   printf("EventData ==> %f\n",InPckt->GetLEventData(2));


}
