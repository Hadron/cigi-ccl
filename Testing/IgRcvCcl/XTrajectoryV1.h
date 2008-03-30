// XTrajectoryV1.h: interface for the XTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XTrajectoryV1_INCLUDED_)
#define _PROC_XTrajectoryV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiTrajectoryDefV1.h"

class XTrajectoryV1 : public CigiBaseEventProcessor
{
public:
   XTrajectoryV1();
   virtual ~XTrajectoryV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiTrajectoryDefV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiTrajectoryDefV1 *TPckt;

};

#endif // _PROC_XTrajectoryV1_INCLUDED_
