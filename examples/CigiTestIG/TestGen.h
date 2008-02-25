// TestGen.h: interface for the TestGen class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_TEST_GENERATOR_INCLUDED_)
#define _TEST_GENERATOR_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "AllCigi.h"
#include "ParseLine.h"
#include "ParseValue.h"




class TestGen  
{
public:
	TestGen();
	virtual ~TestGen();

	void Init(CigiIGSession *IGSnIn);

	void Out(void);
	void Test(ParseLine &PrsLn);




protected:


   // routine to determine the current packet from csv data
	int DeterminePckt(ParseValue *pPV);

   CigiIGSession *IGsn;

   ParseLine IGPrsLn;

   int TstID;

   char *DefHex;

   char line[512];


   // Cigi objects used to send packets
   CigiCollDetSegRespV3 Om_CollDetSegResp;
   CigiSensorRespV3 Om_SensorResp;
   CigiSensorXRespV3 Om_SensorXResp;
   CigiLosRespV3_2 Om_LosResp;
   CigiLosXRespV3_2 Om_LosXResp;
   CigiHatHotRespV3_2 Om_HatHotResp;
   CigiHatHotXRespV3_2 Om_HatHotXResp;
   CigiCollDetVolRespV3 Om_CollDetVolResp;
   CigiPositionRespV3 Om_PositionResp;
   CigiWeatherCondRespV3 Om_WeatherCondResp;
   CigiAerosolRespV3 Om_AerosolResp;
   CigiMaritimeSurfaceRespV3 Om_MaritimeSurfaceResp;
   CigiTerrestrialSurfaceRespV3 Om_TerrestrialSurfaceResp;
   CigiAnimationStopV3 Om_AnimationStop;
   CigiEventNotificationV3 Om_EventNotification;
   CigiIGMsgV3 Om_IGMsg;



   // parsing routines to fill in packets
   void Proc_CollDetSegResp(ParseValue *pPV);
   void Proc_SensorResp(ParseValue *pPV);
   void Proc_SensorXResp(ParseValue *pPV);
   void Proc_LosResp(ParseValue *pPV);
   void Proc_LosXResp(ParseValue *pPV);
   void Proc_HatHotResp(ParseValue *pPV);
   void Proc_HatHotXResp(ParseValue *pPV);
   void Proc_CollDetVolResp(ParseValue *pPV);
   void Proc_PositionResp(ParseValue *pPV);
   void Proc_WeatherCondResp(ParseValue *pPV);
   void Proc_AerosolResp(ParseValue *pPV);
   void Proc_MaritimeSurfaceResp(ParseValue *pPV);
   void Proc_TerrestrialSurfaceResp(ParseValue *pPV);
   void Proc_AnimationStop(ParseValue *pPV);
   void Proc_EventNotification(ParseValue *pPV);
   void Proc_IGMsg(ParseValue *pPV);



};

#endif // !defined(_TEST_GENERATOR_INCLUDED_)
