// XAerosolRespV3.h: Interface for the XAerosolRespV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XAEROSOLRESPV3_INCLUDED_)
#define _PROC_XAEROSOLRESPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiAerosolRespV3.h"

class XAerosolRespV3 : public CigiBaseEventProcessor
{
public:
   XAerosolRespV3();
   virtual ~XAerosolRespV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiAerosolRespV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiAerosolRespV3 *TPckt;

};

#endif   //  _PROC_XAEROSOLRESPV3_INCLUDED_


