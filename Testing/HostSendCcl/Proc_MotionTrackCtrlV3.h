// Proc_MotionTrackCtrlV3.h: interface for the Proc_MotionTrackCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_MotionTrackCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_MotionTrackCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiMotionTrackCtrlV3.h>


class Proc_MotionTrackCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_MotionTrackCtrlV3(void);

   virtual ~Proc_MotionTrackCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiMotionTrackCtrlV3 Om_MotionTrackCtrl;

};

#endif   //  _Proc_MotionTrackCtrlV3_PARSING_PROCESSOR_INCLUDED_


