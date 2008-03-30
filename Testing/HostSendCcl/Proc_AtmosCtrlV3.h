// Proc_AtmosCtrlV3.h: interface for the Proc_AtmosCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_AtmosCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_AtmosCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiAtmosCtrl.h>


class Proc_AtmosCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_AtmosCtrlV3(void);

   virtual ~Proc_AtmosCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiAtmosCtrlV3 Om_AtmosCtrl;

};

#endif   //  _Proc_AtmosCtrlV3_PARSING_PROCESSOR_INCLUDED_


