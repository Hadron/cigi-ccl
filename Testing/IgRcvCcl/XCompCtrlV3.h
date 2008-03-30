// XCompCtrlV3.h: interface for the XCompCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCompCtrlV3_INCLUDED_)
#define _PROC_XCompCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCompCtrlV3.h"

class XCompCtrlV3 : public CigiBaseEventProcessor
{
public:
   XCompCtrlV3();
   virtual ~XCompCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCompCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCompCtrlV3 *TPckt;

};

#endif // _PROC_XCompCtrlV3_INCLUDED_
