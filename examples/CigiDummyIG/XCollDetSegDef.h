// XCollDetSegDef.h: interface for the XCollDetSegDef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCollDetSegDef_INCLUDED_)
#define _PROC_XCollDetSegDef_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetSegDefV3.h"

class XCollDetSegDef : public CigiBaseEventProcessor
{
public:
   XCollDetSegDef();
   virtual ~XCollDetSegDef();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetSegDefV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetSegDefV3 *TPckt;

};

#endif // _PROC_XCollDetSegDef_INCLUDED_
