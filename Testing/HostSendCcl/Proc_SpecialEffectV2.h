// Proc_SpecialEffectV2.h: interface for the Proc_SpecialEffectV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SpecialEffectV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SpecialEffectV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSpecEffDefV2.h>


class Proc_SpecialEffectV2 : public PcktParsingProcessor
{
public:

   Proc_SpecialEffectV2(void);

   virtual ~Proc_SpecialEffectV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSpecEffDefV2 Om_SpecialEffect;

};

#endif   //  _Proc_SpecialEffectV2_PARSING_PROCESSOR_INCLUDED_


