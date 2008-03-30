// Proc_EnvRgnCtrlV3.h: interface for the Proc_EnvRgnCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_EnvRgnCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_EnvRgnCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiEnvRgnCtrlV3.h>


class Proc_EnvRgnCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_EnvRgnCtrlV3(void);

   virtual ~Proc_EnvRgnCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiEnvRgnCtrlV3 Om_EnvRgnCtrl;

};

#endif   //  _Proc_EnvRgnCtrlV3_PARSING_PROCESSOR_INCLUDED_


