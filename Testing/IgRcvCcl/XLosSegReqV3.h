// XLosSegReqV3.h: interface for the XLosSegReqV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosSegReqV3_INCLUDED_)
#define _PROC_XLosSegReqV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosSegReqV3.h"

class XLosSegReqV3 : public CigiBaseEventProcessor
{
public:
   XLosSegReqV3();
   virtual ~XLosSegReqV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosSegReqV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosSegReqV3 *TPckt;

};

#endif // _PROC_XLosSegReqV3_INCLUDED_
