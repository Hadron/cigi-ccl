// Proc_HatRespV1.h: Interface for the Proc_HatRespV1 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_HATRESPV1_PARSING_PROCESSOR_INCLUDED_)
#define PROC_HATRESPV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiHatRespV1.h"

class Proc_HatRespV1 : public PcktParsingProcessor
{
public:
   Proc_HatRespV1();
   virtual ~Proc_HatRespV1();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiHatRespV1 Om_HatRespV1;

};

#endif   //  PROC_HATRESPV1_PARSING_PROCESSOR_INCLUDED_


