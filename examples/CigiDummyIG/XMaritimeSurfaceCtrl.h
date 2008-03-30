// XMaritimeSurfaceCtrl.h: interface for the XMaritimeSurfaceCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XMaritimeSurfaceCtrl_INCLUDED_)
#define _PROC_XMaritimeSurfaceCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiMaritimeSurfaceCtrlV3.h"

class XMaritimeSurfaceCtrl : public CigiBaseEventProcessor
{
public:
   XMaritimeSurfaceCtrl();
   virtual ~XMaritimeSurfaceCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiMaritimeSurfaceCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiMaritimeSurfaceCtrlV3 *TPckt;

};

#endif // _PROC_XMaritimeSurfaceCtrl_INCLUDED_
