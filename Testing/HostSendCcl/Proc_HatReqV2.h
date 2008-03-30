// Proc_HatReqV2.h: interface for the Proc_HatReqV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_HatReqV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_HatReqV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiHatReqV2.h>


class Proc_HatReqV2 : public PcktParsingProcessor
{
public:

   Proc_HatReqV2(void);

   virtual ~Proc_HatReqV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiHatReqV2 Om_HatReq;

};

#endif   //  _Proc_HatReqV2_PARSING_PROCESSOR_INCLUDED_


