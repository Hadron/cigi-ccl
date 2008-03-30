// Proc_TerrestrialSurfaceRespV3.h: Interface for the Proc_TerrestrialSurfaceRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_TERRESTRIALSURFACERESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_TERRESTRIALSURFACERESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiTerrestrialSurfaceRespV3.h"

class Proc_TerrestrialSurfaceRespV3 : public PcktParsingProcessor
{
public:
   Proc_TerrestrialSurfaceRespV3();
   virtual ~Proc_TerrestrialSurfaceRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiTerrestrialSurfaceRespV3 Om_TerrestrialSurfaceRespV3;

};

#endif   //  PROC_TERRESTRIALSURFACERESPV3_PARSING_PROCESSOR_INCLUDED_


