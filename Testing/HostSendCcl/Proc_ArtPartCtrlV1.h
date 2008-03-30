// Proc_ArtPartCtrlV1.h: interface for the Proc_ArtPartCtrlV1 Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_Proc_ArtPartCtrlV1_PARSING_PROCESSOR_INCLUDED_)
#define _Proc_ArtPartCtrlV1_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"

#include <CigiArtPartCtrlV1.h>


class Proc_ArtPartCtrlV1 : public PcktParsingProcessor
{
public:

   Proc_ArtPartCtrlV1(void);

   virtual ~Proc_ArtPartCtrlV1(void);

   virtual void ProcPckt(ParseValue *pPV);


protected:

   CigiArtPartCtrlV1 Om_ArtPartCtrl;

};

#endif   //  _Proc_ArtPartCtrlV1_PARSING_PROCESSOR_INCLUDED_


