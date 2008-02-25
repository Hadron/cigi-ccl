// XIGMsg.h: interface for the XIGMsg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XIGMsg_INCLUDED_)
#define _PROC_XIGMsg_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiIGMsgV3.h"

class XIGMsg : public CigiBaseEventProcessor
{
public:
   XIGMsg();
   virtual ~XIGMsg();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiIGMsgV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiIGMsgV3 *TPckt;

};

#endif // _PROC_XIGMsg_INCLUDED_
