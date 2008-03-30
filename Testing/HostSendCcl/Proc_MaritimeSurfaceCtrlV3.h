// Proc_MaritimeSurfaceCtrlV3.h: interface for the Proc_MaritimeSurfaceCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_MaritimeSurfaceCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_MaritimeSurfaceCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiMaritimeSurfaceCtrlV3.h>


class Proc_MaritimeSurfaceCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_MaritimeSurfaceCtrlV3(void);

   virtual ~Proc_MaritimeSurfaceCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiMaritimeSurfaceCtrlV3 Om_MaritimeSurfaceCtrl;

};

#endif   //  _Proc_MaritimeSurfaceCtrlV3_PARSING_PROCESSOR_INCLUDED_


