// XLosVectReqV2.h: interface for the XLosVectReqV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosVectReqV2_INCLUDED_)
#define _PROC_XLosVectReqV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosVectReqV2.h"

class XLosVectReqV2 : public CigiBaseEventProcessor
{
public:
   XLosVectReqV2();
   virtual ~XLosVectReqV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosVectReqV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosVectReqV2 *TPckt;

};

#endif // _PROC_XLosVectReqV2_INCLUDED_
