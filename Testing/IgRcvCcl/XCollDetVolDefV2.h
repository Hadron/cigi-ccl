// XCollDetVolDefV2.h: interface for the XCollDetVolDefV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCollDetVolDefV2_INCLUDED_)
#define _PROC_XCollDetVolDefV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetVolDefV2.h"

class XCollDetVolDefV2 : public CigiBaseEventProcessor
{
public:
   XCollDetVolDefV2();
   virtual ~XCollDetVolDefV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetVolDefV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetVolDefV2 *TPckt;

};

#endif // _PROC_XCollDetVolDefV2_INCLUDED_
