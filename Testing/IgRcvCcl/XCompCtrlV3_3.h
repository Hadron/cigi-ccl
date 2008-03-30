// XCompCtrlV3_3.h: interface for the XCompCtrlV3_3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCompCtrlV3_3_INCLUDED_)
#define _PROC_XCompCtrlV3_3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCompCtrlV3_3.h"

class XCompCtrlV3_3 : public CigiBaseEventProcessor
{
public:
   XCompCtrlV3_3();
   virtual ~XCompCtrlV3_3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCompCtrlV3_3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCompCtrlV3_3 *TPckt;

};

#endif // _PROC_XCompCtrlV3_3_INCLUDED_
