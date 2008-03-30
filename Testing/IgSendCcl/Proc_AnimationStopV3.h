// Proc_AnimationStopV3.h: Interface for the Proc_AnimationStopV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_ANIMATIONSTOPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_ANIMATIONSTOPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiAnimationStopV3.h"

class Proc_AnimationStopV3 : public PcktParsingProcessor
{
public:
   Proc_AnimationStopV3();
   virtual ~Proc_AnimationStopV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiAnimationStopV3 Om_AnimationStopV3;

};

#endif   //  PROC_ANIMATIONSTOPV3_PARSING_PROCESSOR_INCLUDED_


