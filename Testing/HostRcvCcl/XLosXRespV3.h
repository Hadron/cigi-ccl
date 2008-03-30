// XLosXRespV3.h: Interface for the XLosXRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLOSXRESPV3_INCLUDED_)
#define _PROC_XLOSXRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosXRespV3.h"

class XLosXRespV3 : public CigiBaseEventProcessor
{
public:
   XLosXRespV3();
   virtual ~XLosXRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosXRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosXRespV3 *TPckt;

};

#endif   //  _PROC_XLOSXRESPV3_INCLUDED_


