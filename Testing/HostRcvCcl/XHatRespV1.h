// XHatRespV1.h: Interface for the XHatRespV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHATRESPV1_INCLUDED_)
#define _PROC_XHATRESPV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatRespV1.h"

class XHatRespV1 : public CigiBaseEventProcessor
{
public:
   XHatRespV1();
   virtual ~XHatRespV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatRespV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatRespV1 *TPckt;

};

#endif   //  _PROC_XHATRESPV1_INCLUDED_


