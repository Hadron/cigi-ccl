// XEventNotification.cpp: Body of the XEventNotification class.
//
//////////////////////////////////////////////////////////////////////

#include "XEventNotification.h"

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XEventNotification::XEventNotification()
{

}

XEventNotification::~XEventNotification()
{

}


void XEventNotification::OnPacketReceived(CigiBasePacket *Packet)
{
CigiEventNotificationV3 *InPckt = (CigiEventNotificationV3 *)Packet;

   printf("===> EventNotification <===\n");

   printf("EventID ==> %d\n",InPckt->GetEventID());
   printf("EventData ==> %f\n",InPckt->GetLEventData(0));
   printf("EventData ==> %f\n",InPckt->GetLEventData(1));
   printf("EventData ==> %f\n",InPckt->GetLEventData(2));


}
