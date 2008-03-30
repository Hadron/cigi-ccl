// XSOFV2.h: Interface for the XSOFV2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSOFV2_INCLUDED_)
#define _PROC_XSOFV2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSOFV2.h"

class XSOFV2 : public CigiBaseEventProcessor
{
public:
   XSOFV2();
   virtual ~XSOFV2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSOFV2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSOFV2 *TPckt;

};

#endif   //  _PROC_XSOFV2_INCLUDED_


