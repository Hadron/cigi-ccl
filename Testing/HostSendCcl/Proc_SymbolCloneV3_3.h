// Proc_SymbolCloneV3_3.h: interface for the Proc_SymbolCloneV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SymbolCloneV3_3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SymbolCloneV3_3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSymbolCloneV3_3.h>


class Proc_SymbolCloneV3_3 : public PcktParsingProcessor
{
public:

   Proc_SymbolCloneV3_3(void);

   virtual ~Proc_SymbolCloneV3_3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSymbolCloneV3_3 Om_SymbolClone;

};

#endif   //  _Proc_SymbolCloneV3_3_PARSING_PROCESSOR_INCLUDED_


