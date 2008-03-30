// XHatHotReqV3.h: interface for the XHatHotReqV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHatHotReqV3_INCLUDED_)
#define _PROC_XHatHotReqV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatHotReqV3.h"

class XHatHotReqV3 : public CigiBaseEventProcessor
{
public:
   XHatHotReqV3();
   virtual ~XHatHotReqV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatHotReqV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatHotReqV3 *TPckt;

};

#endif // _PROC_XHatHotReqV3_INCLUDED_
