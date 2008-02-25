// XHatHotReq.h: interface for the XHatHotReq class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHatHotReq_INCLUDED_)
#define _PROC_XHatHotReq_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatHotReqV3_2.h"

class XHatHotReq : public CigiBaseEventProcessor
{
public:
   XHatHotReq();
   virtual ~XHatHotReq();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatHotReqV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatHotReqV3_2 *TPckt;

};

#endif // _PROC_XHatHotReq_INCLUDED_
