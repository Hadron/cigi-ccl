// XCompCtrlV1.h: interface for the XCompCtrlV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCompCtrlV1_INCLUDED_)
#define _PROC_XCompCtrlV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCompCtrlV1.h"

class XCompCtrlV1 : public CigiBaseEventProcessor
{
public:
   XCompCtrlV1();
   virtual ~XCompCtrlV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCompCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCompCtrlV3 *TPckt;

};

#endif // _PROC_XCompCtrlV1_INCLUDED_
