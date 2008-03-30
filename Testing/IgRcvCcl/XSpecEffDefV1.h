// XSpecEffDefV1.h: interface for the XSpecEffDefV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSpecEffDefV1_INCLUDED_)
#define _PROC_XSpecEffDefV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSpecEffDefV1.h"

class XSpecEffDefV1 : public CigiBaseEventProcessor
{
public:
   XSpecEffDefV1();
   virtual ~XSpecEffDefV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSpecEffDefV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSpecEffDefV1 *TPckt;

};

#endif // _PROC_XSpecEffDefV1_INCLUDED_
