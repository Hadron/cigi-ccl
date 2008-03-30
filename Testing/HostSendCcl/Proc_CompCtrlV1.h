// Proc_CompCtrlV1.h: interface for the Proc_CompCtrlV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CompCtrlV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CompCtrlV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCompCtrlV1.h>


class Proc_CompCtrlV1 : public PcktParsingProcessor
{
public:

   Proc_CompCtrlV1(void);

   virtual ~Proc_CompCtrlV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCompCtrlV1 Om_CompCtrl;

};

#endif   //  _Proc_CompCtrlV1_PARSING_PROCESSOR_INCLUDED_


