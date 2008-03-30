// XRateCtrl.h: interface for the XRateCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XRateCtrl_INCLUDED_)
#define _PROC_XRateCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiRateCtrlV3_2.h"

class XRateCtrl : public CigiBaseEventProcessor
{
public:
   XRateCtrl();
   virtual ~XRateCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiRateCtrlV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiRateCtrlV3_2 *TPckt;

};

#endif // _PROC_XRateCtrl_INCLUDED_
