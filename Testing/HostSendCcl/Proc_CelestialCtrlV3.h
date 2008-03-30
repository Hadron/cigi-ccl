// Proc_CelestialCtrlV3.h: interface for the Proc_CelestialCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_CelestialCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_CelestialCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiCelestialCtrl.h>


class Proc_CelestialCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_CelestialCtrlV3(void);

   virtual ~Proc_CelestialCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiCelestialCtrlV3 Om_CelestialCtrl;

};

#endif   //  _Proc_CelestialCtrlV3_PARSING_PROCESSOR_INCLUDED_


