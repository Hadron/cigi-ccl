// Proc_WeatherCtrlV1.h: interface for the Proc_WeatherCtrlV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_WeatherCtrlV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_WeatherCtrlV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiWeatherCtrlV1.h>


class Proc_WeatherCtrlV1 : public PcktParsingProcessor
{
public:

   Proc_WeatherCtrlV1(void);

   virtual ~Proc_WeatherCtrlV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiWeatherCtrlV1 Om_WeatherCtrl;

};

#endif   //  _Proc_WeatherCtrlV1_PARSING_PROCESSOR_INCLUDED_


