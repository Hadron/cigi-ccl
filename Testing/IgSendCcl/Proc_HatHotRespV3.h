// Proc_HatHotRespV3.h: Interface for the Proc_HatHotRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_HATHOTRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_HATHOTRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiHatHotRespV3.h"

class Proc_HatHotRespV3 : public PcktParsingProcessor
{
public:
   Proc_HatHotRespV3();
   virtual ~Proc_HatHotRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiHatHotRespV3 Om_HatHotRespV3;

};

#endif   //  PROC_HATHOTRESPV3_PARSING_PROCESSOR_INCLUDED_


