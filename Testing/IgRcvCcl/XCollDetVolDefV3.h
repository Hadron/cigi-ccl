// XCollDetVolDefV3.h: interface for the XCollDetVolDefV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCollDetVolDefV3_INCLUDED_)
#define _PROC_XCollDetVolDefV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetVolDefV3.h"

class XCollDetVolDefV3 : public CigiBaseEventProcessor
{
public:
   XCollDetVolDefV3();
   virtual ~XCollDetVolDefV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetVolDefV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetVolDefV3 *TPckt;

};

#endif // _PROC_XCollDetVolDefV3_INCLUDED_
