// Proc_RateCtrlV2.h: interface for the Proc_RateCtrlV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_RateCtrlV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_RateCtrlV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiRateCtrlV2.h>


class Proc_RateCtrlV2 : public PcktParsingProcessor
{
public:

   Proc_RateCtrlV2(void);

   virtual ~Proc_RateCtrlV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiRateCtrlV2 Om_RateCtrl;

};

#endif   //  _Proc_RateCtrlV2_PARSING_PROCESSOR_INCLUDED_


