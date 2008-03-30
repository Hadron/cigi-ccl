// Proc_LosVectReqV3_2.h: interface for the Proc_LosVectReqV3_2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_LosVectReqV3_2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_LosVectReqV3_2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiLosVectReqV3_2.h>


class Proc_LosVectReqV3_2 : public PcktParsingProcessor
{
public:

   Proc_LosVectReqV3_2(void);

   virtual ~Proc_LosVectReqV3_2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiLosVectReqV3_2 Om_LosVectReq;

};

#endif   //  _Proc_LosVectReqV3_2_PARSING_PROCESSOR_INCLUDED_


