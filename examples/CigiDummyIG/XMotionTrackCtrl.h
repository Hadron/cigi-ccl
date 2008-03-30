// XMotionTrackCtrl.h: interface for the XMotionTrackCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XMotionTrackCtrl_INCLUDED_)
#define _PROC_XMotionTrackCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiMotionTrackCtrlV3.h"

class XMotionTrackCtrl : public CigiBaseEventProcessor
{
public:
   XMotionTrackCtrl();
   virtual ~XMotionTrackCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiMotionTrackCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiMotionTrackCtrlV3 *TPckt;

};

#endif // _PROC_XMotionTrackCtrl_INCLUDED_
