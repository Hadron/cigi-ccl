// XEnvCtrlV2.h: interface for the XEnvCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEnvCtrlV2_INCLUDED_)
#define _PROC_XEnvCtrlV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEnvCtrlV2.h"

class XEnvCtrlV2 : public CigiBaseEventProcessor
{
public:
   XEnvCtrlV2();
   virtual ~XEnvCtrlV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEnvCtrlV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEnvCtrlV2 *TPckt;

};

#endif // _PROC_XEnvCtrlV2_INCLUDED_
