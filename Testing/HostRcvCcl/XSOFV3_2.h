// XSOFV3_2.h: Interface for the XSOFV3_2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSOFV3_2_INCLUDED_)
#define _PROC_XSOFV3_2_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSOFV3_2.h"

class XSOFV3_2 : public CigiBaseEventProcessor
{
public:
   XSOFV3_2();
   virtual ~XSOFV3_2();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSOFV3_2 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSOFV3_2 *TPckt;

};

#endif   //  _PROC_XSOFV3_2_INCLUDED_


