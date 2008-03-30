// Proc_HotRespV2.h: Interface for the Proc_HotRespV2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_HOTRESPV2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_HOTRESPV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiHotRespV2.h"

class Proc_HotRespV2 : public PcktParsingProcessor
{
public:
   Proc_HotRespV2();
   virtual ~Proc_HotRespV2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiHotRespV2 Om_HotRespV2;

};

#endif   //  PROC_HOTRESPV2_PARSING_PROCESSOR_INCLUDED_


