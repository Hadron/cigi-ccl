// Proc_TrajectoryV3.h: interface for the Proc_TrajectoryV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_TrajectoryV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_TrajectoryV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiTrajectoryDefV3.h>


class Proc_TrajectoryV3 : public PcktParsingProcessor
{
public:

   Proc_TrajectoryV3(void);

   virtual ~Proc_TrajectoryV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiTrajectoryDefV3 Om_Trajectory;

};

#endif   //  _Proc_TrajectoryV3_PARSING_PROCESSOR_INCLUDED_


