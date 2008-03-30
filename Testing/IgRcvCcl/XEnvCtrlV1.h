// XEnvCtrlV1.h: interface for the XEnvCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEnvCtrlV1_INCLUDED_)
#define _PROC_XEnvCtrlV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEnvCtrlV1.h"

class XEnvCtrlV1 : public CigiBaseEventProcessor
{
public:
   XEnvCtrlV1();
   virtual ~XEnvCtrlV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEnvCtrlV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEnvCtrlV1 *TPckt;

};

#endif // _PROC_XEnvCtrlV1_INCLUDED_
