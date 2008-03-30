// Proc_RateCtrlV3_2.h: interface for the Proc_RateCtrlV3_2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_RateCtrlV3_2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_RateCtrlV3_2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiRateCtrlV3_2.h>


class Proc_RateCtrlV3_2 : public PcktParsingProcessor
{
public:

   Proc_RateCtrlV3_2(void);

   virtual ~Proc_RateCtrlV3_2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiRateCtrlV3_2 Om_RateCtrl;

};

#endif   //  _Proc_RateCtrlV3_2_PARSING_PROCESSOR_INCLUDED_


