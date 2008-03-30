// Proc_SOFV3.h: Interface for the Proc_SOFV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_SOFV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_SOFV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiSOFV3.h"

class Proc_SOFV3 : public PcktParsingProcessor
{
public:
   Proc_SOFV3();
   virtual ~Proc_SOFV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiSOFV3 Om_SOFV3;

};

#endif   //  PROC_SOFV3_PARSING_PROCESSOR_INCLUDED_


