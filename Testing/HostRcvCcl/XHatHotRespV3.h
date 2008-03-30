// XHatHotRespV3.h: Interface for the XHatHotRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHATHOTRESPV3_INCLUDED_)
#define _PROC_XHATHOTRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatHotRespV3.h"

class XHatHotRespV3 : public CigiBaseEventProcessor
{
public:
   XHatHotRespV3();
   virtual ~XHatHotRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatHotRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatHotRespV3 *TPckt;

};

#endif   //  _PROC_XHATHOTRESPV3_INCLUDED_


