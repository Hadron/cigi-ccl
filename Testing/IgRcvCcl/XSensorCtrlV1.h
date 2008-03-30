// XSensorCtrlV1.h: interface for the XSensorCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSensorCtrlV1_INCLUDED_)
#define _PROC_XSensorCtrlV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorCtrlV1.h"

class XSensorCtrlV1 : public CigiBaseEventProcessor
{
public:
   XSensorCtrlV1();
   virtual ~XSensorCtrlV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorCtrlV3 *TPckt;

};

#endif // _PROC_XSensorCtrlV1_INCLUDED_
