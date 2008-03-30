// XViewCtrl.h: interface for the XViewCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XViewCtrl_INCLUDED_)
#define _PROC_XViewCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiViewCtrlV3.h"

class XViewCtrl : public CigiBaseEventProcessor
{
public:
   XViewCtrl();
   virtual ~XViewCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiViewCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiViewCtrlV3 *TPckt;

};

#endif // _PROC_XViewCtrl_INCLUDED_
