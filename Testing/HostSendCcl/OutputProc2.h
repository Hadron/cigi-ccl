// OutputProcessor2.h: interface for the OutputProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_OUTPUT_PROCESSOR_2_INCLUDED_)
#define _OUTPUT_PROCESSOR_2_INCLUDED_


#include "OutputProc.h"


class OutputProcessor2 : public OutputProcessor
{
public:
	OutputProcessor2();
	virtual ~OutputProcessor2();

   virtual void Init(CigiHostSession *HostSnIn,
                     string &CsvFileNm,
                     int MajorVer,
                     int MinorVer);

};

#endif // !defined(_OUTPUT_PROCESSOR_2_INCLUDED_)

