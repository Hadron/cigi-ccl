// XWaveCtrlV3.h: interface for the XWaveCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XWaveCtrlV3_INCLUDED_)
#define _PROC_XWaveCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiWaveCtrlV3.h"

class XWaveCtrlV3 : public CigiBaseEventProcessor
{
public:
   XWaveCtrlV3();
   virtual ~XWaveCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiWaveCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiWaveCtrlV3 *TPckt;

};

#endif // _PROC_XWaveCtrlV3_INCLUDED_
