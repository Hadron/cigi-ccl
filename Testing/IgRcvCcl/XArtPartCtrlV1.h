// XArtPartCtrlV1.h: interface for the XArtPartCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XArtPartCtrlV1_INCLUDED_)
#define _PROC_XArtPartCtrlV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiArtPartCtrlV3.h"

class XArtPartCtrlV1 : public CigiBaseEventProcessor
{
public:
   XArtPartCtrlV1();
   virtual ~XArtPartCtrlV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiArtPartCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiArtPartCtrlV3 *TPckt;

};

#endif // _PROC_XArtPartCtrlV1_INCLUDED_
