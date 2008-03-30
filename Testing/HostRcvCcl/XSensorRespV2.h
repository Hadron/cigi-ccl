// XSensorRespV2.h: Interface for the XSensorRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSENSORRESPV2_INCLUDED_)
#define _PROC_XSENSORRESPV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorRespV2.h"

class XSensorRespV2 : public CigiBaseEventProcessor
{
public:
   XSensorRespV2();
   virtual ~XSensorRespV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorRespV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorRespV2 *TPckt;

};

#endif   //  _PROC_XSENSORRESPV2_INCLUDED_


