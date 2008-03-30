// XSensorXRespV3.h: Interface for the XSensorXRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSENSORXRESPV3_INCLUDED_)
#define _PROC_XSENSORXRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorXRespV3.h"

class XSensorXRespV3 : public CigiBaseEventProcessor
{
public:
   XSensorXRespV3();
   virtual ~XSensorXRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorXRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorXRespV3 *TPckt;

};

#endif   //  _PROC_XSENSORXRESPV3_INCLUDED_


