// Proc_SymbolSurfaceDefV3_3.h: interface for the Proc_SymbolSurfaceDefV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SymbolSurfaceDefV3_3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SymbolSurfaceDefV3_3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSymbolSurfaceDefV3_3.h>


class Proc_SymbolSurfaceDefV3_3 : public PcktParsingProcessor
{
public:

   Proc_SymbolSurfaceDefV3_3(void);

   virtual ~Proc_SymbolSurfaceDefV3_3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSymbolSurfaceDefV3_3 Om_SymbolSurfaceDef;

};

#endif   //  _Proc_SymbolSurfaceDefV3_3_PARSING_PROCESSOR_INCLUDED_


