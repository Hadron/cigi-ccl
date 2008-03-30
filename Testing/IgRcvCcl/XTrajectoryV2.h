// XTrajectoryV2.h: interface for the XTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XTrajectoryV2_INCLUDED_)
#define _PROC_XTrajectoryV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiTrajectoryDefV2.h"

class XTrajectoryV2 : public CigiBaseEventProcessor
{
public:
   XTrajectoryV2();
   virtual ~XTrajectoryV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiTrajectoryDefV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiTrajectoryDefV2 *TPckt;

};

#endif // _PROC_XTrajectoryV2_INCLUDED_
