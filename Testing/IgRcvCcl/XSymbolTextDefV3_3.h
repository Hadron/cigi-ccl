// XSymbolTextDefV3_3.h: interface for the XSymbolTextDefV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSymbolTextDefV3_3_INCLUDED_)
#define _PROC_XSymbolTextDefV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSymbolTextDefV3_3.h"

class XSymbolTextDefV3_3 : public CigiBaseEventProcessor
{
public:
   XSymbolTextDefV3_3();
   virtual ~XSymbolTextDefV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSymbolTextDefV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSymbolTextDefV3_3 *TPckt;

};

#endif // _PROC_XSymbolTextDefV3_3_INCLUDED_
