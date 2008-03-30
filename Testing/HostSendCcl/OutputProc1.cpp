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


#include "Proc_ArtPartCtrlV1.h"
#include "Proc_CollDetSegDefV1.h"
#include "Proc_CompCtrlV1.h"
#include "Proc_EntityCtrlV1.h"
#include "Proc_SensorCtrlV1.h"
#include "Proc_TrajectoryV1.h"
#include "Proc_ViewCtrlV1.h"
#include "Proc_ViewDefV1.h"
#include "Proc_WeatherCtrlV1.h"
#include "Proc_RateCtrlV1.h"
#include "Proc_LosSegReqV1.h"
#include "Proc_LosVectReqV1.h"
#include "Proc_EnvCtrlV1.h"
#include "Proc_SpecialEffectV1.h"
#include "Proc_HatReqV1.h"


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





void OutputProcessor1::Init(CigiHostSession *HostSnIn,
                            string &CsvFileNm,
                            int MajorVer,
                            int MinorVer)
{

   Parsers.push_back((PcktParsingProcessor *)(new Proc_ArtPartCtrlV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetSegDefV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_CompCtrlV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_EntityCtrlV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_SensorCtrlV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_TrajectoryV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_ViewCtrlV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_ViewDefV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_WeatherCtrlV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_RateCtrlV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_LosSegReqV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_LosVectReqV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_EnvCtrlV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_SpecialEffectV1));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_HatReqV1));

   OutputProcessor::Init(HostSnIn, CsvFileNm, MajorVer, MinorVer);

}



