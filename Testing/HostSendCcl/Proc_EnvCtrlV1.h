// Proc_EnvCtrlV1.h: interface for the Proc_EnvCtrlV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_EnvCtrlV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_EnvCtrlV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiEnvCtrlV1.h>


class Proc_EnvCtrlV1 : public PcktParsingProcessor
{
public:

   Proc_EnvCtrlV1(void);

   virtual ~Proc_EnvCtrlV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiEnvCtrlV1 Om_EnvCtrl;

};

#endif   //  _Proc_EnvCtrlV1_PARSING_PROCESSOR_INCLUDED_


