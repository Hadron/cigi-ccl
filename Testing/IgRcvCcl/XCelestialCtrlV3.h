// XCelestialCtrlV3.h: interface for the XCelestialCtrlV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XCelestialCtrlV3_INCLUDED_)
#define _PROC_XCelestialCtrlV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiCelestialCtrl.h"

class XCelestialCtrlV3 : public CigiBaseEventProcessor
{
public:
   XCelestialCtrlV3();
   virtual ~XCelestialCtrlV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiCelestialCtrlV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiCelestialCtrlV3 *TPckt;

};

#endif // _PROC_XCelestialCtrlV3_INCLUDED_
