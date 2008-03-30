// XSensorCtrlV3.h: interface for the XSensorCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSensorCtrlV3_INCLUDED_)
#define _PROC_XSensorCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorCtrlV3.h"

class XSensorCtrlV3 : public CigiBaseEventProcessor
{
public:
   XSensorCtrlV3();
   virtual ~XSensorCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorCtrlV3 *TPckt;

};

#endif // _PROC_XSensorCtrlV3_INCLUDED_
