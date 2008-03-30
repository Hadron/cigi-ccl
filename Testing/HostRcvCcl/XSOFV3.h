// XSOFV3.h: Interface for the XSOFV3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSOFV3_INCLUDED_)
#define _PROC_XSOFV3_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSOFV3.h"

class XSOFV3 : public CigiBaseEventProcessor
{
public:
   XSOFV3();
   virtual ~XSOFV3();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSOFV3 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSOFV3 *TPckt;

};

#endif   //  _PROC_XSOFV3_INCLUDED_


