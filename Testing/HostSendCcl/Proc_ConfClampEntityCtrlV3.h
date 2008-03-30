// Proc_ConfClampEntityCtrlV3.h: interface for the Proc_ConfClampEntityCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ConfClampEntityCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ConfClampEntityCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiConfClampEntityCtrlV3.h>


class Proc_ConfClampEntityCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_ConfClampEntityCtrlV3(void);

   virtual ~Proc_ConfClampEntityCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiConfClampEntityCtrlV3 Om_ConfClampEntityCtrl;

};

#endif   //  _Proc_ConfClampEntityCtrlV3_PARSING_PROCESSOR_INCLUDED_


