// Proc_CollDetSegRespV2.h: Interface for the Proc_CollDetSegRespV2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_COLLDETSEGRESPV2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_COLLDETSEGRESPV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiCollDetSegRespV2.h"

class Proc_CollDetSegRespV2 : public PcktParsingProcessor
{
public:
   Proc_CollDetSegRespV2();
   virtual ~Proc_CollDetSegRespV2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiCollDetSegRespV2 Om_CollDetSegRespV2;

};

#endif   //  PROC_COLLDETSEGRESPV2_PARSING_PROCESSOR_INCLUDED_


