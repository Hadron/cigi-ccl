// Proc_ViewDefV1.h: interface for the Proc_ViewDefV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ViewDefV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ViewDefV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiViewDefV1.h>


class Proc_ViewDefV1 : public PcktParsingProcessor
{
public:

   Proc_ViewDefV1(void);

   virtual ~Proc_ViewDefV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiViewDefV1 Om_ViewDef;

};

#endif   //  _Proc_ViewDefV1_PARSING_PROCESSOR_INCLUDED_


