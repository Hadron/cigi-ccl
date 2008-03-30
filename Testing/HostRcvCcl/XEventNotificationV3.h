// XEventNotificationV3.h: Interface for the XEventNotificationV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEVENTNOTIFICATIONV3_INCLUDED_)
#define _PROC_XEVENTNOTIFICATIONV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEventNotificationV3.h"

class XEventNotificationV3 : public CigiBaseEventProcessor
{
public:
   XEventNotificationV3();
   virtual ~XEventNotificationV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEventNotificationV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEventNotificationV3 *TPckt;

};

#endif   //  _PROC_XEVENTNOTIFICATIONV3_INCLUDED_


