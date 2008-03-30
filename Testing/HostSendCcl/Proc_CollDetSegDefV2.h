// Proc_CollDetSegDefV2.h: interface for the Proc_CollDetSegDefV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CollDetSegDefV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CollDetSegDefV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCollDetSegDefV2.h>


class Proc_CollDetSegDefV2 : public PcktParsingProcessor
{
public:

   Proc_CollDetSegDefV2(void);

   virtual ~Proc_CollDetSegDefV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCollDetSegDefV2 Om_CollDetSegDef;

};

#endif   //  _Proc_CollDetSegDefV2_PARSING_PROCESSOR_INCLUDED_


