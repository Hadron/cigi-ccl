// XShortSymbolCtrlV3_3.h: interface for the XShortSymbolCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XShortSymbolCtrlV3_3_INCLUDED_)
#define _PROC_XShortSymbolCtrlV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiShortSymbolCtrlV3_3.h"

class XShortSymbolCtrlV3_3 : public CigiBaseEventProcessor
{
public:
   XShortSymbolCtrlV3_3();
   virtual ~XShortSymbolCtrlV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiShortSymbolCtrlV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiShortSymbolCtrlV3_3 *TPckt;

};

#endif // _PROC_XShortSymbolCtrlV3_3_INCLUDED_
