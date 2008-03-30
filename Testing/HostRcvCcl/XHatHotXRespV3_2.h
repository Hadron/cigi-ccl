// XHatHotXRespV3_2.h: Interface for the XHatHotXRespV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHATHOTXRESPV3_2_INCLUDED_)
#define _PROC_XHATHOTXRESPV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatHotXRespV3_2.h"

class XHatHotXRespV3_2 : public CigiBaseEventProcessor
{
public:
   XHatHotXRespV3_2();
   virtual ~XHatHotXRespV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatHotXRespV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatHotXRespV3_2 *TPckt;

};

#endif   //  _PROC_XHATHOTXRESPV3_2_INCLUDED_


