// XCollDetVolDef.h: interface for the XCollDetVolDef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCollDetVolDef_INCLUDED_)
#define _PROC_XCollDetVolDef_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetVolDefV3.h"

class XCollDetVolDef : public CigiBaseEventProcessor
{
public:
   XCollDetVolDef();
   virtual ~XCollDetVolDef();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetVolDefV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetVolDefV3 *TPckt;

};

#endif // _PROC_XCollDetVolDef_INCLUDED_
