// XLosVectReqV1.h: interface for the XLosVectReqV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosVectReqV1_INCLUDED_)
#define _PROC_XLosVectReqV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosVectReqV1.h"

class XLosVectReqV1 : public CigiBaseEventProcessor
{
public:
   XLosVectReqV1();
   virtual ~XLosVectReqV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosVectReqV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosVectReqV1 *TPckt;

};

#endif // _PROC_XLosVectReqV1_INCLUDED_
