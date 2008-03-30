// Proc_LosVectReqV2.h: interface for the Proc_LosVectReqV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_LosVectReqV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_LosVectReqV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiLosVectReqV2.h>


class Proc_LosVectReqV2 : public PcktParsingProcessor
{
public:

   Proc_LosVectReqV2(void);

   virtual ~Proc_LosVectReqV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiLosVectReqV2 Om_LosVectReq;

};

#endif   //  _Proc_LosVectReqV2_PARSING_PROCESSOR_INCLUDED_


