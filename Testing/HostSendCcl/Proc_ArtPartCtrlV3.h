// Proc_ArtPartCtrlV3.h: interface for the Proc_ArtPartCtrlV3 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ArtPartCtrlV3_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ArtPartCtrlV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiArtPartCtrlV3.h>


class Proc_ArtPartCtrlV3 : public PcktParsingProcessor
{
public:

   Proc_ArtPartCtrlV3(void);

   virtual ~Proc_ArtPartCtrlV3(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiArtPartCtrlV3 Om_ArtPartCtrl;

};

#endif   //  _Proc_ArtPartCtrlV3_PARSING_PROCESSOR_INCLUDED_


