// Proc_LosSegReqV3_2.h: interface for the Proc_LosSegReqV3_2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_LosSegReqV3_2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_LosSegReqV3_2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiLosSegReqV3_2.h>


class Proc_LosSegReqV3_2 : public PcktParsingProcessor
{
public:

   Proc_LosSegReqV3_2(void);

   virtual ~Proc_LosSegReqV3_2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiLosSegReqV3_2 Om_LosSegReq;

};

#endif   //  _Proc_LosSegReqV3_2_PARSING_PROCESSOR_INCLUDED_


