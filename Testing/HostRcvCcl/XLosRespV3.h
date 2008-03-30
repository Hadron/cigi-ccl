// XLosRespV3.h: Interface for the XLosRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLOSRESPV3_INCLUDED_)
#define _PROC_XLOSRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosRespV3.h"

class XLosRespV3 : public CigiBaseEventProcessor
{
public:
   XLosRespV3();
   virtual ~XLosRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosRespV3 *TPckt;

};

#endif   //  _PROC_XLOSRESPV3_INCLUDED_


