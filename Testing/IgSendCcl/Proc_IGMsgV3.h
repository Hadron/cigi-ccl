// Proc_IGMsgV3.h: Interface for the Proc_IGMsgV3 parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PROC_IGMSGV3_PARSING_PROCESSOR_INCLUDED_)
#define PROC_IGMSGV3_PARSING_PROCESSOR_INCLUDED_

#include "PcktParsingProcessor.h"
#include "CigiIGMsgV3.h"

class Proc_IGMsgV3 : public PcktParsingProcessor
{
public:
   Proc_IGMsgV3();
   virtual ~Proc_IGMsgV3();

   virtual void ProcPckt(ParseValue *pPV);

protected:
   CigiIGMsgV3 Om_IGMsgV3;

};

#endif   //  PROC_IGMSGV3_PARSING_PROCESSOR_INCLUDED_


