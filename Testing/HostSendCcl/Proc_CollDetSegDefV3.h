// Proc_CollDetSegDefV3.h: interface for the Proc_CollDetSegDefV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CollDetSegDefV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CollDetSegDefV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCollDetSegDefV3.h>


class Proc_CollDetSegDefV3 : public PcktParsingProcessor
{
public:

   Proc_CollDetSegDefV3(void);

   virtual ~Proc_CollDetSegDefV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCollDetSegDefV3 Om_CollDetSegDef;

};

#endif   //  _Proc_CollDetSegDefV3_PARSING_PROCESSOR_INCLUDED_


