// XShortCompCtrl.h: interface for the XShortCompCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XShortCompCtrl_INCLUDED_)
#define _PROC_XShortCompCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiShortCompCtrlV3.h"

class XShortCompCtrl : public CigiBaseEventProcessor
{
public:
   XShortCompCtrl();
   virtual ~XShortCompCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiShortCompCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiShortCompCtrlV3 *TPckt;

};

#endif // _PROC_XShortCompCtrl_INCLUDED_
