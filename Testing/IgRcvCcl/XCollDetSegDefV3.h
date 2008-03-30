// XCollDetSegDefV3.h: interface for the XCollDetSegDefV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCollDetSegDefV3_INCLUDED_)
#define _PROC_XCollDetSegDefV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetSegDefV3.h"

class XCollDetSegDefV3 : public CigiBaseEventProcessor
{
public:
   XCollDetSegDefV3();
   virtual ~XCollDetSegDefV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetSegDefV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetSegDefV3 *TPckt;

};

#endif // _PROC_XCollDetSegDefV3_INCLUDED_
