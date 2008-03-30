// XCompCtrl.h: interface for the XCompCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCompCtrl_INCLUDED_)
#define _PROC_XCompCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCompCtrlV3.h"

class XCompCtrl : public CigiBaseEventProcessor
{
public:
   XCompCtrl();
   virtual ~XCompCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCompCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCompCtrlV3 *TPckt;

};

#endif // _PROC_XCompCtrl_INCLUDED_
