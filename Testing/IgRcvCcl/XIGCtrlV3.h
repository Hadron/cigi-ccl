// XIGCtrlV3.h: interface for the XIGCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XIGCtrlV3_INCLUDED_)
#define _PROC_XIGCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiIGCtrlV3.h"

class XIGCtrlV3 : public CigiBaseEventProcessor
{
public:
   XIGCtrlV3();
   virtual ~XIGCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiIGCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiIGCtrlV3 *TPckt;

};

#endif // _PROC_XIGCtrlV3_INCLUDED_
