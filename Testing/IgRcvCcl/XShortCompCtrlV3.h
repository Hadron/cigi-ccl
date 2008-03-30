// XShortCompCtrlV3.h: interface for the XShortCompCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XShortCompCtrlV3_INCLUDED_)
#define _PROC_XShortCompCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiShortCompCtrlV3.h"

class XShortCompCtrlV3 : public CigiBaseEventProcessor
{
public:
   XShortCompCtrlV3();
   virtual ~XShortCompCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiShortCompCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiShortCompCtrlV3 *TPckt;

};

#endif // _PROC_XShortCompCtrlV3_INCLUDED_
