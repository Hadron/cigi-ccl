// XLosSegReqV2.h: interface for the XLosSegReqV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosSegReqV2_INCLUDED_)
#define _PROC_XLosSegReqV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosSegReqV2.h"

class XLosSegReqV2 : public CigiBaseEventProcessor
{
public:
   XLosSegReqV2();
   virtual ~XLosSegReqV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosSegReqV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosSegReqV2 *TPckt;

};

#endif // _PROC_XLosSegReqV2_INCLUDED_
