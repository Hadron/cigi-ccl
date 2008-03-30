// Proc_EnvCtrlV2.h: interface for the Proc_EnvCtrlV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_EnvCtrlV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_EnvCtrlV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiEnvCtrlV2.h>


class Proc_EnvCtrlV2 : public PcktParsingProcessor
{
public:

   Proc_EnvCtrlV2(void);

   virtual ~Proc_EnvCtrlV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiEnvCtrlV2 Om_EnvCtrl;

};

#endif   //  _Proc_EnvCtrlV2_PARSING_PROCESSOR_INCLUDED_


