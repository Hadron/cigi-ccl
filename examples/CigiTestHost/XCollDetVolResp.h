// XCollDetVolResp.h: interface for the XCollDetVolResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCollDetVolResp_INCLUDED_)
#define _PROC_XCollDetVolResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetVolRespV3.h"

class XCollDetVolResp : public CigiBaseEventProcessor
{
public:
   XCollDetVolResp();
   virtual ~XCollDetVolResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetVolRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetVolRespV3 *TPckt;

};

#endif // _PROC_XCollDetVolResp_INCLUDED_
