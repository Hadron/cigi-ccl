// Proc_HatHotReqV3_2.h: interface for the Proc_HatHotReqV3_2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_HatHotReqV3_2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_HatHotReqV3_2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiHatHotReqV3_2.h>


class Proc_HatHotReqV3_2 : public PcktParsingProcessor
{
public:

   Proc_HatHotReqV3_2(void);

   virtual ~Proc_HatHotReqV3_2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiHatHotReqV3_2 Om_HatHotReq;

};

#endif   //  _Proc_HatHotReqV3_2_PARSING_PROCESSOR_INCLUDED_


