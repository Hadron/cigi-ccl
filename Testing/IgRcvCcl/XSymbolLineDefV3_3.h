// XSymbolLineDefV3_3.h: interface for the XSymbolLineDefV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSymbolLineDefV3_3_INCLUDED_)
#define _PROC_XSymbolLineDefV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSymbolLineDefV3_3.h"

class XSymbolLineDefV3_3 : public CigiBaseEventProcessor
{
public:
   XSymbolLineDefV3_3();
   virtual ~XSymbolLineDefV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSymbolLineDefV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSymbolLineDefV3_3 *TPckt;

};

#endif // _PROC_XSymbolLineDefV3_3_INCLUDED_
