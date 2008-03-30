// XRateCtrlV3_2.h: interface for the XRateCtrlV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XRateCtrlV3_2_INCLUDED_)
#define _PROC_XRateCtrlV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiRateCtrlV3_2.h"

class XRateCtrlV3_2 : public CigiBaseEventProcessor
{
public:
   XRateCtrlV3_2();
   virtual ~XRateCtrlV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiRateCtrlV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiRateCtrlV3_2 *TPckt;

};

#endif // _PROC_XRateCtrlV3_2_INCLUDED_
