// XAnimationStopV3.h: Interface for the XAnimationStopV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XANIMATIONSTOPV3_INCLUDED_)
#define _PROC_XANIMATIONSTOPV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiAnimationStopV3.h"

class XAnimationStopV3 : public CigiBaseEventProcessor
{
public:
   XAnimationStopV3();
   virtual ~XAnimationStopV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiAnimationStopV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiAnimationStopV3 *TPckt;

};

#endif   //  _PROC_XANIMATIONSTOPV3_INCLUDED_


