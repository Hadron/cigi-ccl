// XLosRespV2.h: Interface for the XLosRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLOSRESPV2_INCLUDED_)
#define _PROC_XLOSRESPV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosRespV2.h"

class XLosRespV2 : public CigiBaseEventProcessor
{
public:
   XLosRespV2();
   virtual ~XLosRespV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosRespV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosRespV2 *TPckt;

};

#endif   //  _PROC_XLOSRESPV2_INCLUDED_


