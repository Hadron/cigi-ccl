// XSymbolCloneV3_3.h: interface for the XSymbolCloneV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSymbolCloneV3_3_INCLUDED_)
#define _PROC_XSymbolCloneV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSymbolCloneV3_3.h"

class XSymbolCloneV3_3 : public CigiBaseEventProcessor
{
public:
   XSymbolCloneV3_3();
   virtual ~XSymbolCloneV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSymbolCloneV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSymbolCloneV3_3 *TPckt;

};

#endif // _PROC_XSymbolCloneV3_3_INCLUDED_
