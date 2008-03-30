// XHotReqV2.h: interface for the XHotReqV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHotReqV2_INCLUDED_)
#define _PROC_XHotReqV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHotReqV2.h"

class XHotReqV2 : public CigiBaseEventProcessor
{
public:
   XHotReqV2();
   virtual ~XHotReqV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHotReqV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHotReqV2 *TPckt;

};

#endif // _PROC_XHotReqV2_INCLUDED_
