// OutputProcessor1.cpp: implementation of the OutputProcessor1 class.
//
//////////////////////////////////////////////////////////////////////


#include "StdAfx.h"


#ifndef _WIN32
    #include <fstream>
#elif _MSC_VER > 1300
    #include <fstream>
#else
    #include <fstream.h>
#endif


#include "PcktParsingProcessor.h"
#include "ParseLine.h"
#include "ParseValue.h"

#include "OutputProc1.h"

#include "Proc_HatRespV1.h"
#include "Proc_LosRespV1.h"
#include "Proc_CollDetSegRespV1.h"
#include "Proc_SensorRespV1.h"



using namespace std;



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


OutputProcessor1::OutputProcessor1()
{

}




OutputProcessor1::~OutputProcessor1()
{

}





void OutputProcessor1::Init(CigiSession *CrntSessionIn,
                            string &CsvFileNm,
                            int MajorVer,
                            int MinorVer)
{

   Parsers.push_back((PcktParsingProcessor *)(new Proc_HatRespV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_LosRespV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetSegRespV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_SensorRespV1));

   OutputProcessor::Init(CrntSessionIn, CsvFileNm, MajorVer, MinorVer);

}



