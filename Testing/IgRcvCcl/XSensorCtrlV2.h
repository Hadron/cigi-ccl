// XSensorCtrlV2.h: interface for the XSensorCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSensorCtrlV2_INCLUDED_)
#define _PROC_XSensorCtrlV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorCtrlV2.h"

class XSensorCtrlV2 : public CigiBaseEventProcessor
{
public:
   XSensorCtrlV2();
   virtual ~XSensorCtrlV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorCtrlV3 *TPckt;

};

#endif // _PROC_XSensorCtrlV2_INCLUDED_
