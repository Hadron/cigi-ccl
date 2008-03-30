// Proc_CollDetVolDefV3.h: interface for the Proc_CollDetVolDefV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CollDetVolDefV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CollDetVolDefV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCollDetVolDefV3.h>


class Proc_CollDetVolDefV3 : public PcktParsingProcessor
{
public:

   Proc_CollDetVolDefV3(void);

   virtual ~Proc_CollDetVolDefV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCollDetVolDefV3 Om_CollDetVolDef;

};

#endif   //  _Proc_CollDetVolDefV3_PARSING_PROCESSOR_INCLUDED_


