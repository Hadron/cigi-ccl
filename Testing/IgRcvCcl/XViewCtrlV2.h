// XViewCtrlV2.h: interface for the XViewCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XViewCtrlV2_INCLUDED_)
#define _PROC_XViewCtrlV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiViewCtrlV2.h"

class XViewCtrlV2 : public CigiBaseEventProcessor
{
public:
   XViewCtrlV2();
   virtual ~XViewCtrlV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiViewCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiViewCtrlV3 *TPckt;

};

#endif // _PROC_XViewCtrlV2_INCLUDED_
