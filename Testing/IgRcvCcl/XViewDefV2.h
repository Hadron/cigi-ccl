// XViewDefV2.h: interface for the XViewDef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XViewDefV2_INCLUDED_)
#define _PROC_XViewDefV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiViewDefV2.h"

class XViewDefV2 : public CigiBaseEventProcessor
{
public:
   XViewDefV2();
   virtual ~XViewDefV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiViewDefV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiViewDefV2 *TPckt;

};

#endif // _PROC_XViewDefV2_INCLUDED_
