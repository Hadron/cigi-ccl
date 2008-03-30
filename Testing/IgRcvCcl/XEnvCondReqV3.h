// XEnvCondReqV3.h: interface for the XEnvCondReqV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEnvCondReqV3_INCLUDED_)
#define _PROC_XEnvCondReqV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEnvCondReqV3.h"

class XEnvCondReqV3 : public CigiBaseEventProcessor
{
public:
   XEnvCondReqV3();
   virtual ~XEnvCondReqV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEnvCondReqV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEnvCondReqV3 *TPckt;

};

#endif // _PROC_XEnvCondReqV3_INCLUDED_
