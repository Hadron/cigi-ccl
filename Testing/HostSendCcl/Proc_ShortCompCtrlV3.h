// Proc_ShortCompCtrlV3.h: interface for the Proc_ShortCompCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ShortCompCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ShortCompCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiShortCompCtrlV3.h>


class Proc_ShortCompCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_ShortCompCtrlV3(void);

   virtual ~Proc_ShortCompCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiShortCompCtrlV3 Om_ShortCompCtrl;

};

#endif   //  _Proc_ShortCompCtrlV3_PARSING_PROCESSOR_INCLUDED_


