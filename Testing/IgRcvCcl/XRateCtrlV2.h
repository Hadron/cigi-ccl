// XRateCtrlV2.h: interface for the XRateCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XRateCtrlV2_INCLUDED_)
#define _PROC_XRateCtrlV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiRateCtrlV2.h"

class XRateCtrlV2 : public CigiBaseEventProcessor
{
public:
   XRateCtrlV2();
   virtual ~XRateCtrlV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiRateCtrlV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiRateCtrlV2 *TPckt;

};

#endif // _PROC_XRateCtrlV2_INCLUDED_
