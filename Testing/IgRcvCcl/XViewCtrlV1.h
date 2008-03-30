// XViewCtrlV1.h: interface for the XViewCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XViewCtrlV1_INCLUDED_)
#define _PROC_XViewCtrlV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiViewCtrlV1.h"

class XViewCtrlV1 : public CigiBaseEventProcessor
{
public:
   XViewCtrlV1();
   virtual ~XViewCtrlV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiViewCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiViewCtrlV3 *TPckt;

};

#endif // _PROC_XViewCtrlV1_INCLUDED_
