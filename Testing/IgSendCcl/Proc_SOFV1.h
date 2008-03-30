// Proc_SOFV1.h: Interface for the Proc_SOFV1 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_SOFV1_PARSING_PROCESSOR_INCLUDED_)
#define PROC_SOFV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiSOFV1.h"

class Proc_SOFV1 : public PcktParsingProcessor
{
public:
   Proc_SOFV1();
   virtual ~Proc_SOFV1();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiSOFV1 Om_SOFV1;

};

#endif   //  PROC_SOFV1_PARSING_PROCESSOR_INCLUDED_


