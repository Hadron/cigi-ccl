// Proc_LosSegReqV2.h: interface for the Proc_LosSegReqV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_LosSegReqV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_LosSegReqV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiLosSegReqV2.h>


class Proc_LosSegReqV2 : public PcktParsingProcessor
{
public:

   Proc_LosSegReqV2(void);

   virtual ~Proc_LosSegReqV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiLosSegReqV2 Om_LosSegReq;

};

#endif   //  _Proc_LosSegReqV2_PARSING_PROCESSOR_INCLUDED_


