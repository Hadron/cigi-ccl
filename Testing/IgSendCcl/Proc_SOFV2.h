// Proc_SOFV2.h: Interface for the Proc_SOFV2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_SOFV2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_SOFV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiSOFV2.h"

class Proc_SOFV2 : public PcktParsingProcessor
{
public:
   Proc_SOFV2();
   virtual ~Proc_SOFV2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiSOFV2 Om_SOFV2;

};

#endif   //  PROC_SOFV2_PARSING_PROCESSOR_INCLUDED_


