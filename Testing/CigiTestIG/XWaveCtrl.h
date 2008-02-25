// XWaveCtrl.h: interface for the XWaveCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XWaveCtrl_INCLUDED_)
#define _PROC_XWaveCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiWaveCtrlV3.h"

class XWaveCtrl : public CigiBaseEventProcessor
{
public:
   XWaveCtrl();
   virtual ~XWaveCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiWaveCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiWaveCtrlV3 *TPckt;

};

#endif // _PROC_XWaveCtrl_INCLUDED_
