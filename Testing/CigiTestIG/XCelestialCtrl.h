// XCelestialCtrl.h: interface for the XCelestialCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCelestialCtrl_INCLUDED_)
#define _PROC_XCelestialCtrl_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCelestialCtrl.h"

class XCelestialCtrl : public CigiBaseEventProcessor
{
public:
   XCelestialCtrl();
   virtual ~XCelestialCtrl();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCelestialCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCelestialCtrlV3 *TPckt;

};

#endif // _PROC_XCelestialCtrl_INCLUDED_
