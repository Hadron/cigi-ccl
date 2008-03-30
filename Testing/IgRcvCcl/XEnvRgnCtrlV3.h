// XEnvRgnCtrlV3.h: interface for the XEnvRgnCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEnvRgnCtrlV3_INCLUDED_)
#define _PROC_XEnvRgnCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEnvRgnCtrlV3.h"

class XEnvRgnCtrlV3 : public CigiBaseEventProcessor
{
public:
   XEnvRgnCtrlV3();
   virtual ~XEnvRgnCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEnvRgnCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEnvRgnCtrlV3 *TPckt;

};

#endif // _PROC_XEnvRgnCtrlV3_INCLUDED_
