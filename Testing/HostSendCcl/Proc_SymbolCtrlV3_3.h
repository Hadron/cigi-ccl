// Proc_SymbolCtrlV3_3.h: interface for the Proc_SymbolCtrlV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SymbolCtrlV3_3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SymbolCtrlV3_3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSymbolCtrlV3_3.h>


class Proc_SymbolCtrlV3_3 : public PcktParsingProcessor
{
public:

   Proc_SymbolCtrlV3_3(void);

   virtual ~Proc_SymbolCtrlV3_3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSymbolCtrlV3_3 Om_SymbolCtrl;

};

#endif   //  _Proc_SymbolCtrlV3_3_PARSING_PROCESSOR_INCLUDED_


