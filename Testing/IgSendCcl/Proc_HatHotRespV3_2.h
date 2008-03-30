// Proc_HatHotRespV3_2.h: Interface for the Proc_HatHotRespV3_2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_HATHOTRESPV3_2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_HATHOTRESPV3_2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiHatHotRespV3_2.h"

class Proc_HatHotRespV3_2 : public PcktParsingProcessor
{
public:
   Proc_HatHotRespV3_2();
   virtual ~Proc_HatHotRespV3_2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiHatHotRespV3_2 Om_HatHotRespV3_2;

};

#endif   //  PROC_HATHOTRESPV3_2_PARSING_PROCESSOR_INCLUDED_


