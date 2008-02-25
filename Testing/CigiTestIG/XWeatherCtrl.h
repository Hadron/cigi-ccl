// XWeatherCtrl.h: interface for the XWeatherCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XWeatherCtrl_INCLUDED_)
#define _PROC_XWeatherCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiWeatherCtrlV3.h"

class XWeatherCtrl : public CigiBaseEventProcessor
{
public:
   XWeatherCtrl();
   virtual ~XWeatherCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiWeatherCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiWeatherCtrlV3 *TPckt;

};

#endif // _PROC_XWeatherCtrl_INCLUDED_
