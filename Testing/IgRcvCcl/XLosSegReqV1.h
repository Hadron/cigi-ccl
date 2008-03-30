// XLosSegReqV1.h: interface for the XLosSegReqV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosSegReqV1_INCLUDED_)
#define _PROC_XLosSegReqV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosSegReqV1.h"

class XLosSegReqV1 : public CigiBaseEventProcessor
{
public:
   XLosSegReqV1();
   virtual ~XLosSegReqV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosSegReqV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosSegReqV1 *TPckt;

};

#endif // _PROC_XLosSegReqV1_INCLUDED_
