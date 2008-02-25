// XAnimationStop.h: interface for the XAnimationStop class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XAnimationStop_INCLUDED_)
#define _PROC_XAnimationStop_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiAnimationStopV3.h"

class XAnimationStop : public CigiBaseEventProcessor
{
public:
   XAnimationStop();
   virtual ~XAnimationStop();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiAnimationStopV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiAnimationStopV3 *TPckt;

};

#endif // _PROC_XAnimationStop_INCLUDED_
