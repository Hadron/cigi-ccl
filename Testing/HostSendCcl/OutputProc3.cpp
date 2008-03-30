// OutputProcessor3.cpp: implementation of the OutputProcessor3 class.
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

#include "OutputProc3.h"


#include "Proc_ArtPartCtrlV3.h"
#include "Proc_AtmosCtrlV3.h"
#include "Proc_CelestialCtrlV3.h"
#include "Proc_CollDetSegDefV3.h"
#include "Proc_CollDetVolDefV3.h"
#include "Proc_CompCtrlV3.h"
#include "Proc_ConfClampEntityCtrlV3.h"
#include "Proc_EarthModelDefV3.h"
#include "Proc_EntityCtrlV3.h"
#include "Proc_EnvCondReqV3.h"
#include "Proc_EnvRgnCtrlV3.h"
#include "Proc_MaritimeSurfaceCtrlV3.h"
#include "Proc_MotionTrackCtrlV3.h"
#include "Proc_PositionReqV3.h"
#include "Proc_SensorCtrlV3.h"
#include "Proc_ShortArtPartCtrlV3.h"
#include "Proc_ShortCompCtrlV3.h"
#include "Proc_TerrestrialSurfaceCtrlV3.h"
#include "Proc_TrajectoryV3.h"
#include "Proc_ViewCtrlV3.h"
#include "Proc_ViewDefV3.h"
#include "Proc_WaveCtrlV3.h"
#include "Proc_WeatherCtrlV3.h"
#include "Proc_RateCtrlV3.h"
#include "Proc_HatHotReqV3.h"
#include "Proc_LosSegReqV3.h"
#include "Proc_LosVectReqV3.h"
#include "Proc_RateCtrlV3_2.h"
#include "Proc_HatHotReqV3_2.h"
#include "Proc_LosSegReqV3_2.h"
#include "Proc_LosVectReqV3_2.h"
#include "Proc_CompCtrlV3_3.h"
#include "Proc_ShortCompCtrlV3_3.h"
#include "Proc_SymbolSurfaceDefV3_3.h"
#include "Proc_SymbolCtrlV3_3.h"
#include "Proc_ShortSymbolCtrlV3_3.h"
#include "Proc_SymbolTextDefV3_3.h"
#include "Proc_SymbolCircleDefV3_3.h"
#include "Proc_SymbolLineDefV3_3.h"


using namespace std;



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


OutputProcessor3::OutputProcessor3()
{

}




OutputProcessor3::~OutputProcessor3()
{

}





void OutputProcessor3::Init(CigiHostSession *HostSnIn,
                            string &CsvFileNm,
                            int MajorVer,
                            int MinorVer)
{

   if(MajorVer == 3)
   {
      Parsers.push_back((PcktParsingProcessor *)(new Proc_ArtPartCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_AtmosCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_CelestialCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetSegDefV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetVolDefV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_ConfClampEntityCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_EarthModelDefV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_EntityCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_EnvCondReqV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_EnvRgnCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_MaritimeSurfaceCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_MotionTrackCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_PositionReqV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_SensorCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_ShortArtPartCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_TerrestrialSurfaceCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_TrajectoryV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_ViewCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_ViewDefV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_WaveCtrlV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_WeatherCtrlV3));

      if(MinorVer < 2)
      {
         Parsers.push_back((PcktParsingProcessor *)(new Proc_RateCtrlV3));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_HatHotReqV3));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_LosSegReqV3));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_LosVectReqV3));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_CompCtrlV3));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_ShortCompCtrlV3));
      }
      else
      {
         Parsers.push_back((PcktParsingProcessor *)(new Proc_HatHotReqV3_2));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_LosSegReqV3_2));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_LosVectReqV3_2));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_RateCtrlV3_2));
         if(MinorVer < 3)
         {
            Parsers.push_back((PcktParsingProcessor *)(new Proc_CompCtrlV3));
            Parsers.push_back((PcktParsingProcessor *)(new Proc_ShortCompCtrlV3));
         }
         else
         {
            Parsers.push_back((PcktParsingProcessor *)(new Proc_CompCtrlV3_3));
            Parsers.push_back((PcktParsingProcessor *)(new Proc_ShortCompCtrlV3_3));
            Parsers.push_back((PcktParsingProcessor *)(new Proc_SymbolSurfaceDefV3_3));
            Parsers.push_back((PcktParsingProcessor *)(new Proc_SymbolCtrlV3_3));
            Parsers.push_back((PcktParsingProcessor *)(new Proc_ShortSymbolCtrlV3_3));
            Parsers.push_back((PcktParsingProcessor *)(new Proc_SymbolTextDefV3_3));
            Parsers.push_back((PcktParsingProcessor *)(new Proc_SymbolCircleDefV3_3));
            Parsers.push_back((PcktParsingProcessor *)(new Proc_SymbolLineDefV3_3));
         }
      }
   }

   OutputProcessor::Init(HostSnIn, CsvFileNm, MajorVer, MinorVer);

}




