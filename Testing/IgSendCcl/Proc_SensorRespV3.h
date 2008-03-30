// Proc_SensorRespV3.h: Interface for the Proc_SensorRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_SENSORRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_SENSORRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiSensorRespV3.h"

class Proc_SensorRespV3 : public PcktParsingProcessor
{
public:
   Proc_SensorRespV3();
   virtual ~Proc_SensorRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiSensorRespV3 Om_SensorRespV3;

};

#endif   //  PROC_SENSORRESPV3_PARSING_PROCESSOR_INCLUDED_


