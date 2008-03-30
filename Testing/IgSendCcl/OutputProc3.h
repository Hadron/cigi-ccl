// OutputProcessor3.h: interface for the OutputProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_OUTPUT_PROCESSOR_3_INCLUDED_)
#define _OUTPUT_PROCESSOR_3_INCLUDED_


#include "OutputProc.h"


class OutputProcessor3 : public OutputProcessor
{
public:
	OutputProcessor3();
	virtual ~OutputProcessor3();

   virtual void Init(CigiSession *CrntSessionIn,
                     string &CsvFileNm,
                     int MajorVer,
                     int MinorVer);

};

#endif // !defined(_OUTPUT_PROCESSOR_3_INCLUDED_)

