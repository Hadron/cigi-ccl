// XSymbolCtrlV3_3.h: interface for the XSymbolCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSymbolCtrlV3_3_INCLUDED_)
#define _PROC_XSymbolCtrlV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSymbolCtrlV3_3.h"

class XSymbolCtrlV3_3 : public CigiBaseEventProcessor
{
public:
   XSymbolCtrlV3_3();
   virtual ~XSymbolCtrlV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSymbolCtrlV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSymbolCtrlV3_3 *TPckt;

};

#endif // _PROC_XSymbolCtrlV3_3_INCLUDED_
