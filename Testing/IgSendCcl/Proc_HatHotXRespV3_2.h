// Proc_HatHotXRespV3_2.h: Interface for the Proc_HatHotXRespV3_2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_HATHOTXRESPV3_2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_HATHOTXRESPV3_2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiHatHotXRespV3_2.h"

class Proc_HatHotXRespV3_2 : public PcktParsingProcessor
{
public:
   Proc_HatHotXRespV3_2();
   virtual ~Proc_HatHotXRespV3_2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiHatHotXRespV3_2 Om_HatHotXRespV3_2;

};

#endif   //  PROC_HATHOTXRESPV3_2_PARSING_PROCESSOR_INCLUDED_


