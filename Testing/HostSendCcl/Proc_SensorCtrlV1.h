// Proc_SensorCtrlV1.h: interface for the Proc_SensorCtrlV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SensorCtrlV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SensorCtrlV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSensorCtrlV1.h>


class Proc_SensorCtrlV1 : public PcktParsingProcessor
{
public:

   Proc_SensorCtrlV1(void);

   virtual ~Proc_SensorCtrlV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSensorCtrlV1 Om_SensorCtrl;

};

#endif   //  _Proc_SensorCtrlV1_PARSING_PROCESSOR_INCLUDED_


