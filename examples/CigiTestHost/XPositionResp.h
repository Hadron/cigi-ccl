// XPositionResp.h: interface for the XPositionResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XPositionResp_INCLUDED_)
#define _PROC_XPositionResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiPositionRespV3.h"

class XPositionResp : public CigiBaseEventProcessor
{
public:
   XPositionResp();
   virtual ~XPositionResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiPositionRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiPositionRespV3 *TPckt;

};

#endif // _PROC_XPositionResp_INCLUDED_
