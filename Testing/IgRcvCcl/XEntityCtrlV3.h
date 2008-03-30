// XEntityCtrlV3.h: interface for the XEntityCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEntityCtrlV3_INCLUDED_)
#define _PROC_XEntityCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEntityCtrlV3.h"

class XEntityCtrlV3 : public CigiBaseEventProcessor
{
public:
   XEntityCtrlV3();
   virtual ~XEntityCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEntityCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEntityCtrlV3 *TPckt;

};

#endif // _PROC_XEntityCtrlV3_INCLUDED_
