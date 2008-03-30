// XMotionTrackCtrlV3.h: interface for the XMotionTrackCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XMotionTrackCtrlV3_INCLUDED_)
#define _PROC_XMotionTrackCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiMotionTrackCtrlV3.h"

class XMotionTrackCtrlV3 : public CigiBaseEventProcessor
{
public:
   XMotionTrackCtrlV3();
   virtual ~XMotionTrackCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiMotionTrackCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiMotionTrackCtrlV3 *TPckt;

};

#endif // _PROC_XMotionTrackCtrlV3_INCLUDED_
