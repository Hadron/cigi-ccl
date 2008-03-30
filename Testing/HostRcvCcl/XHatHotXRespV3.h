// XHatHotXRespV3.h: Interface for the XHatHotXRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XHATHOTXRESPV3_INCLUDED_)
#define _PROC_XHATHOTXRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiHatHotXRespV3.h"

class XHatHotXRespV3 : public CigiBaseEventProcessor
{
public:
   XHatHotXRespV3();
   virtual ~XHatHotXRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiHatHotXRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiHatHotXRespV3 *TPckt;

};

#endif   //  _PROC_XHATHOTXRESPV3_INCLUDED_


