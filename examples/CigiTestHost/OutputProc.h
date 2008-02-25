// OutputProcessor.h: interface for the OutputProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_OUTPUT_PROCESSOR_INCLUDED_)
#define _OUTPUT_PROCESSOR_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "AllCigi.h"

class ParseLine;
class ParseValue;




class OutputProcessor  
{
public:
	OutputProcessor();
	virtual ~OutputProcessor();


   void Init(CigiHostSession *HostSnIn);
	void Out(void);
	void ProcLine(ParseLine &PrsLn);



protected:

   CigiHostSession *HostSn;
   CigiOutgoingMsg *OmsgPtr;

   ParseLine *HPrsLn;

   char line[512];


	int DeterminePckt(ParseValue *pPV);


   int TstID;

   char *DefHex;

   // Cigi objects used to send packets
   CigiEntityCtrlV3 Om_EntityCtrl;
   CigiConfClampEntityCtrlV3 Om_ConfClampEntityCtrl;
   CigiCompCtrlV3 Om_CompCtrl;
   CigiShortCompCtrlV3 Om_ShortCompCtrl;
   CigiArtPartCtrlV3 Om_ArtPartCtrl;
   CigiShortArtPartCtrlV3 Om_ShortArtPartCtrl;
   CigiRateCtrlV3_2 Om_RateCtrl;
   CigiCelestialCtrlV3 Om_CelestialCtrl;
   CigiAtmosCtrlV3 Om_AtmosCtrl;
   CigiEnvRgnCtrlV3 Om_EnvRgnCtrl;
   CigiWeatherCtrlV3 Om_WeatherCtrl;
   CigiMaritimeSurfaceCtrlV3 Om_MaritimeSurfaceCtrl;
   CigiWaveCtrlV3 Om_WaveCtrl;
   CigiTerrestrialSurfaceCtrlV3 Om_TerrestrialSurfaceCtrl;
   CigiViewCtrlV3 Om_ViewCtrl;
   CigiSensorCtrlV3 Om_SensorCtrl;
   CigiMotionTrackCtrlV3 Om_MotionTrackCtrl;
   CigiEarthModelDefV3 Om_EarthModelDef;
   CigiTrajectoryDefV3 Om_Trajectory;
   CigiViewDefV3 Om_ViewDef;
   CigiCollDetSegDefV3 Om_CollDetSegDef;
   CigiCollDetVolDefV3 Om_CollDetVolDef;
   CigiHatHotReqV3_2 Om_HatHotReq;
   CigiLosSegReqV3_2 Om_LosSegReq;
   CigiLosVectReqV3_2 Om_LosVectReq;
   CigiPositionReqV3 Om_PositionReq;
   CigiEnvCondReqV3 Om_EnvCondReq;



   // parsing routines to fill in packets
   // void Proc_IGCtrl(ParseValue *pPV);
   void Proc_EntityCtrl(ParseValue *pPV);
   void Proc_ConfClampEntityCtrl(ParseValue *pPV);
   void Proc_CompCtrl(ParseValue *pPV);
   void Proc_ShortCompCtrl(ParseValue *pPV);
   void Proc_ArtPartCtrl(ParseValue *pPV);
   void Proc_ShortArtPartCtrl(ParseValue *pPV);
   void Proc_RateCtrl(ParseValue *pPV);
   void Proc_CelestialCtrl(ParseValue *pPV);
   void Proc_AtmosCtrl(ParseValue *pPV);
   void Proc_EnvRgnCtrl(ParseValue *pPV);
   void Proc_WeatherCtrl(ParseValue *pPV);
   void Proc_MaritimeSurfaceCtrl(ParseValue *pPV);
   void Proc_WaveCtrl(ParseValue *pPV);
   void Proc_TerrestrialSurfaceCtrl(ParseValue *pPV);
   void Proc_ViewCtrl(ParseValue *pPV);
   void Proc_SensorCtrl(ParseValue *pPV);
   void Proc_MotionTrackCtrl(ParseValue *pPV);
   void Proc_EarthModelDef(ParseValue *pPV);
   void Proc_Trajectory(ParseValue *pPV);
   void Proc_ViewDef(ParseValue *pPV);
   void Proc_CollDetSegDef(ParseValue *pPV);
   void Proc_CollDetVolDef(ParseValue *pPV);
   void Proc_HatHotReq(ParseValue *pPV);
   void Proc_LosSegReq(ParseValue *pPV);
   void Proc_LosVectReq(ParseValue *pPV);
   void Proc_PostionReq(ParseValue *pPV);
   void Proc_EnvCondReq(ParseValue *pPV);



};

#endif // !defined(_OUTPUT_PROCESSOR_INCLUDED_)
