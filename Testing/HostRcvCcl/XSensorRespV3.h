// XSensorRespV3.h: Interface for the XSensorRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSENSORRESPV3_INCLUDED_)
#define _PROC_XSENSORRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSensorRespV3.h"

class XSensorRespV3 : public CigiBaseEventProcessor
{
public:
   XSensorRespV3();
   virtual ~XSensorRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSensorRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSensorRespV3 *TPckt;

};

#endif   //  _PROC_XSENSORRESPV3_INCLUDED_


