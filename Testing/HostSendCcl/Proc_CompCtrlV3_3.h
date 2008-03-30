// Proc_CompCtrlV3_3.h: interface for the Proc_CompCtrlV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CompCtrlV3_3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CompCtrlV3_3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCompCtrlV3_3.h>


class Proc_CompCtrlV3_3 : public PcktParsingProcessor
{
public:

   Proc_CompCtrlV3_3(void);

   virtual ~Proc_CompCtrlV3_3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCompCtrlV3_3 Om_CompCtrl;

};

#endif   //  _Proc_CompCtrlV3_3_PARSING_PROCESSOR_INCLUDED_


