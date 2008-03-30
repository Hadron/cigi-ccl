// Proc_RateCtrlV1.h: interface for the Proc_RateCtrlV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_RateCtrlV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_RateCtrlV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiRateCtrlV1.h>


class Proc_RateCtrlV1 : public PcktParsingProcessor
{
public:

   Proc_RateCtrlV1(void);

   virtual ~Proc_RateCtrlV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiRateCtrlV1 Om_RateCtrl;

};

#endif   //  _Proc_RateCtrlV1_PARSING_PROCESSOR_INCLUDED_


