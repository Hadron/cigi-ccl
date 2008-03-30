// Proc_ArtPartCtrlV2.h: interface for the Proc_ArtPartCtrlV2 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ArtPartCtrlV2_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ArtPartCtrlV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiArtPartCtrlV2.h>


class Proc_ArtPartCtrlV2 : public PcktParsingProcessor
{
public:

   Proc_ArtPartCtrlV2(void);

   virtual ~Proc_ArtPartCtrlV2(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiArtPartCtrlV2 Om_ArtPartCtrl;

};

#endif   //  _Proc_ArtPartCtrlV2_PARSING_PROCESSOR_INCLUDED_


