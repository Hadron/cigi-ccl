// Proc_SymbolLineDefV3_3.h: interface for the Proc_SymbolLineDefV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SymbolLineDefV3_3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SymbolLineDefV3_3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSymbolLineDefV3_3.h>


class Proc_SymbolLineDefV3_3 : public PcktParsingProcessor
{
public:

   Proc_SymbolLineDefV3_3(void);

   virtual ~Proc_SymbolLineDefV3_3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSymbolLineDefV3_3 Om_SymbolLineDef;

};

#endif   //  _Proc_SymbolLineDefV3_3_PARSING_PROCESSOR_INCLUDED_


