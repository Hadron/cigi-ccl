// XLosRespV1.h: Interface for the XLosRespV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLOSRESPV1_INCLUDED_)
#define _PROC_XLOSRESPV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosRespV1.h"

class XLosRespV1 : public CigiBaseEventProcessor
{
public:
   XLosRespV1();
   virtual ~XLosRespV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosRespV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosRespV1 *TPckt;

};

#endif   //  _PROC_XLOSRESPV1_INCLUDED_


