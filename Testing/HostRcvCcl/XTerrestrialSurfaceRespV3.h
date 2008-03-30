// XTerrestrialSurfaceRespV3.h: Interface for the XTerrestrialSurfaceRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XTERRESTRIALSURFACERESPV3_INCLUDED_)
#define _PROC_XTERRESTRIALSURFACERESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiTerrestrialSurfaceRespV3.h"

class XTerrestrialSurfaceRespV3 : public CigiBaseEventProcessor
{
public:
   XTerrestrialSurfaceRespV3();
   virtual ~XTerrestrialSurfaceRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiTerrestrialSurfaceRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiTerrestrialSurfaceRespV3 *TPckt;

};

#endif   //  _PROC_XTERRESTRIALSURFACERESPV3_INCLUDED_


