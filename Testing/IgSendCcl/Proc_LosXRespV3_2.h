// Proc_LosXRespV3_2.h: Interface for the Proc_LosXRespV3_2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_LOSXRESPV3_2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_LOSXRESPV3_2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiLosXRespV3_2.h"

class Proc_LosXRespV3_2 : public PcktParsingProcessor
{
public:
   Proc_LosXRespV3_2();
   virtual ~Proc_LosXRespV3_2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiLosXRespV3_2 Om_LosXRespV3_2;

};

#endif   //  PROC_LOSXRESPV3_2_PARSING_PROCESSOR_INCLUDED_


