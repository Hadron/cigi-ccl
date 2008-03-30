// XHatHotReqV3_2.h: interface for the XHatHotReqV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHatHotReqV3_2_INCLUDED_)
#define _PROC_XHatHotReqV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatHotReqV3_2.h"

class XHatHotReqV3_2 : public CigiBaseEventProcessor
{
public:
   XHatHotReqV3_2();
   virtual ~XHatHotReqV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatHotReqV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatHotReqV3_2 *TPckt;

};

#endif // _PROC_XHatHotReqV3_2_INCLUDED_
