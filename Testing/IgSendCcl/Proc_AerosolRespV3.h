// Proc_AerosolRespV3.h: Interface for the Proc_AerosolRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_AEROSOLRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_AEROSOLRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiAerosolRespV3.h"

class Proc_AerosolRespV3 : public PcktParsingProcessor
{
public:
   Proc_AerosolRespV3();
   virtual ~Proc_AerosolRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiAerosolRespV3 Om_AerosolRespV3;

};

#endif   //  PROC_AEROSOLRESPV3_PARSING_PROCESSOR_INCLUDED_


