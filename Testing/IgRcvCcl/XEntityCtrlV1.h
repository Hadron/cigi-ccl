// XEntityCtrlV1.h: interface for the XEntityCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEntityCtrlV1_INCLUDED_)
#define _PROC_XEntityCtrlV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEntityCtrlV1.h"

class XEntityCtrlV1 : public CigiBaseEventProcessor
{
public:
   XEntityCtrlV1();
   virtual ~XEntityCtrlV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEntityCtrlV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEntityCtrlV1 *TPckt;

};

#endif // _PROC_XEntityCtrlV1_INCLUDED_
