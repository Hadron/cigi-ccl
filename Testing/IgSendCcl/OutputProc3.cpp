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


#include "Proc_HatHotRespV3.h"
#include "Proc_HatHotXRespV3.h"
#include "Proc_LosRespV3.h"
#include "Proc_LosXRespV3.h"
#include "Proc_SensorRespV3.h"
#include "Proc_SensorXRespV3.h"
#include "Proc_PositionRespV3.h"
#include "Proc_WeatherCondRespV3.h"
#include "Proc_AerosolRespV3.h"
#include "Proc_MaritimeSurfaceRespV3.h"
#include "Proc_TerrestrialSurfaceRespV3.h"
#include "Proc_CollDetSegRespV3.h"
#include "Proc_CollDetVolRespV3.h"
#include "Proc_AnimationStopV3.h"
#include "Proc_EventNotificationV3.h"
#include "Proc_IGMsgV3.h"

#include "Proc_HatHotRespV3_2.h"
#include "Proc_HatHotXRespV3_2.h"
#include "Proc_LosRespV3_2.h"
#include "Proc_LosXRespV3_2.h"





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





void OutputProcessor3::Init(CigiSession *CrntSessionIn,
                            string &CsvFileNm,
                            int MajorVer,
                            int MinorVer)
{

   if(MajorVer == 3)
   {
      Parsers.push_back((PcktParsingProcessor *)(new Proc_SensorRespV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_SensorXRespV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_PositionRespV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_WeatherCondRespV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_AerosolRespV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_MaritimeSurfaceRespV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_TerrestrialSurfaceRespV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetSegRespV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_CollDetVolRespV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_AnimationStopV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_EventNotificationV3));
      Parsers.push_back((PcktParsingProcessor *)(new Proc_IGMsgV3));

      if(MinorVer < 2)
      {
         Parsers.push_back((PcktParsingProcessor *)(new Proc_HatHotRespV3));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_HatHotXRespV3));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_LosRespV3));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_LosXRespV3));
      }
      else
      {
         Parsers.push_back((PcktParsingProcessor *)(new Proc_HatHotRespV3_2));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_HatHotXRespV3_2));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_LosRespV3_2));
         Parsers.push_back((PcktParsingProcessor *)(new Proc_LosXRespV3_2));
      }
   }

   OutputProcessor::Init(CrntSessionIn, CsvFileNm, MajorVer, MinorVer);

}




