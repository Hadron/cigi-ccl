// XWeatherCtrlV3.h: interface for the XWeatherCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XWeatherCtrlV3_INCLUDED_)
#define _PROC_XWeatherCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiWeatherCtrlV3.h"

class XWeatherCtrlV3 : public CigiBaseEventProcessor
{
public:
   XWeatherCtrlV3();
   virtual ~XWeatherCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiWeatherCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiWeatherCtrlV3 *TPckt;

};

#endif // _PROC_XWeatherCtrlV3_INCLUDED_
