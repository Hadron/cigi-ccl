// XAtmosCtrl.h: interface for the XAtmosCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XAtmosCtrl_INCLUDED_)
#define _PROC_XAtmosCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiAtmosCtrl.h"

class XAtmosCtrl : public CigiBaseEventProcessor
{
public:
   XAtmosCtrl();
   virtual ~XAtmosCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiAtmosCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiAtmosCtrlV3 *TPckt;

};

#endif // _PROC_XAtmosCtrl_INCLUDED_
