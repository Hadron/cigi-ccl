// Proc_EntityCtrlV1.h: interface for the Proc_EntityCtrlV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_EntityCtrlV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_EntityCtrlV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiEntityCtrlV1.h>


class Proc_EntityCtrlV1 : public PcktParsingProcessor
{
public:

   Proc_EntityCtrlV1(void);

   virtual ~Proc_EntityCtrlV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiEntityCtrlV1 Om_EntityCtrl;

};

#endif   //  _Proc_EntityCtrlV1_PARSING_PROCESSOR_INCLUDED_


