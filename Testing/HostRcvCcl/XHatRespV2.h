// XHatRespV2.h: Interface for the XHatRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHATRESPV2_INCLUDED_)
#define _PROC_XHATRESPV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatRespV2.h"

class XHatRespV2 : public CigiBaseEventProcessor
{
public:
   XHatRespV2();
   virtual ~XHatRespV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatRespV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatRespV2 *TPckt;

};

#endif   //  _PROC_XHATRESPV2_INCLUDED_


