// XLosSegReqV3_2.h: interface for the XLosSegReqV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosSegReqV3_2_INCLUDED_)
#define _PROC_XLosSegReqV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosSegReqV3_2.h"

class XLosSegReqV3_2 : public CigiBaseEventProcessor
{
public:
   XLosSegReqV3_2();
   virtual ~XLosSegReqV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosSegReqV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosSegReqV3_2 *TPckt;

};

#endif // _PROC_XLosSegReqV3_2_INCLUDED_
