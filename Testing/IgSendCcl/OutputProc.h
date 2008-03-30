// OutputProcessor.h: interface for the OutputProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_OUTPUT_PROCESSOR_INCLUDED_)
#define _OUTPUT_PROCESSOR_INCLUDED_


#include "AllCigi.h"

#include <string>
#include <list>

class PcktParsingProcessor;
class ParseLine;
class ParseValue;


class OutputProcessor  
{
public:
   OutputProcessor();
   virtual ~OutputProcessor();


   virtual void Init(CigiSession *CrntSessionIn,
                     string &CsvFileNm,
                     int MajorVer,
                     int MinorVer);
	bool Out(void);
	void ProcLine(ParseLine &PrsLn);



protected:

   CigiSession *CrntSession;
   CigiOutgoingMsg *OmsgPtr;

   std::string CsvFile;

   std::list<PcktParsingProcessor *> Parsers;

   ParseLine *HPrsLn;

   char line[512];

   int TstID;


};

#endif // !defined(_OUTPUT_PROCESSOR_INCLUDED_)
