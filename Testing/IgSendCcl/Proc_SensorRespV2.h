// Proc_SensorRespV2.h: Interface for the Proc_SensorRespV2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_SENSORRESPV2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_SENSORRESPV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiSensorRespV2.h"

class Proc_SensorRespV2 : public PcktParsingProcessor
{
public:
   Proc_SensorRespV2();
   virtual ~Proc_SensorRespV2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiSensorRespV2 Om_SensorRespV2;

};

#endif   //  PROC_SENSORRESPV2_PARSING_PROCESSOR_INCLUDED_


