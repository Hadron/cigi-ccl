// Proc_RateCtrlV3.h: interface for the Proc_RateCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_RateCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_RateCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiRateCtrlV3.h>


class Proc_RateCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_RateCtrlV3(void);

   virtual ~Proc_RateCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiRateCtrlV3 Om_RateCtrl;

};

#endif   //  _Proc_RateCtrlV3_PARSING_PROCESSOR_INCLUDED_


