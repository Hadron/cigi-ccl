// Proc_ViewDefV3.h: interface for the Proc_ViewDefV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ViewDefV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ViewDefV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiViewDefV3.h>


class Proc_ViewDefV3 : public PcktParsingProcessor
{
public:

   Proc_ViewDefV3(void);

   virtual ~Proc_ViewDefV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiViewDefV3 Om_ViewDef;

};

#endif   //  _Proc_ViewDefV3_PARSING_PROCESSOR_INCLUDED_


