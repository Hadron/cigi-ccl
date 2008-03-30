// XCollDetVolRespV3.h: Interface for the XCollDetVolRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCOLLDETVOLRESPV3_INCLUDED_)
#define _PROC_XCOLLDETVOLRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCollDetVolRespV3.h"

class XCollDetVolRespV3 : public CigiBaseEventProcessor
{
public:
   XCollDetVolRespV3();
   virtual ~XCollDetVolRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCollDetVolRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCollDetVolRespV3 *TPckt;

};

#endif   //  _PROC_XCOLLDETVOLRESPV3_INCLUDED_


