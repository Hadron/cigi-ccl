// Proc_EntityCtrlV2.h: interface for the Proc_EntityCtrlV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_EntityCtrlV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_EntityCtrlV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiEntityCtrlV2.h>


class Proc_EntityCtrlV2 : public PcktParsingProcessor
{
public:

   Proc_EntityCtrlV2(void);

   virtual ~Proc_EntityCtrlV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiEntityCtrlV2 Om_EntityCtrl;

};

#endif   //  _Proc_EntityCtrlV2_PARSING_PROCESSOR_INCLUDED_


