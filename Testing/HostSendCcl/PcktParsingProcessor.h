// PcktParsingProcessor.h: interface for the Packet Parsing
//   Processor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_PACKET_PARSING_PROCESSOR_INCLUDED_)
#define _PACKET_PARSING_PROCESSOR_INCLUDED_


#include "AllCigi.h"

#include <string>

class ParseValue;


class PcktParsingProcessor
{
public:

   PcktParsingProcessor(void)
   {
      Omsg = NULL;
   }

   virtual ~PcktParsingProcessor(void)
   {
   }

   std::string * GetPcktID(void)
   {
      return(&PcktID);
   }

   void Init(CigiOutgoingMsg *OmsgIn)
   {
      Omsg = OmsgIn;
   }

   virtual void ProcPckt(ParseValue *pPV) = 0;


protected:

   std::string PcktID;
   CigiOutgoingMsg *Omsg;
   char *DefHex;

};


#endif   //  _PACKET_PARSING_PROCESSOR_INCLUDED_

