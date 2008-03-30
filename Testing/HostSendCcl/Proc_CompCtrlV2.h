// Proc_CompCtrlV2.h: interface for the Proc_CompCtrlV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CompCtrlV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CompCtrlV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCompCtrlV2.h>


class Proc_CompCtrlV2 : public PcktParsingProcessor
{
public:

   Proc_CompCtrlV2(void);

   virtual ~Proc_CompCtrlV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCompCtrlV2 Om_CompCtrl;

};

#endif   //  _Proc_CompCtrlV2_PARSING_PROCESSOR_INCLUDED_


