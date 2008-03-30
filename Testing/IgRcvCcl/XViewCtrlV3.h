// XViewCtrlV3.h: interface for the XViewCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XViewCtrlV3_INCLUDED_)
#define _PROC_XViewCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiViewCtrlV3.h"

class XViewCtrlV3 : public CigiBaseEventProcessor
{
public:
   XViewCtrlV3();
   virtual ~XViewCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiViewCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiViewCtrlV3 *TPckt;

};

#endif // _PROC_XViewCtrlV3_INCLUDED_
