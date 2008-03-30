// Proc_TerrestrialSurfaceCtrlV3.h: interface for the Proc_TerrestrialSurfaceCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_TerrestrialSurfaceCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_TerrestrialSurfaceCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiTerrestrialSurfaceCtrlV3.h>


class Proc_TerrestrialSurfaceCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_TerrestrialSurfaceCtrlV3(void);

   virtual ~Proc_TerrestrialSurfaceCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiTerrestrialSurfaceCtrlV3 Om_TerrestrialSurfaceCtrl;

};

#endif   //  _Proc_TerrestrialSurfaceCtrlV3_PARSING_PROCESSOR_INCLUDED_


