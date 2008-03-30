// Proc_ViewCtrlV3.h: interface for the Proc_ViewCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ViewCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ViewCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiViewCtrlV3.h>


class Proc_ViewCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_ViewCtrlV3(void);

   virtual ~Proc_ViewCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiViewCtrlV3 Om_ViewCtrl;

};

#endif   //  _Proc_ViewCtrlV3_PARSING_PROCESSOR_INCLUDED_


