// Proc_EventNotificationV3.h: Interface for the Proc_EventNotificationV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_EVENTNOTIFICATIONV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_EVENTNOTIFICATIONV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiEventNotificationV3.h"

class Proc_EventNotificationV3 : public PcktParsingProcessor
{
public:
   Proc_EventNotificationV3();
   virtual ~Proc_EventNotificationV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiEventNotificationV3 Om_EventNotificationV3;

};

#endif   //  PROC_EVENTNOTIFICATIONV3_PARSING_PROCESSOR_INCLUDED_


