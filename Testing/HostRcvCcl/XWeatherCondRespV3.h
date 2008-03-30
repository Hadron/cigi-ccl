// XWeatherCondRespV3.h: Interface for the XWeatherCondRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XWEATHERCONDRESPV3_INCLUDED_)
#define _PROC_XWEATHERCONDRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiWeatherCondRespV3.h"

class XWeatherCondRespV3 : public CigiBaseEventProcessor
{
public:
   XWeatherCondRespV3();
   virtual ~XWeatherCondRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiWeatherCondRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiWeatherCondRespV3 *TPckt;

};

#endif   //  _PROC_XWEATHERCONDRESPV3_INCLUDED_


