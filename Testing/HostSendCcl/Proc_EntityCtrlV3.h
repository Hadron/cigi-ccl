// Proc_EntityCtrlV3.h: interface for the Proc_EntityCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_EntityCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_EntityCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiEntityCtrlV3.h>


class Proc_EntityCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_EntityCtrlV3(void);

   virtual ~Proc_EntityCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiEntityCtrlV3 Om_EntityCtrl;

};

#endif   //  _Proc_EntityCtrlV3_PARSING_PROCESSOR_INCLUDED_


