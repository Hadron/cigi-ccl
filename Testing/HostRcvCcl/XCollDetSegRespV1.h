// XCollDetSegRespV1.h: Interface for the XCollDetSegRespV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCOLLDETSEGRESPV1_INCLUDED_)
#define _PROC_XCOLLDETSEGRESPV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetSegRespV1.h"

class XCollDetSegRespV1 : public CigiBaseEventProcessor
{
public:
   XCollDetSegRespV1();
   virtual ~XCollDetSegRespV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetSegRespV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetSegRespV1 *TPckt;

};

#endif   //  _PROC_XCOLLDETSEGRESPV1_INCLUDED_


