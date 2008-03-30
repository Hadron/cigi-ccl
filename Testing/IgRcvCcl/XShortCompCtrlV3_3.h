// XShortCompCtrlV3_3.h: interface for the XShortCompCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XShortCompCtrlV3_3_INCLUDED_)
#define _PROC_XShortCompCtrlV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiShortCompCtrlV3_3.h"

class XShortCompCtrlV3_3 : public CigiBaseEventProcessor
{
public:
   XShortCompCtrlV3_3();
   virtual ~XShortCompCtrlV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiShortCompCtrlV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiShortCompCtrlV3_3 *TPckt;

};

#endif // _PROC_XShortCompCtrlV3_3_INCLUDED_
