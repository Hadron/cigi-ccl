// Proc_HatReqV1.h: interface for the Proc_HatReqV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_HatReqV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_HatReqV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiHatReqV1.h>


class Proc_HatReqV1 : public PcktParsingProcessor
{
public:

   Proc_HatReqV1(void);

   virtual ~Proc_HatReqV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiHatReqV1 Om_HatReq;

};

#endif   //  _Proc_HatReqV1_PARSING_PROCESSOR_INCLUDED_


