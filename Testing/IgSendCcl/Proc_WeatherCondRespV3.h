// Proc_WeatherCondRespV3.h: Interface for the Proc_WeatherCondRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_WEATHERCONDRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_WEATHERCONDRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiWeatherCondRespV3.h"

class Proc_WeatherCondRespV3 : public PcktParsingProcessor
{
public:
   Proc_WeatherCondRespV3();
   virtual ~Proc_WeatherCondRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiWeatherCondRespV3 Om_WeatherCondRespV3;

};

#endif   //  PROC_WEATHERCONDRESPV3_PARSING_PROCESSOR_INCLUDED_


