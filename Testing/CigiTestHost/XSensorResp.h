// XSensorResp.h: interface for the XSensorResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSensorResp_INCLUDED_)
#define _PROC_XSensorResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorRespV3.h"

class XSensorResp : public CigiBaseEventProcessor
{
public:
   XSensorResp();
   virtual ~XSensorResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorRespV3 *TPckt;

};

#endif // _PROC_XSensorResp_INCLUDED_
