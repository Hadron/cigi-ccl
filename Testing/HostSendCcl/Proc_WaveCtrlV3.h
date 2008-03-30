// Proc_WaveCtrlV3.h: interface for the Proc_WaveCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_WaveCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_WaveCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiWaveCtrlV3.h>


class Proc_WaveCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_WaveCtrlV3(void);

   virtual ~Proc_WaveCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiWaveCtrlV3 Om_WaveCtrl;

};

#endif   //  _Proc_WaveCtrlV3_PARSING_PROCESSOR_INCLUDED_


