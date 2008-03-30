// XWeatherCtrlV2.h: interface for the XWeatherCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XWeatherCtrlV2_INCLUDED_)
#define _PROC_XWeatherCtrlV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiWeatherCtrlV2.h"

class XWeatherCtrlV2 : public CigiBaseEventProcessor
{
public:
   XWeatherCtrlV2();
   virtual ~XWeatherCtrlV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiWeatherCtrlV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiWeatherCtrlV2 *TPckt;

};

#endif // _PROC_XWeatherCtrlV2_INCLUDED_
