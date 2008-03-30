// XWeatherCtrlV1.h: interface for the XWeatherCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XWeatherCtrlV1_INCLUDED_)
#define _PROC_XWeatherCtrlV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiWeatherCtrlV1.h"

class XWeatherCtrlV1 : public CigiBaseEventProcessor
{
public:
   XWeatherCtrlV1();
   virtual ~XWeatherCtrlV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiWeatherCtrlV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiWeatherCtrlV1 *TPckt;

};

#endif // _PROC_XWeatherCtrlV1_INCLUDED_
