// XPositionRespV3.h: Interface for the XPositionRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XPOSITIONRESPV3_INCLUDED_)
#define _PROC_XPOSITIONRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiPositionRespV3.h"

class XPositionRespV3 : public CigiBaseEventProcessor
{
public:
   XPositionRespV3();
   virtual ~XPositionRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiPositionRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiPositionRespV3 *TPckt;

};

#endif   //  _PROC_XPOSITIONRESPV3_INCLUDED_


