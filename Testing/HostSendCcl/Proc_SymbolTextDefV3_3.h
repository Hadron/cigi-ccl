// Proc_SymbolTextDefV3_3.h: interface for the Proc_SymbolTextDefV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SymbolTextDefV3_3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SymbolTextDefV3_3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSymbolTextDefV3_3.h>


class Proc_SymbolTextDefV3_3 : public PcktParsingProcessor
{
public:

   Proc_SymbolTextDefV3_3(void);

   virtual ~Proc_SymbolTextDefV3_3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSymbolTextDefV3_3 Om_SymbolTextDef;

};

#endif   //  _Proc_SymbolTextDefV3_3_PARSING_PROCESSOR_INCLUDED_


