// XIGCtrlV1.h: interface for the XIGCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XIGCtrlV1_INCLUDED_)
#define _PROC_XIGCtrlV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiIGCtrlV1.h"

class XIGCtrlV1 : public CigiBaseEventProcessor
{
public:
   XIGCtrlV1();
   virtual ~XIGCtrlV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiIGCtrlV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiIGCtrlV1 *TPckt;

};

#endif // _PROC_XIGCtrlV1_INCLUDED_
