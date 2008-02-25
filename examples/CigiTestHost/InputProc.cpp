// InputProc.cpp: implementation of the InputProc class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "InputProc.h"

#include "Callbacks.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

InputProc::InputProc()
{

   HostSn = NULL;
   ImsgPtr = NULL;

   Pr_SOF = NULL;
   Pr_CollDetSegResp = NULL;
   Pr_SensorResp = NULL;
   Pr_SensorXResp = NULL;
   Pr_LosResp = NULL;
   Pr_LosXResp = NULL;
   Pr_HatHotResp = NULL;
   Pr_HatHotXResp = NULL;
   Pr_CollDetVolResp = NULL;
   Pr_PositionResp = NULL;
   Pr_WeatherCondResp = NULL;
   Pr_AerosolResp = NULL;
   Pr_MaritimeSurfaceResp = NULL;
   Pr_TerrestrialSurfaceResp = NULL;
   Pr_AnimationStop = NULL;
   Pr_EventNotification = NULL;
   Pr_IGMsg = NULL;

   Pr_Default = NULL;

   SigProc = NULL;

}



InputProc::~InputProc()
{

   delete Pr_SOF;
   delete Pr_CollDetSegResp;
   delete Pr_SensorResp;
   delete Pr_SensorXResp;
   delete Pr_LosResp;
   delete Pr_LosXResp;
   delete Pr_HatHotResp;
   delete Pr_HatHotXResp;
   delete Pr_CollDetVolResp;
   delete Pr_PositionResp;
   delete Pr_WeatherCondResp;
   delete Pr_AerosolResp;
   delete Pr_MaritimeSurfaceResp;
   delete Pr_TerrestrialSurfaceResp;
   delete Pr_AnimationStop;
   delete Pr_EventNotification;
   delete Pr_IGMsg;

   delete Pr_Default;

   delete SigProc;

}





