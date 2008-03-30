// Proc_ViewCtrlV1.h: interface for the Proc_ViewCtrlV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ViewCtrlV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ViewCtrlV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiViewCtrlV1.h>


class Proc_ViewCtrlV1 : public PcktParsingProcessor
{
public:

   Proc_ViewCtrlV1(void);

   virtual ~Proc_ViewCtrlV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiViewCtrlV1 Om_ViewCtrl;

};

#endif   //  _Proc_ViewCtrlV1_PARSING_PROCESSOR_INCLUDED_


