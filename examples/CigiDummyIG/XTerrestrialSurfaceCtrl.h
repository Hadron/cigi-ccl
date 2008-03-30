// XTerrestrialSurfaceCtrl.h: interface for the XTerrestrialSurfaceCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XTerrestrialSurfaceCtrl_INCLUDED_)
#define _PROC_XTerrestrialSurfaceCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiTerrestrialSurfaceCtrlV3.h"

class XTerrestrialSurfaceCtrl : public CigiBaseEventProcessor
{
public:
   XTerrestrialSurfaceCtrl();
   virtual ~XTerrestrialSurfaceCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiTerrestrialSurfaceCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiTerrestrialSurfaceCtrlV3 *TPckt;

};

#endif // _PROC_XTerrestrialSurfaceCtrl_INCLUDED_
