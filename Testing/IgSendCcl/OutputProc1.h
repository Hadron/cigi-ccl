// OutputProcessor1.h: interface for the OutputProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_OUTPUT_PROCESSOR_1_INCLUDED_)
#define _OUTPUT_PROCESSOR_1_INCLUDED_


#include "OutputProc.h"


class OutputProcessor1 : public OutputProcessor
{
public:
	OutputProcessor1();
	virtual ~OutputProcessor1();

   virtual void Init(CigiSession *CrntSessionIn,
                     string &CsvFileNm,
                     int MajorVer,
                     int MinorVer);

};

#endif // !defined(_OUTPUT_PROCESSOR_1_INCLUDED_)

