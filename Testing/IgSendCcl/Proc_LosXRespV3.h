// Proc_LosXRespV3.h: Interface for the Proc_LosXRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_LOSXRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_LOSXRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiLosXRespV3.h"

class Proc_LosXRespV3 : public PcktParsingProcessor
{
public:
   Proc_LosXRespV3();
   virtual ~Proc_LosXRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiLosXRespV3 Om_LosXRespV3;

};

#endif   //  PROC_LOSXRESPV3_PARSING_PROCESSOR_INCLUDED_


