// Proc_CollDetSegDefV1.h: interface for the Proc_CollDetSegDefV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CollDetSegDefV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CollDetSegDefV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCollDetSegDefV1.h>


class Proc_CollDetSegDefV1 : public PcktParsingProcessor
{
public:

   Proc_CollDetSegDefV1(void);

   virtual ~Proc_CollDetSegDefV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCollDetSegDefV1 Om_CollDetSegDef;

};

#endif   //  _Proc_CollDetSegDefV1_PARSING_PROCESSOR_INCLUDED_


