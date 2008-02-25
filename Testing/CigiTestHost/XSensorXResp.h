// XSensorXResp.h: interface for the XSensorXResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSensorXResp_INCLUDED_)
#define _PROC_XSensorXResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorXRespV3.h"

class XSensorXResp : public CigiBaseEventProcessor
{
public:
   XSensorXResp();
   virtual ~XSensorXResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorXRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorXRespV3 *TPckt;

};

#endif // _PROC_XSensorXResp_INCLUDED_
