// Proc_ShortArtPartCtrlV3.h: interface for the Proc_ShortArtPartCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ShortArtPartCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ShortArtPartCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiShortArtPartCtrlV3.h>


class Proc_ShortArtPartCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_ShortArtPartCtrlV3(void);

   virtual ~Proc_ShortArtPartCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiShortArtPartCtrlV3 Om_ShortArtPartCtrl;

};

#endif   //  _Proc_ShortArtPartCtrlV3_PARSING_PROCESSOR_INCLUDED_


