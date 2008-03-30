// Proc_SensorRespV1.h: Interface for the Proc_SensorRespV1 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_SENSORRESPV1_PARSING_PROCESSOR_INCLUDED_)
#define PROC_SENSORRESPV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiSensorRespV1.h"

class Proc_SensorRespV1 : public PcktParsingProcessor
{
public:
   Proc_SensorRespV1();
   virtual ~Proc_SensorRespV1();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiSensorRespV1 Om_SensorRespV1;

};

#endif   //  PROC_SENSORRESPV1_PARSING_PROCESSOR_INCLUDED_


