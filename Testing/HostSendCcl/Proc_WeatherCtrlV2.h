// Proc_WeatherCtrlV2.h: interface for the Proc_WeatherCtrlV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_WeatherCtrlV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_WeatherCtrlV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiWeatherCtrlV2.h>


class Proc_WeatherCtrlV2 : public PcktParsingProcessor
{
public:

   Proc_WeatherCtrlV2(void);

   virtual ~Proc_WeatherCtrlV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiWeatherCtrlV2 Om_WeatherCtrl;

};

#endif   //  _Proc_WeatherCtrlV2_PARSING_PROCESSOR_INCLUDED_


