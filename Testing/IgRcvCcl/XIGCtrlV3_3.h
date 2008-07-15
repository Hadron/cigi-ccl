// XIGCtrlV3_3.h: interface for the XIGCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XIGCtrlV3_3_INCLUDED_)
#define _PROC_XIGCtrlV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiIGCtrlV3_3.h"

class XIGCtrlV3_3 : public CigiBaseEventProcessor
{
public:
   XIGCtrlV3_3();
   virtual ~XIGCtrlV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiIGCtrlV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiIGCtrlV3_3 *TPckt;

};

#endif // _PROC_XIGCtrlV3_3_INCLUDED_
