// XEarthModelDefV3.h: interface for the XEarthModelDefV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEarthModelDefV3_INCLUDED_)
#define _PROC_XEarthModelDefV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEarthModelDefV3.h"

class XEarthModelDefV3 : public CigiBaseEventProcessor
{
public:
   XEarthModelDefV3();
   virtual ~XEarthModelDefV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEarthModelDefV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEarthModelDefV3 *TPckt;

};

#endif // _PROC_XEarthModelDefV3_INCLUDED_
