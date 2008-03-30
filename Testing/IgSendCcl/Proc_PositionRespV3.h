// Proc_PositionRespV3.h: Interface for the Proc_PositionRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_POSITIONRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_POSITIONRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiPositionRespV3.h"

class Proc_PositionRespV3 : public PcktParsingProcessor
{
public:
   Proc_PositionRespV3();
   virtual ~Proc_PositionRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiPositionRespV3 Om_PositionRespV3;

};

#endif   //  PROC_POSITIONRESPV3_PARSING_PROCESSOR_INCLUDED_


