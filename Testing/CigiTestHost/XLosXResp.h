// XLosXResp.h: interface for the XLosXResp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XLosXResp_INCLUDED_)
#define _PROC_XLosXResp_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiLosXRespV3_2.h"

class XLosXResp : public CigiBaseEventProcessor
{
public:
   XLosXResp();
   virtual ~XLosXResp();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiLosXRespV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiLosXRespV3_2 *TPckt;

};

#endif // _PROC_XLosXResp_INCLUDED_
