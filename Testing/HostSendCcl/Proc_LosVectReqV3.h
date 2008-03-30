// Proc_LosVectReqV3.h: interface for the Proc_LosVectReqV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_LosVectReqV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_LosVectReqV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiLosVectReqV3.h>


class Proc_LosVectReqV3 : public PcktParsingProcessor
{
public:

   Proc_LosVectReqV3(void);

   virtual ~Proc_LosVectReqV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiLosVectReqV3 Om_LosVectReq;

};

#endif   //  _Proc_LosVectReqV3_PARSING_PROCESSOR_INCLUDED_


