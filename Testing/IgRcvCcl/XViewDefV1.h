// XViewDefV1.h: interface for the XViewDef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XViewDefV1_INCLUDED_)
#define _PROC_XViewDefV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiViewDefV1.h"

class XViewDefV1 : public CigiBaseEventProcessor
{
public:
   XViewDefV1();
   virtual ~XViewDefV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiViewDefV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiViewDefV1 *TPckt;

};

#endif // _PROC_XViewDefV1_INCLUDED_
