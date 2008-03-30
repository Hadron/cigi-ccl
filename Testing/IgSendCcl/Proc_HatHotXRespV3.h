// Proc_HatHotXRespV3.h: Interface for the Proc_HatHotXRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_HATHOTXRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_HATHOTXRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiHatHotXRespV3.h"

class Proc_HatHotXRespV3 : public PcktParsingProcessor
{
public:
   Proc_HatHotXRespV3();
   virtual ~Proc_HatHotXRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiHatHotXRespV3 Om_HatHotXRespV3;

};

#endif   //  PROC_HATHOTXRESPV3_PARSING_PROCESSOR_INCLUDED_


