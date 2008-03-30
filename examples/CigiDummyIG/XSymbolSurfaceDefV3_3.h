// XSymbolSurfaceDefV3_3.h: interface for the XSymbolSurfaceDefV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSymbolSurfaceDefV3_3_INCLUDED_)
#define _PROC_XSymbolSurfaceDefV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSymbolSurfaceDefV3_3.h"

class XSymbolSurfaceDefV3_3 : public CigiBaseEventProcessor
{
public:
   XSymbolSurfaceDefV3_3();
   virtual ~XSymbolSurfaceDefV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSymbolSurfaceDefV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSymbolSurfaceDefV3_3 *TPckt;

};

#endif // _PROC_XSymbolSurfaceDefV3_3_INCLUDED_
