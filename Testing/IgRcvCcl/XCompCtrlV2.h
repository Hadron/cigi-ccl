// XCompCtrlV2.h: interface for the XCompCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCompCtrlV2_INCLUDED_)
#define _PROC_XCompCtrlV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCompCtrlV2.h"

class XCompCtrlV2 : public CigiBaseEventProcessor
{
public:
   XCompCtrlV2();
   virtual ~XCompCtrlV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCompCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCompCtrlV3 *TPckt;

};

#endif // _PROC_XCompCtrlV2_INCLUDED_
