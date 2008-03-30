// XTrajectory.h: interface for the XTrajectory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XTrajectory_INCLUDED_)
#define _PROC_XTrajectory_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiTrajectoryDefV3.h"

class XTrajectory : public CigiBaseEventProcessor
{
public:
   XTrajectory();
   virtual ~XTrajectory();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiTrajectoryDefV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiTrajectoryDefV3 *TPckt;

};

#endif // _PROC_XTrajectory_INCLUDED_
