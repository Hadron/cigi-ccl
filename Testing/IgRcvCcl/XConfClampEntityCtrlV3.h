// XConfClampEntityCtrlV3.h: interface for the XConfClampEntityCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XConfClampEntityCtrlV3_INCLUDED_)
#define _PROC_XConfClampEntityCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiConfClampEntityCtrlV3.h"

class XConfClampEntityCtrlV3 : public CigiBaseEventProcessor
{
public:
   XConfClampEntityCtrlV3();
   virtual ~XConfClampEntityCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiConfClampEntityCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiConfClampEntityCtrlV3 *TPckt;

};

#endif // _PROC_XConfClampEntityCtrlV3_INCLUDED_
