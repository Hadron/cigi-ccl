// Proc_LosRespV3_2.h: Interface for the Proc_LosRespV3_2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_LOSRESPV3_2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_LOSRESPV3_2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiLosRespV3_2.h"

class Proc_LosRespV3_2 : public PcktParsingProcessor
{
public:
   Proc_LosRespV3_2();
   virtual ~Proc_LosRespV3_2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiLosRespV3_2 Om_LosRespV3_2;

};

#endif   //  PROC_LOSRESPV3_2_PARSING_PROCESSOR_INCLUDED_


