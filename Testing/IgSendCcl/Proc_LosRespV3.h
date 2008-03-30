// Proc_LosRespV3.h: Interface for the Proc_LosRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_LOSRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_LOSRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiLosRespV3.h"

class Proc_LosRespV3 : public PcktParsingProcessor
{
public:
   Proc_LosRespV3();
   virtual ~Proc_LosRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiLosRespV3 Om_LosRespV3;

};

#endif   //  PROC_LOSRESPV3_PARSING_PROCESSOR_INCLUDED_


