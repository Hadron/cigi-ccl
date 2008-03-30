// Proc_HotReqV2.h: interface for the Proc_HotReqV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_HotReqV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_HotReqV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiHotReqV2.h>


class Proc_HotReqV2 : public PcktParsingProcessor
{
public:

   Proc_HotReqV2(void);

   virtual ~Proc_HotReqV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiHotReqV2 Om_HotReq;

};

#endif   //  _Proc_HotReqV2_PARSING_PROCESSOR_INCLUDED_


