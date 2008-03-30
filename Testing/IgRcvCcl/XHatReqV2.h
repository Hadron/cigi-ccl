// XHatReqV2.h: interface for the XHatReqV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHatReqV2_INCLUDED_)
#define _PROC_XHatReqV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatReqV2.h"

class XHatReqV2 : public CigiBaseEventProcessor
{
public:
   XHatReqV2();
   virtual ~XHatReqV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatReqV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatReqV2 *TPckt;

};

#endif // _PROC_XHatReqV2_INCLUDED_
