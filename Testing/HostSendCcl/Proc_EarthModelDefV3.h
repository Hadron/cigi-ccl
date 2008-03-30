// Proc_EarthModelDefV3.h: interface for the Proc_EarthModelDefV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_EarthModelDefV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_EarthModelDefV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiEarthModelDefV3.h>


class Proc_EarthModelDefV3 : public PcktParsingProcessor
{
public:

   Proc_EarthModelDefV3(void);

   virtual ~Proc_EarthModelDefV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiEarthModelDefV3 Om_EarthModelDef;

};

#endif   //  _Proc_EarthModelDefV3_PARSING_PROCESSOR_INCLUDED_


