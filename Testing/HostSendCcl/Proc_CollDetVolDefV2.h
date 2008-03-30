// Proc_CollDetVolDefV2.h: interface for the Proc_CollDetVolDefV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CollDetVolDefV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CollDetVolDefV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCollDetVolDefV2.h>


class Proc_CollDetVolDefV2 : public PcktParsingProcessor
{
public:

   Proc_CollDetVolDefV2(void);

   virtual ~Proc_CollDetVolDefV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCollDetVolDefV2 Om_CollDetVolDef;

};

#endif   //  _Proc_CollDetVolDefV2_PARSING_PROCESSOR_INCLUDED_


