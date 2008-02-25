// InputProc.h: interface for the InputProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_INPUT_PROCESSOR_INCLUDED_)
#define _INPUT_PROCESSOR_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "AllCigi.h"


#include "XSOF.h"
#include "XCollDetSegResp.h"
#include "XSensorResp.h"
#include "XSensorXResp.h"
#include "XLosResp.h"
#include "XLosXResp.h"
#include "XHatHotResp.h"
#include "XHatHotXResp.h"
#include "XCollDetVolResp.h"
#include "XPositionResp.h"
#include "XWeatherCondResp.h"
#include "XAerosolResp.h"
#include "XMaritimeSurfaceResp.h"
#include "XTerrestrialSurfaceResp.h"
#include "XAnimationStop.h"
#include "XEventNotification.h"
#include "XIGMsg.h"

#include "DefaultProc.h"

#include "SignalProcessing.h"



class InputProc  
{
public:
	InputProc();
	virtual ~InputProc();


   void Init(CigiHostSession *HostSnIn);



protected:

   CigiHostSession *HostSn;
   CigiIncomingMsg *ImsgPtr;



   //Event classes to work with incoming packets
   XSOF *Pr_SOF;
   XCollDetSegResp *Pr_CollDetSegResp;
   XSensorResp *Pr_SensorResp;
   XSensorXResp *Pr_SensorXResp;
   XLosResp *Pr_LosResp;
   XLosXResp *Pr_LosXResp;
   XHatHotResp *Pr_HatHotResp;
   XHatHotXResp *Pr_HatHotXResp;
   XCollDetVolResp *Pr_CollDetVolResp;
   XPositionResp *Pr_PositionResp;
   XWeatherCondResp *Pr_WeatherCondResp;
   XAerosolResp *Pr_AerosolResp;
   XMaritimeSurfaceResp *Pr_MaritimeSurfaceResp;
   XTerrestrialSurfaceResp *Pr_TerrestrialSurfaceResp;
   XAnimationStop *Pr_AnimationStop;
   XEventNotification *Pr_EventNotification;
   XIGMsg *Pr_IGMsg;

   DefaultProc *Pr_Default;


   SignalProcessing *SigProc;




};

#endif // !defined(_INPUT_PROCESSOR_INCLUDED_)
