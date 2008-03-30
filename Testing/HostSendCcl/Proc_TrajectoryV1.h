// Proc_TrajectoryV1.h: interface for the Proc_TrajectoryV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_TrajectoryV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_TrajectoryV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiTrajectoryDefV1.h>


class Proc_TrajectoryV1 : public PcktParsingProcessor
{
public:

   Proc_TrajectoryV1(void);

   virtual ~Proc_TrajectoryV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiTrajectoryDefV1 Om_Trajectory;

};

#endif   //  _Proc_TrajectoryV1_PARSING_PROCESSOR_INCLUDED_


