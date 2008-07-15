// Proc_EntityCtrlV3_3.h: interface for the Proc_EntityCtrlV3_3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_EntityCtrlV3_3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_EntityCtrlV3_3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiEntityCtrlV3_3.h>


class Proc_EntityCtrlV3_3 : public PcktParsingProcessor
{
public:

   Proc_EntityCtrlV3_3(void);

   virtual ~Proc_EntityCtrlV3_3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiEntityCtrlV3_3 Om_EntityCtrl;

};

#endif   //  _Proc_EntityCtrlV3_3_PARSING_PROCESSOR_INCLUDED_


