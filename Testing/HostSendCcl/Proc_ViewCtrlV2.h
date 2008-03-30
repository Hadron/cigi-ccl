// Proc_ViewCtrlV2.h: interface for the Proc_ViewCtrlV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ViewCtrlV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ViewCtrlV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiViewCtrlV2.h>


class Proc_ViewCtrlV2 : public PcktParsingProcessor
{
public:

   Proc_ViewCtrlV2(void);

   virtual ~Proc_ViewCtrlV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiViewCtrlV2 Om_ViewCtrl;

};

#endif   //  _Proc_ViewCtrlV2_PARSING_PROCESSOR_INCLUDED_


