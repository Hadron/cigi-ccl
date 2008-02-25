// XEventNotification.cpp: Body of the XEventNotification class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XEventNotification.h"

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

   printf("EventID ==> %d\n",InPckt->GetEventID());
   printf("EventData ==> %d\n",InPckt->GetLEventData(0));
   printf("EventData ==> %d\n",InPckt->GetLEventData(1));
   printf("EventData ==> %d\n",InPckt->GetLEventData(2));


}
