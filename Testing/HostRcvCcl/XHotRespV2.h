// XHotRespV2.h: Interface for the XHotRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHOTRESPV2_INCLUDED_)
#define _PROC_XHOTRESPV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHotRespV2.h"

class XHotRespV2 : public CigiBaseEventProcessor
{
public:
   XHotRespV2();
   virtual ~XHotRespV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHotRespV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHotRespV2 *TPckt;

};

#endif   //  _PROC_XHOTRESPV2_INCLUDED_


