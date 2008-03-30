// Proc_CollDetSegRespV1.h: Interface for the Proc_CollDetSegRespV1 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_COLLDETSEGRESPV1_PARSING_PROCESSOR_INCLUDED_)
#define PROC_COLLDETSEGRESPV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiCollDetSegRespV1.h"

class Proc_CollDetSegRespV1 : public PcktParsingProcessor
{
public:
   Proc_CollDetSegRespV1();
   virtual ~Proc_CollDetSegRespV1();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiCollDetSegRespV1 Om_CollDetSegRespV1;

};

#endif   //  PROC_COLLDETSEGRESPV1_PARSING_PROCESSOR_INCLUDED_


