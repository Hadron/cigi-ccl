// XEnvRgnCtrl.h: interface for the XEnvRgnCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEnvRgnCtrl_INCLUDED_)
#define _PROC_XEnvRgnCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEnvRgnCtrlV3.h"

class XEnvRgnCtrl : public CigiBaseEventProcessor
{
public:
   XEnvRgnCtrl();
   virtual ~XEnvRgnCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEnvRgnCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEnvRgnCtrlV3 *TPckt;

};

#endif // _PROC_XEnvRgnCtrl_INCLUDED_
