// XCollDetSegDefV1.h: interface for the XCollDetSegDefV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCollDetSegDefV1_INCLUDED_)
#define _PROC_XCollDetSegDefV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetSegDefV1.h"

class XCollDetSegDefV1 : public CigiBaseEventProcessor
{
public:
   XCollDetSegDefV1();
   virtual ~XCollDetSegDefV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetSegDefV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetSegDefV1 *TPckt;

};

#endif // _PROC_XCollDetSegDefV1_INCLUDED_
