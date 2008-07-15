// XEntityCtrlV3_3.h: interface for the XEntityCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XEntityCtrlV3_3_INCLUDED_)
#define _PROC_XEntityCtrlV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiEntityCtrlV3_3.h"

class XEntityCtrlV3_3 : public CigiBaseEventProcessor
{
public:
   XEntityCtrlV3_3();
   virtual ~XEntityCtrlV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiEntityCtrlV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiEntityCtrlV3_3 *TPckt;

};

#endif // _PROC_XEntityCtrlV3_3_INCLUDED_
