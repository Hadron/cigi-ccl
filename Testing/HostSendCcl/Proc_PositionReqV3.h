// Proc_PositionReqV3.h: interface for the Proc_PositionReqV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_PositionReqV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_PositionReqV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiPositionReqV3.h>


class Proc_PositionReqV3 : public PcktParsingProcessor
{
public:

   Proc_PositionReqV3(void);

   virtual ~Proc_PositionReqV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiPositionReqV3 Om_PositionReq;

};

#endif   //  _Proc_PositionReqV3_PARSING_PROCESSOR_INCLUDED_


