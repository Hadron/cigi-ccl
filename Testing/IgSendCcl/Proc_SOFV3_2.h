// Proc_SOFV3_2.h: Interface for the Proc_SOFV3_2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_SOFV3_2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_SOFV3_2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiSOFV3_2.h"

class Proc_SOFV3_2 : public PcktParsingProcessor
{
public:
   Proc_SOFV3_2();
   virtual ~Proc_SOFV3_2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiSOFV3_2 Om_SOFV3_2;

};

#endif   //  PROC_SOFV3_2_PARSING_PROCESSOR_INCLUDED_


