// XSOFV1.h: Interface for the XSOFV1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PROC_XSOFV1_INCLUDED_)
#define _PROC_XSOFV1_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiSOFV1.h"

class XSOFV1 : public CigiBaseEventProcessor
{
public:
   XSOFV1();
   virtual ~XSOFV1();

   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void SetOrigPckt(CigiSOFV1 *TPcktIn) { TPckt = TPcktIn; }

protected:
   CigiSOFV1 *TPckt;

};

#endif   //  _PROC_XSOFV1_INCLUDED_


