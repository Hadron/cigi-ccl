// Proc_CompCtrlV3.h: interface for the Proc_CompCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CompCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CompCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCompCtrlV3.h>


class Proc_CompCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_CompCtrlV3(void);

   virtual ~Proc_CompCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCompCtrlV3 Om_CompCtrl;

};

#endif   //  _Proc_CompCtrlV3_PARSING_PROCESSOR_INCLUDED_


