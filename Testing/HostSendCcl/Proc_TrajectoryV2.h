// Proc_TrajectoryV2.h: interface for the Proc_TrajectoryV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_TrajectoryV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_TrajectoryV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiTrajectoryDefV2.h>


class Proc_TrajectoryV2 : public PcktParsingProcessor
{
public:

   Proc_TrajectoryV2(void);

   virtual ~Proc_TrajectoryV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiTrajectoryDefV2 Om_Trajectory;

};

#endif   //  _Proc_TrajectoryV2_PARSING_PROCESSOR_INCLUDED_


