// Proc_HatRespV2.h: Interface for the Proc_HatRespV2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_HATRESPV2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_HATRESPV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiHatRespV2.h"

class Proc_HatRespV2 : public PcktParsingProcessor
{
public:
   Proc_HatRespV2();
   virtual ~Proc_HatRespV2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiHatRespV2 Om_HatRespV2;

};

#endif   //  PROC_HATRESPV2_PARSING_PROCESSOR_INCLUDED_


