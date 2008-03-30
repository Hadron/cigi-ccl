// OutputProcessor2.cpp: implementation of the OutputProcessor2 class.
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

#include "OutputProc2.h"



#include "Proc_HatRespV2.h"
#include "Proc_LosRespV2.h"
#include "Proc_CollDetSegRespV2.h"
#include "Proc_SensorRespV2.h"
#include "Proc_HotRespV2.h"
#include "Proc_CollDetVolRespV2.h"
#include "Proc_IGMsgV2.h"


using namespace std;



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


OutputProcessor2::OutputProcessor2()
{

}




OutputProcessor2::~OutputProcessor2()
{

}





void OutputProcessor2::Init(CigiSession *CrntSessionIn,
                            string &CsvFileNm,
                            int MajorVer,
                            int MinorVer)
{

   Parsers.push_back((PcktParsingProcessor *)(new Proc_HatRespV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_LosRespV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetSegRespV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_SensorRespV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_HotRespV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetVolRespV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_IGMsgV2));


   OutputProcessor::Init(CrntSessionIn, CsvFileNm, MajorVer, MinorVer);

}