void InputProc::Init(CigiHostSession *HostSnIn)
{
   // Get Host Session
   HostSn = HostSnIn;

   // Get the Incoming Message Manager
   CigiIncomingMsg &Imsg = HostSn->GetIncomingMsgMgr();
   ImsgPtr = &Imsg;



   // Create and Register all the Event processors

   // SOF
   Pr_SOF = new XSOF;
   Imsg.RegisterEventProcessor(CIGI_SOF_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) Pr_SOF);

   // Collision Detection Segment Response
   Pr_CollDetSegResp = new XCollDetSegResp;
   Imsg.RegisterEventProcessor(CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_CollDetSegResp);

   // Sensor Response
   Pr_SensorResp = new XSensorResp;
   Imsg.RegisterEventProcessor(CIGI_SENSOR_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_SensorResp);

   // Extended Sensor Response
   Pr_SensorXResp = new XSensorXResp;
   Imsg.RegisterEventProcessor(CIGI_SENSOR_XRESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_SensorXResp);

   // Line Of Sight Response
   Pr_LosResp = new XLosResp;
   Imsg.RegisterEventProcessor(CIGI_LOS_RESP_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) Pr_LosResp);

   // Line Of Sight Extended Response
   Pr_LosXResp = new XLosXResp;
   Imsg.RegisterEventProcessor(CIGI_LOS_XRESP_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) Pr_LosXResp);

   // Height Above/Of Terrain Response
   Pr_HatHotResp = new XHatHotResp;
   Imsg.RegisterEventProcessor(CIGI_HAT_HOT_RESP_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) Pr_HatHotResp);

   // Height Above/Of Terrain Extended Response
   Pr_HatHotXResp = new XHatHotXResp;
   Imsg.RegisterEventProcessor(CIGI_HAT_HOT_XRESP_PACKET_ID_V3_2,
                              (CigiBaseEventProcessor *) Pr_HatHotXResp);

   // Collision Detection Volume Response
   Pr_CollDetVolResp = new XCollDetVolResp;
   Imsg.RegisterEventProcessor(CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_CollDetVolResp);

   // Position Response
   Pr_PositionResp = new XPositionResp;
   Imsg.RegisterEventProcessor(CIGI_POSITION_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_PositionResp);

   // Weather Condition Response
   Pr_WeatherCondResp = new XWeatherCondResp;
   Imsg.RegisterEventProcessor(CIGI_WEATHER_COND_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_WeatherCondResp);

   // Aerosol Response
   Pr_AerosolResp = new XAerosolResp;
   Imsg.RegisterEventProcessor(CIGI_AEROSOL_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_AerosolResp);

   // Maritime Surface Response
   Pr_MaritimeSurfaceResp = new XMaritimeSurfaceResp;
   Imsg.RegisterEventProcessor(CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_MaritimeSurfaceResp);

   // Terrestrial Surface Response
   Pr_TerrestrialSurfaceResp = new XTerrestrialSurfaceResp;
   Imsg.RegisterEventProcessor(CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_TerrestrialSurfaceResp);

   // Animation Stop Notification
   Pr_AnimationStop = new XAnimationStop;
   Imsg.RegisterEventProcessor(CIGI_ANIMATION_STOP_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_AnimationStop);

   // Event Notification
   Pr_EventNotification = new XEventNotification;
   Imsg.RegisterEventProcessor(CIGI_EVENT_NOTIFICATION_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_EventNotification);

   // IG Message
   Pr_IGMsg = new XIGMsg;
   Imsg.RegisterEventProcessor(CIGI_IG_MSG_PACKET_ID_V3,
                              (CigiBaseEventProcessor *) Pr_IGMsg);

   // Default Packet Processor
   Pr_Default = new DefaultProc;
	Imsg.RegisterEventProcessor(0, (CigiBaseEventProcessor *) Pr_Default);



   // Register all the callback processors
   Imsg.RegisterCallBack(CIGI_SOF_PACKET_ID_V3,
                              (CigiCBProcessor) &YSOF);
   Imsg.RegisterCallBack(CIGI_COLL_DET_SEG_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YCollDetSegResp);
   Imsg.RegisterCallBack(CIGI_SENSOR_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YSensorResp);
   Imsg.RegisterCallBack(CIGI_SENSOR_XRESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YSensorXResp);
   Imsg.RegisterCallBack(CIGI_LOS_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YLosResp);
   Imsg.RegisterCallBack(CIGI_LOS_XRESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YLosXResp);
   Imsg.RegisterCallBack(CIGI_HAT_HOT_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YHatHotResp);
   Imsg.RegisterCallBack(CIGI_HAT_HOT_XRESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YHatHotXResp);
   Imsg.RegisterCallBack(CIGI_COLL_DET_VOL_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YCollDetVolResp);
   Imsg.RegisterCallBack(CIGI_POSITION_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YPositionResp);
   Imsg.RegisterCallBack(CIGI_WEATHER_COND_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YWeatherCondResp);
   Imsg.RegisterCallBack(CIGI_AEROSOL_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YAerosolResp);
   Imsg.RegisterCallBack(CIGI_MARITIME_SURFACE_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YMaritimeSurfaceResp);
   Imsg.RegisterCallBack(CIGI_TERRESTRIAL_SURFACE_RESP_PACKET_ID_V3,
                              (CigiCBProcessor) &YTerrestrialSurfaceResp);
   Imsg.RegisterCallBack(CIGI_ANIMATION_STOP_PACKET_ID_V3,
                              (CigiCBProcessor) &YAnimationStop);
   Imsg.RegisterCallBack(CIGI_EVENT_NOTIFICATION_PACKET_ID_V3,
                              (CigiCBProcessor) &YEventNotification);
   Imsg.RegisterCallBack(CIGI_IG_MSG_PACKET_ID_V3,
                              (CigiCBProcessor) &YIGMsg);

	Imsg.RegisterCallBack(0, (CigiCBProcessor) &YDeflt);



   // Create and register the signal processor object
   SigProc = new SignalProcessing;
   Imsg.RegisterSignalProcessor(SigProc);


}





