// XViewDefV3.h: interface for the XViewDef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XViewDefV3_INCLUDED_)
#define _PROC_XViewDefV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiViewDefV3.h"

class XViewDefV3 : public CigiBaseEventProcessor
{
public:
   XViewDefV3();
   virtual ~XViewDefV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiViewDefV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiViewDefV3 *TPckt;

};

#endif // _PROC_XViewDefV3_INCLUDED_
