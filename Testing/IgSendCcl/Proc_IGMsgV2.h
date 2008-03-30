// Proc_IGMsgV2.h: Interface for the Proc_IGMsgV2 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_IGMSGV2_PARSING_PROCESSOR_INCLUDED_)
#define PROC_IGMSGV2_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiIGMsgV2.h"

class Proc_IGMsgV2 : public PcktParsingProcessor
{
public:
   Proc_IGMsgV2();
   virtual ~Proc_IGMsgV2();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiIGMsgV2 Om_IGMsgV2;

};

#endif   //  PROC_IGMSGV2_PARSING_PROCESSOR_INCLUDED_


