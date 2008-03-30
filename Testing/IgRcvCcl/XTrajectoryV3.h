// XTrajectoryV3.h: interface for the XTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XTrajectoryV3_INCLUDED_)
#define _PROC_XTrajectoryV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiTrajectoryDefV3.h"

class XTrajectoryV3 : public CigiBaseEventProcessor
{
public:
   XTrajectoryV3();
   virtual ~XTrajectoryV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiTrajectoryDefV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiTrajectoryDefV3 *TPckt;

};

#endif // _PROC_XTrajectoryV3_INCLUDED_
