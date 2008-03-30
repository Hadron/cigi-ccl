// XMaritimeSurfaceRespV3.h: Interface for the XMaritimeSurfaceRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XMARITIMESURFACERESPV3_INCLUDED_)
#define _PROC_XMARITIMESURFACERESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiMaritimeSurfaceRespV3.h"

class XMaritimeSurfaceRespV3 : public CigiBaseEventProcessor
{
public:
   XMaritimeSurfaceRespV3();
   virtual ~XMaritimeSurfaceRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiMaritimeSurfaceRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiMaritimeSurfaceRespV3 *TPckt;

};

#endif   //  _PROC_XMARITIMESURFACERESPV3_INCLUDED_


