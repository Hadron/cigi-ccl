// Proc_LosSegReqV1.h: interface for the Proc_LosSegReqV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_LosSegReqV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_LosSegReqV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiLosSegReqV1.h>


class Proc_LosSegReqV1 : public PcktParsingProcessor
{
public:

   Proc_LosSegReqV1(void);

   virtual ~Proc_LosSegReqV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiLosSegReqV1 Om_LosSegReq;

};

#endif   //  _Proc_LosSegReqV1_PARSING_PROCESSOR_INCLUDED_


