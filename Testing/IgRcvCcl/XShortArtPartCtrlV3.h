// XShortArtPartCtrlV3.h: interface for the XShortArtPartCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XShortArtPartCtrlV3_INCLUDED_)
#define _PROC_XShortArtPartCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiShortArtPartCtrlV3.h"

class XShortArtPartCtrlV3 : public CigiBaseEventProcessor
{
public:
   XShortArtPartCtrlV3();
   virtual ~XShortArtPartCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiShortArtPartCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiShortArtPartCtrlV3 *TPckt;

};

#endif // _PROC_XShortArtPartCtrlV3_INCLUDED_
