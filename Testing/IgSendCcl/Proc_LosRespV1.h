// Proc_LosRespV1.h: Interface for the Proc_LosRespV1 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_LOSRESPV1_PARSING_PROCESSOR_INCLUDED_)
#define PROC_LOSRESPV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiLosRespV1.h"

class Proc_LosRespV1 : public PcktParsingProcessor
{
public:
   Proc_LosRespV1();
   virtual ~Proc_LosRespV1();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiLosRespV1 Om_LosRespV1;

};

#endif   //  PROC_LOSRESPV1_PARSING_PROCESSOR_INCLUDED_


