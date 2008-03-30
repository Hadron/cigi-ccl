// XIGMsgV3.h: Interface for the XIGMsgV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XIGMSGV3_INCLUDED_)
#define _PROC_XIGMSGV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiIGMsgV3.h"

class XIGMsgV3 : public CigiBaseEventProcessor
{
public:
   XIGMsgV3();
   virtual ~XIGMsgV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiIGMsgV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiIGMsgV3 *TPckt;

};

#endif   //  _PROC_XIGMSGV3_INCLUDED_


