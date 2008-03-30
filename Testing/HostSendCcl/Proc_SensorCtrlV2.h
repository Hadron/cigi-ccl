// Proc_SensorCtrlV2.h: interface for the Proc_SensorCtrlV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_SensorCtrlV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_SensorCtrlV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiSensorCtrlV2.h>


class Proc_SensorCtrlV2 : public PcktParsingProcessor
{
public:

   Proc_SensorCtrlV2(void);

   virtual ~Proc_SensorCtrlV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiSensorCtrlV2 Om_SensorCtrl;

};

#endif   //  _Proc_SensorCtrlV2_PARSING_PROCESSOR_INCLUDED_


