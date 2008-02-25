// XHatHotResp.h: interface for the XHatHotResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHatHotResp_INCLUDED_)
#define _PROC_XHatHotResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatHotRespV3_2.h"

class XHatHotResp : public CigiBaseEventProcessor
{
public:
   XHatHotResp();
   virtual ~XHatHotResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatHotRespV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatHotRespV3_2 *TPckt;

};

#endif // _PROC_XHatHotResp_INCLUDED_
