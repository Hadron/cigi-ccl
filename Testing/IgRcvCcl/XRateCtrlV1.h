// XRateCtrlV1.h: interface for the XRateCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XRateCtrlV1_INCLUDED_)
#define _PROC_XRateCtrlV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiRateCtrlV1.h"

class XRateCtrlV1 : public CigiBaseEventProcessor
{
public:
   XRateCtrlV1();
   virtual ~XRateCtrlV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiRateCtrlV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiRateCtrlV1 *TPckt;

};

#endif // _PROC_XRateCtrlV1_INCLUDED_
