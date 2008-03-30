// XIGCtrlV2.h: interface for the XIGCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XIGCtrlV2_INCLUDED_)
#define _PROC_XIGCtrlV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiIGCtrlV2.h"

class XIGCtrlV2 : public CigiBaseEventProcessor
{
public:
   XIGCtrlV2();
   virtual ~XIGCtrlV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiIGCtrlV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiIGCtrlV2 *TPckt;

};

#endif // _PROC_XIGCtrlV2_INCLUDED_
