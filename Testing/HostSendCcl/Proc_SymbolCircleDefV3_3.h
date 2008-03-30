// Proc_SymbolCircleDefV3_3.h: interface for the Proc_SymbolCircleDefV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SymbolCircleDefV3_3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SymbolCircleDefV3_3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSymbolCircleDefV3_3.h>


class Proc_SymbolCircleDefV3_3 : public PcktParsingProcessor
{
public:

   Proc_SymbolCircleDefV3_3(void);

   virtual ~Proc_SymbolCircleDefV3_3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSymbolCircleDefV3_3 Om_SymbolCircleDef;

};

#endif   //  _Proc_SymbolCircleDefV3_3_PARSING_PROCESSOR_INCLUDED_


