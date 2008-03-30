// Proc_WeatherCtrlV3.h: interface for the Proc_WeatherCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_WeatherCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_WeatherCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiWeatherCtrlV3.h>


class Proc_WeatherCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_WeatherCtrlV3(void);

   virtual ~Proc_WeatherCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiWeatherCtrlV3 Om_WeatherCtrl;

};

#endif   //  _Proc_WeatherCtrlV3_PARSING_PROCESSOR_INCLUDED_


