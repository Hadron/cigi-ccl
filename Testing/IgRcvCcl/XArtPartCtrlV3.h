// XArtPartCtrlV3.h: interface for the XArtPartCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XArtPartCtrlV3_INCLUDED_)
#define _PROC_XArtPartCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiArtPartCtrlV3.h"

class XArtPartCtrlV3 : public CigiBaseEventProcessor
{
public:
   XArtPartCtrlV3();
   virtual ~XArtPartCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiArtPartCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiArtPartCtrlV3 *TPckt;

};

#endif // _PROC_XArtPartCtrlV3_INCLUDED_
