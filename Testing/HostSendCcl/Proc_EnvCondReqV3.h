// Proc_EnvCondReqV3.h: interface for the Proc_EnvCondReqV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_EnvCondReqV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_EnvCondReqV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiEnvCondReqV3.h>


class Proc_EnvCondReqV3 : public PcktParsingProcessor
{
public:

   Proc_EnvCondReqV3(void);

   virtual ~Proc_EnvCondReqV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiEnvCondReqV3 Om_EnvCondReq;

};

#endif   //  _Proc_EnvCondReqV3_PARSING_PROCESSOR_INCLUDED_


