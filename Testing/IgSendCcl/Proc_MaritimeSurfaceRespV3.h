// Proc_MaritimeSurfaceRespV3.h: Interface for the Proc_MaritimeSurfaceRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_MARITIMESURFACERESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_MARITIMESURFACERESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiMaritimeSurfaceRespV3.h"

class Proc_MaritimeSurfaceRespV3 : public PcktParsingProcessor
{
public:
   Proc_MaritimeSurfaceRespV3();
   virtual ~Proc_MaritimeSurfaceRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiMaritimeSurfaceRespV3 Om_MaritimeSurfaceRespV3;

};

#endif   //  PROC_MARITIMESURFACERESPV3_PARSING_PROCESSOR_INCLUDED_


