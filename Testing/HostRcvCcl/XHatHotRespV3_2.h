// XHatHotRespV3_2.h: Interface for the XHatHotRespV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHATHOTRESPV3_2_INCLUDED_)
#define _PROC_XHATHOTRESPV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatHotRespV3_2.h"

class XHatHotRespV3_2 : public CigiBaseEventProcessor
{
public:
   XHatHotRespV3_2();
   virtual ~XHatHotRespV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatHotRespV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatHotRespV3_2 *TPckt;

};

#endif   //  _PROC_XHATHOTRESPV3_2_INCLUDED_


