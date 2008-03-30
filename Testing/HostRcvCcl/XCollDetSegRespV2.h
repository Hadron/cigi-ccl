// XCollDetSegRespV2.h: Interface for the XCollDetSegRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCOLLDETSEGRESPV2_INCLUDED_)
#define _PROC_XCOLLDETSEGRESPV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetSegRespV2.h"

class XCollDetSegRespV2 : public CigiBaseEventProcessor
{
public:
   XCollDetSegRespV2();
   virtual ~XCollDetSegRespV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetSegRespV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetSegRespV2 *TPckt;

};

#endif   //  _PROC_XCOLLDETSEGRESPV2_INCLUDED_


