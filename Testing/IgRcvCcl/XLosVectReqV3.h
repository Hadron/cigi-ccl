// XLosVectReqV3.h: interface for the XLosVectReqV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosVectReqV3_INCLUDED_)
#define _PROC_XLosVectReqV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosVectReqV3.h"

class XLosVectReqV3 : public CigiBaseEventProcessor
{
public:
   XLosVectReqV3();
   virtual ~XLosVectReqV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosVectReqV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosVectReqV3 *TPckt;

};

#endif // _PROC_XLosVectReqV3_INCLUDED_
