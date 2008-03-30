// Proc_ShortSymbolCtrlV3_3.h: interface for the Proc_ShortSymbolCtrlV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ShortSymbolCtrlV3_3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ShortSymbolCtrlV3_3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiShortSymbolCtrlV3_3.h>


class Proc_ShortSymbolCtrlV3_3 : public PcktParsingProcessor
{
public:

   Proc_ShortSymbolCtrlV3_3(void);

   virtual ~Proc_ShortSymbolCtrlV3_3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiShortSymbolCtrlV3_3 Om_ShortSymbolCtrl;

};

#endif   //  _Proc_ShortSymbolCtrlV3_3_PARSING_PROCESSOR_INCLUDED_


