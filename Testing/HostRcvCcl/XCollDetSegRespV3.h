// XCollDetSegRespV3.h: Interface for the XCollDetSegRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCOLLDETSEGRESPV3_INCLUDED_)
#define _PROC_XCOLLDETSEGRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetSegRespV3.h"

class XCollDetSegRespV3 : public CigiBaseEventProcessor
{
public:
   XCollDetSegRespV3();
   virtual ~XCollDetSegRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetSegRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetSegRespV3 *TPckt;

};

#endif   //  _PROC_XCOLLDETSEGRESPV3_INCLUDED_


