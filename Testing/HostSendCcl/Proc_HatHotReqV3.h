// Proc_HatHotReqV3.h: interface for the Proc_HatHotReqV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_HatHotReqV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_HatHotReqV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiHatHotReqV3.h>


class Proc_HatHotReqV3 : public PcktParsingProcessor
{
public:

   Proc_HatHotReqV3(void);

   virtual ~Proc_HatHotReqV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiHatHotReqV3 Om_HatHotReq;

};

#endif   //  _Proc_HatHotReqV3_PARSING_PROCESSOR_INCLUDED_


