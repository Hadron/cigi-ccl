// Proc_LosVectReqV1.h: interface for the Proc_LosVectReqV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_LosVectReqV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_LosVectReqV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiLosVectReqV1.h>


class Proc_LosVectReqV1 : public PcktParsingProcessor
{
public:

   Proc_LosVectReqV1(void);

   virtual ~Proc_LosVectReqV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiLosVectReqV1 Om_LosVectReq;

};

#endif   //  _Proc_LosVectReqV1_PARSING_PROCESSOR_INCLUDED_


