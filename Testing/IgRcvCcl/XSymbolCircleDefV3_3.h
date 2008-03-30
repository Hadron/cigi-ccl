// XSymbolCircleDefV3_3.h: interface for the XSymbolCircleDefV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSymbolCircleDefV3_3_INCLUDED_)
#define _PROC_XSymbolCircleDefV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSymbolCircleDefV3_3.h"

class XSymbolCircleDefV3_3 : public CigiBaseEventProcessor
{
public:
   XSymbolCircleDefV3_3();
   virtual ~XSymbolCircleDefV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSymbolCircleDefV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSymbolCircleDefV3_3 *TPckt;

};

#endif // _PROC_XSymbolCircleDefV3_3_INCLUDED_
