// Proc_SensorXRespV3.h: Interface for the Proc_SensorXRespV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_SENSORXRESPV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_SENSORXRESPV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiSensorXRespV3.h"

class Proc_SensorXRespV3 : public PcktParsingProcessor
{
public:
   Proc_SensorXRespV3();
   virtual ~Proc_SensorXRespV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiSensorXRespV3 Om_SensorXRespV3;

};

#endif   //  PROC_SENSORXRESPV3_PARSING_PROCESSOR_INCLUDED_


