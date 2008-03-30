// XIGMsgV2.h: Interface for the XIGMsgV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XIGMSGV2_INCLUDED_)
#define _PROC_XIGMSGV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiIGMsgV2.h"

class XIGMsgV2 : public CigiBaseEventProcessor
{
public:
   XIGMsgV2();
   virtual ~XIGMsgV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiIGMsgV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiIGMsgV2 *TPckt;

};

#endif   //  _PROC_XIGMSGV2_INCLUDED_


