// XEntityCtrlV2.h: interface for the XEntityCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEntityCtrlV2_INCLUDED_)
#define _PROC_XEntityCtrlV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEntityCtrlV2.h"

class XEntityCtrlV2 : public CigiBaseEventProcessor
{
public:
   XEntityCtrlV2();
   virtual ~XEntityCtrlV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEntityCtrlV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEntityCtrlV2 *TPckt;

};

#endif // _PROC_XEntityCtrlV2_INCLUDED_
