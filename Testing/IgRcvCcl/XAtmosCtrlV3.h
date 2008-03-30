// XAtmosCtrlV3.h: interface for the XAtmosCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XAtmosCtrlV3_INCLUDED_)
#define _PROC_XAtmosCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiAtmosCtrl.h"

class XAtmosCtrlV3 : public CigiBaseEventProcessor
{
public:
   XAtmosCtrlV3();
   virtual ~XAtmosCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiAtmosCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiAtmosCtrlV3 *TPckt;

};

#endif // _PROC_XAtmosCtrlV3_INCLUDED_
