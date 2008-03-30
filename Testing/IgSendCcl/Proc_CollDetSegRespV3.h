// Proc_CollDetSegRespV3.h: Interface for the Proc_CollDetSegRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_COLLDETSEGRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_COLLDETSEGRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiCollDetSegRespV3.h"

class Proc_CollDetSegRespV3 : public PcktParsingProcessor
{
public:
   Proc_CollDetSegRespV3();
   virtual ~Proc_CollDetSegRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiCollDetSegRespV3 Om_CollDetSegRespV3;

};

#endif   //  PROC_COLLDETSEGRESPV3_PARSING_PROCESSOR_INCLUDED_


