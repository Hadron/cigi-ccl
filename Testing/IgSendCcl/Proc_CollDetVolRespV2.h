// Proc_CollDetVolRespV2.h: Interface for the Proc_CollDetVolRespV2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_COLLDETVOLRESPV2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_COLLDETVOLRESPV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiCollDetVolRespV2.h"

class Proc_CollDetVolRespV2 : public PcktParsingProcessor
{
public:
   Proc_CollDetVolRespV2();
   virtual ~Proc_CollDetVolRespV2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiCollDetVolRespV2 Om_CollDetVolRespV2;

};

#endif   //  PROC_COLLDETVOLRESPV2_PARSING_PROCESSOR_INCLUDED_


