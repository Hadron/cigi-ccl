// XRateCtrlV3.h: interface for the XRateCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XRateCtrlV3_INCLUDED_)
#define _PROC_XRateCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiRateCtrlV3.h"

class XRateCtrlV3 : public CigiBaseEventProcessor
{
public:
   XRateCtrlV3();
   virtual ~XRateCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiRateCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiRateCtrlV3 *TPckt;

};

#endif // _PROC_XRateCtrlV3_INCLUDED_
