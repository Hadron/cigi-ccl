// Proc_LosRespV2.h: Interface for the Proc_LosRespV2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_LOSRESPV2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_LOSRESPV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiLosRespV2.h"

class Proc_LosRespV2 : public PcktParsingProcessor
{
public:
   Proc_LosRespV2();
   virtual ~Proc_LosRespV2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiLosRespV2 Om_LosRespV2;

};

#endif   //  PROC_LOSRESPV2_PARSING_PROCESSOR_INCLUDED_


