// XSpecEffDefV2.h: interface for the XSpecEffDefV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSpecEffDefV2_INCLUDED_)
#define _PROC_XSpecEffDefV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSpecEffDefV2.h"

class XSpecEffDefV2 : public CigiBaseEventProcessor
{
public:
   XSpecEffDefV2();
   virtual ~XSpecEffDefV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSpecEffDefV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSpecEffDefV2 *TPckt;

};

#endif // _PROC_XSpecEffDefV2_INCLUDED_
