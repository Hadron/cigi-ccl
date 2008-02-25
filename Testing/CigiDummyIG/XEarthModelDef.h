// XEarthModelDef.h: interface for the XEarthModelDef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEarthModelDef_INCLUDED_)
#define _PROC_XEarthModelDef_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEarthModelDefV3.h"

class XEarthModelDef : public CigiBaseEventProcessor
{
public:
   XEarthModelDef();
   virtual ~XEarthModelDef();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEarthModelDefV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEarthModelDefV3 *TPckt;

};

#endif // _PROC_XEarthModelDef_INCLUDED_
