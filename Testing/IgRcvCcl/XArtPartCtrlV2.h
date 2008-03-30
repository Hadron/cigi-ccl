// XArtPartCtrlV2.h: interface for the XArtPartCtrlV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XArtPartCtrlV2_INCLUDED_)
#define _PROC_XArtPartCtrlV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiArtPartCtrlV3.h"

class XArtPartCtrlV2 : public CigiBaseEventProcessor
{
public:
   XArtPartCtrlV2();
   virtual ~XArtPartCtrlV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiArtPartCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiArtPartCtrlV3 *TPckt;

};

#endif // _PROC_XArtPartCtrlV2_INCLUDED_
