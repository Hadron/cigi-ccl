// XLosXRespV3_2.h: Interface for the XLosXRespV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLOSXRESPV3_2_INCLUDED_)
#define _PROC_XLOSXRESPV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosXRespV3_2.h"

class XLosXRespV3_2 : public CigiBaseEventProcessor
{
public:
   XLosXRespV3_2();
   virtual ~XLosXRespV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosXRespV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosXRespV3_2 *TPckt;

};

#endif   //  _PROC_XLOSXRESPV3_2_INCLUDED_


