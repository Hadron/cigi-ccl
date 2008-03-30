// XLosVectReqV3_2.h: interface for the XLosVectReqV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosVectReqV3_2_INCLUDED_)
#define _PROC_XLosVectReqV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosVectReqV3_2.h"

class XLosVectReqV3_2 : public CigiBaseEventProcessor
{
public:
   XLosVectReqV3_2();
   virtual ~XLosVectReqV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosVectReqV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosVectReqV3_2 *TPckt;

};

#endif // _PROC_XLosVectReqV3_2_INCLUDED_
