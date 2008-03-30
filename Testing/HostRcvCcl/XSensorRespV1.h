// XSensorRespV1.h: Interface for the XSensorRespV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSENSORRESPV1_INCLUDED_)
#define _PROC_XSENSORRESPV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorRespV1.h"

class XSensorRespV1 : public CigiBaseEventProcessor
{
public:
   XSensorRespV1();
   virtual ~XSensorRespV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorRespV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorRespV1 *TPckt;

};

#endif   //  _PROC_XSENSORRESPV1_INCLUDED_


