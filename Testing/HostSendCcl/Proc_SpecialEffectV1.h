// Proc_SpecialEffectV1.h: interface for the Proc_SpecialEffectV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SpecialEffectV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SpecialEffectV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSpecEffDefV1.h>


class Proc_SpecialEffectV1 : public PcktParsingProcessor
{
public:

   Proc_SpecialEffectV1(void);

   virtual ~Proc_SpecialEffectV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSpecEffDefV1 Om_SpecialEffect;

};

#endif   //  _Proc_SpecialEffectV1_PARSING_PROCESSOR_INCLUDED_


