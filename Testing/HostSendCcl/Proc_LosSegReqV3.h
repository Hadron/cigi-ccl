// Proc_LosSegReqV3.h: interface for the Proc_LosSegReqV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_LosSegReqV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_LosSegReqV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiLosSegReqV3.h>


class Proc_LosSegReqV3 : public PcktParsingProcessor
{
public:

   Proc_LosSegReqV3(void);

   virtual ~Proc_LosSegReqV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiLosSegReqV3 Om_LosSegReq;

};

#endif   //  _Proc_LosSegReqV3_PARSING_PROCESSOR_INCLUDED_


