// XTerrestrialSurfaceCtrlV3.h: interface for the XTerrestrialSurfaceCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XTerrestrialSurfaceCtrlV3_INCLUDED_)
#define _PROC_XTerrestrialSurfaceCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiTerrestrialSurfaceCtrlV3.h"

class XTerrestrialSurfaceCtrlV3 : public CigiBaseEventProcessor
{
public:
   XTerrestrialSurfaceCtrlV3();
   virtual ~XTerrestrialSurfaceCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiTerrestrialSurfaceCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiTerrestrialSurfaceCtrlV3 *TPckt;

};

#endif // _PROC_XTerrestrialSurfaceCtrlV3_INCLUDED_
