// Proc_SensorCtrlV3.h: interface for the Proc_SensorCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SensorCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SensorCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSensorCtrlV3.h>


class Proc_SensorCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_SensorCtrlV3(void);

   virtual ~Proc_SensorCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSensorCtrlV3 Om_SensorCtrl;

};

#endif   //  _Proc_SensorCtrlV3_PARSING_PROCESSOR_INCLUDED_


