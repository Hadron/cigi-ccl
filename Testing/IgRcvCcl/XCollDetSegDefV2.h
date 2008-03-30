// XCollDetSegDefV2.h: interface for the XCollDetSegDefV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCollDetSegDefV2_INCLUDED_)
#define _PROC_XCollDetSegDefV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetSegDefV2.h"

class XCollDetSegDefV2 : public CigiBaseEventProcessor
{
public:
   XCollDetSegDefV2();
   virtual ~XCollDetSegDefV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetSegDefV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetSegDefV2 *TPckt;

};

#endif // _PROC_XCollDetSegDefV2_INCLUDED_
