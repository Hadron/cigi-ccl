// Proc_ViewDefV2.h: interface for the Proc_ViewDefV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ViewDefV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ViewDefV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiViewDefV2.h>


class Proc_ViewDefV2 : public PcktParsingProcessor
{
public:

   Proc_ViewDefV2(void);

   virtual ~Proc_ViewDefV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiViewDefV2 Om_ViewDef;

};

#endif   //  _Proc_ViewDefV2_PARSING_PROCESSOR_INCLUDED_


