// XCollDetVolRespV2.h: Interface for the XCollDetVolRespV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCOLLDETVOLRESPV2_INCLUDED_)
#define _PROC_XCOLLDETVOLRESPV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetVolRespV2.h"

class XCollDetVolRespV2 : public CigiBaseEventProcessor
{
public:
   XCollDetVolRespV2();
   virtual ~XCollDetVolRespV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetVolRespV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetVolRespV2 *TPckt;

};

#endif   //  _PROC_XCOLLDETVOLRESPV2_INCLUDED_


