// Proc_CollDetVolRespV3.h: Interface for the Proc_CollDetVolRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_COLLDETVOLRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_COLLDETVOLRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiCollDetVolRespV3.h"

class Proc_CollDetVolRespV3 : public PcktParsingProcessor
{
public:
   Proc_CollDetVolRespV3();
   virtual ~Proc_CollDetVolRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiCollDetVolRespV3 Om_CollDetVolRespV3;

};

#endif   //  PROC_COLLDETVOLRESPV3_PARSING_PROCESSOR_INCLUDED_


