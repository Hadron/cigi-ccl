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


#include "Proc_ArtPartCtrlV2.h"
#include "Proc_CollDetSegDefV2.h"
#include "Proc_CollDetVolDefV2.h"
#include "Proc_CompCtrlV2.h"
#include "Proc_EntityCtrlV2.h"
#include "Proc_SensorCtrlV2.h"
#include "Proc_TrajectoryV2.h"
#include "Proc_ViewCtrlV2.h"
#include "Proc_ViewDefV2.h"
#include "Proc_WeatherCtrlV2.h"
#include "Proc_RateCtrlV2.h"
#include "Proc_LosSegReqV2.h"
#include "Proc_LosVectReqV2.h"
#include "Proc_EnvCtrlV2.h"
#include "Proc_SpecialEffectV2.h"
#include "Proc_HatReqV2.h"
#include "Proc_HotReqV2.h"


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





void OutputProcessor2::Init(CigiHostSession *HostSnIn,
                            string &CsvFileNm,
                            int MajorVer,
                            int MinorVer)
{

   Parsers.push_back((PcktParsingProcessor *)(new Proc_ArtPartCtrlV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetSegDefV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetVolDefV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_CompCtrlV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_EntityCtrlV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_SensorCtrlV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_TrajectoryV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_ViewCtrlV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_ViewDefV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_WeatherCtrlV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_RateCtrlV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_LosSegReqV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_LosVectReqV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_EnvCtrlV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_SpecialEffectV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_HatReqV2));
   Parsers.push_back((PcktParsingProcessor *)(new Proc_HotReqV2));

   OutputProcessor::Init(HostSnIn, CsvFileNm, MajorVer, MinorVer);

}



