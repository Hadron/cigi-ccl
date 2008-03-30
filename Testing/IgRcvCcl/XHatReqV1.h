// XHatReqV1.h: interface for the XHatReqV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHatReqV1_INCLUDED_)
#define _PROC_XHatReqV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatReqV1.h"

class XHatReqV1 : public CigiBaseEventProcessor
{
public:
   XHatReqV1();
   virtual ~XHatReqV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatReqV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatReqV1 *TPckt;

};

#endif // _PROC_XHatReqV1_INCLUDED_
