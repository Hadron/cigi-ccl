// XAerosolResp.h: interface for the XAerosolResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XAerosolResp_INCLUDED_)
#define _PROC_XAerosolResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiAerosolRespV3.h"

class XAerosolResp : public CigiBaseEventProcessor
{
public:
   XAerosolResp();
   virtual ~XAerosolResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiAerosolRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiAerosolRespV3 *TPckt;

};

#endif // _PROC_XAerosolResp_INCLUDED_
