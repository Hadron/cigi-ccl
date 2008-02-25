// XMaritimeSurfaceResp.h: interface for the XMaritimeSurfaceResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XMaritimeSurfaceResp_INCLUDED_)
#define _PROC_XMaritimeSurfaceResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiMaritimeSurfaceRespV3.h"

class XMaritimeSurfaceResp : public CigiBaseEventProcessor
{
public:
   XMaritimeSurfaceResp();
   virtual ~XMaritimeSurfaceResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiMaritimeSurfaceRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiMaritimeSurfaceRespV3 *TPckt;

};

#endif // _PROC_XMaritimeSurfaceResp_INCLUDED_
