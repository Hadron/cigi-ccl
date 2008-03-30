// XSensorCtrl.h: interface for the XSensorCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSensorCtrl_INCLUDED_)
#define _PROC_XSensorCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorCtrlV3.h"

class XSensorCtrl : public CigiBaseEventProcessor
{
public:
   XSensorCtrl();
   virtual ~XSensorCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorCtrlV3 *TPckt;

};

#endif // _PROC_XSensorCtrl_INCLUDED_
