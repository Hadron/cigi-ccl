// XPositionReqV3.h: interface for the XPostionReqV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XPostionReqV3_INCLUDED_)
#define _PROC_XPostionReqV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiPositionReqV3.h"

class XPositionReqV3 : public CigiBaseEventProcessor
{
public:
   XPositionReqV3();
   virtual ~XPositionReqV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiPositionReqV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiPositionReqV3 *TPckt;

};

#endif // _PROC_XPostionReqV3_INCLUDED_
