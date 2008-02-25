// XCollDetSegResp.h: interface for the XCollDetSegResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCollDetSegResp_INCLUDED_)
#define _PROC_XCollDetSegResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetSegRespV3.h"

class XCollDetSegResp : public CigiBaseEventProcessor
{
public:
   XCollDetSegResp();
   virtual ~XCollDetSegResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetSegRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetSegRespV3 *TPckt;

};

#endif // _PROC_XCollDetSegResp_INCLUDED_
