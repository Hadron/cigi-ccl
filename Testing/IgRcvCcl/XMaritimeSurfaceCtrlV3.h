// XMaritimeSurfaceCtrlV3.h: interface for the XMaritimeSurfaceCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XMaritimeSurfaceCtrlV3_INCLUDED_)
#define _PROC_XMaritimeSurfaceCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiMaritimeSurfaceCtrlV3.h"

class XMaritimeSurfaceCtrlV3 : public CigiBaseEventProcessor
{
public:
   XMaritimeSurfaceCtrlV3();
   virtual ~XMaritimeSurfaceCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiMaritimeSurfaceCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiMaritimeSurfaceCtrlV3 *TPckt;

};

#endif // _PROC_XMaritimeSurfaceCtrlV3_INCLUDED_
