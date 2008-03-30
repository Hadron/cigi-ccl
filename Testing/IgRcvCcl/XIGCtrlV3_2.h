// XIGCtrlV3_2.h: interface for the XIGCtrlV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XIGCtrlV3_2_INCLUDED_)
#define _PROC_XIGCtrlV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiIGCtrlV3_2.h"

class XIGCtrlV3_2 : public CigiBaseEventProcessor
{
public:
   XIGCtrlV3_2();
   virtual ~XIGCtrlV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiIGCtrlV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiIGCtrlV3_2 *TPckt;

};

#endif // _PROC_XIGCtrlV3_2_INCLUDED_
