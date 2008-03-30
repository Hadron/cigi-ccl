// XEntityCtrl.h: interface for the XEntityCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEntityCtrl_INCLUDED_)
#define _PROC_XEntityCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEntityCtrlV3.h"

class XEntityCtrl : public CigiBaseEventProcessor
{
public:
   XEntityCtrl();
   virtual ~XEntityCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEntityCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEntityCtrlV3 *TPckt;

};

#endif // _PROC_XEntityCtrl_INCLUDED_
