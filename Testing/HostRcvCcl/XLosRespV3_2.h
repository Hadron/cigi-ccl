// XLosRespV3_2.h: Interface for the XLosRespV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLOSRESPV3_2_INCLUDED_)
#define _PROC_XLOSRESPV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosRespV3_2.h"

class XLosRespV3_2 : public CigiBaseEventProcessor
{
public:
   XLosRespV3_2();
   virtual ~XLosRespV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosRespV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosRespV3_2 *TPckt;

};

#endif   //  _PROC_XLOSRESPV3_2_INCLUDED_


