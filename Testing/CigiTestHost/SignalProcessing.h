/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2003 The Boeing Company
 *  
 *  This library is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU Lesser General Public License as published by 
 *  the Free Software Foundation; either version 2.1 of the License, or (at 
 *  your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more 
 *  details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License 
 *  along with this library; if not, write to the Free Software Foundation, 
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *  
 *  FILENAME:   SignalProcessing.h
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Common Image Generator Interface (CIGI) SDK
 *  
 *  PROGRAM DESCRIPTION: 
 *  ...
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  09/17/2003 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 * </pre>
 * @author The Boeing Company
 * @version 1.0
 */

#if !defined(_SIGNAL_PROCESSING_INCLUDED_)
#define _SIGNAL_PROCESSING_INCLUDED_

#include "AllCigi.h"


//=========================================================
//! The base class for processing incoming packets using a 
//!   signal processing class.
//!
class SignalProcessing : public CigiBaseSignalProcessing  
{
public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   SignalProcessing() { };

   //=========================================================
   //! General Destructor
   //!
   virtual ~SignalProcessing() { };



   //==> Incoming Packet Processing Functions

   //=========================================================
   //! OnIGCtrl<br>
   //! A base function to process incoming IG control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnIGCtrl(CigiBasePacket *Packet) { printf("OnIGCtrl\n"); }

   //=========================================================
   //! OnEntityCtrl<br>
   //! A base function to process incoming Entity control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnEntityCtrl(CigiBasePacket *Packet) { printf("OnEntityCtrl\n"); }

   //=========================================================
   //! OnViewDef<br>
   //! A base function to process incoming View Definition packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnViewDef(CigiBasePacket *Packet) { printf("OnViewDef\n"); }

   //=========================================================
   //! OnViewCtrl<br>
   //! A base function to process incoming View Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnViewCtrl(CigiBasePacket *Packet) { printf("OnViewCtrl\n"); }

   //=========================================================
   //! OnRateCtrl<br>
   //! A base function to process incoming Rate Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnRateCtrl(CigiBasePacket *Packet) { printf("OnRateCtrl\n"); }

   //=========================================================
   //! OnSensorCtrl<br>
   //! A base function to process incoming Sensor Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnSensorCtrl(CigiBasePacket *Packet) { printf("OnSensorCtrl\n"); }

   //=========================================================
   //! OnTrajectory<br>
   //! A base function to process incoming Trajectory Definition packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnTrajectory(CigiBasePacket *Packet) { printf("OnTrajectory\n"); }

   //=========================================================
   //! OnWeatherCtrl<br>
   //! A base function to process incoming Weather Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnWeatherCtrl(CigiBasePacket *Packet) { printf("OnWeatherCtrl\n"); }

   //=========================================================
   //! OnCollDetSegDef<br>
   //! A base function to process incoming Collision Detection Segment Definition packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnCollDetSegDef(CigiBasePacket *Packet) { printf("OnCollDetSegDef\n"); }

   //=========================================================
   //! OnLosSegReq<br>
   //! A base function to process incoming LOS Segment Request packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnLosSegReq(CigiBasePacket *Packet) { printf("OnLosSegReq\n"); }

   //=========================================================
   //! OnLosVectReq<br>
   //! A base function to process incoming LOS Vector Request packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnLosVectReq(CigiBasePacket *Packet) { printf("OnLosVectReq\n"); }

   //=========================================================
   //! OnHatReq<br>
   //! A base function to process incoming Hat only Request packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnHatReq(CigiBasePacket *Packet) { printf("OnHatReq\n"); }

   //=========================================================
   //! OnHotReq<br>
   //! A base function to process incoming Hot only Request packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnHotReq(CigiBasePacket *Packet) { printf("OnHotReq\n"); }

   //=========================================================
   //! OnHatHotReq<br>
   //! A base function to process incoming Hat Hot Request packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnHatHotReq(CigiBasePacket *Packet) { printf("OnHatHotReq\n"); }

   //=========================================================
   //! OnHatHotXReq<br>
   //! A base function to process incoming Hat Hot Extended Request packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnHatHotXReq(CigiBasePacket *Packet) { printf("OnHatHotXReq\n"); }

   //=========================================================
   //! OnEnvCtrl<br>
   //! A base function to process incoming Environmental Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnEnvCtrl(CigiBasePacket *Packet) { printf("OnEnvCtrl\n"); }

   //=========================================================
   //! OnSpecEffDef<br>
   //! A base function to process incoming Special Effect Definision packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnSpecEffDef(CigiBasePacket *Packet) { printf("OnSpecEffDef\n"); }

   //=========================================================
   //! OnArtPartCtrl<br>
   //! A base function to process incoming Articulated Part Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnArtPartCtrl(CigiBasePacket *Packet) { printf("OnArtPartCtrl\n"); }

   //=========================================================
   //! OnCollDetVolDef<br>
   //! A base function to process incoming Collision Detection Volume Definition packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnCollDetVolDef(CigiBasePacket *Packet) { printf("OnCollDetVolDef\n"); }

   //=========================================================
   //! OnShortArtPartCtrl<br>
   //! A base function to process incoming Short Articulated Part Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnShortArtPartCtrl(CigiBasePacket *Packet) { printf("OnShortArtPartCtrl\n"); }

   //=========================================================
   //! OnConfClampEntityCtrl<br>
   //! A base function to process incoming Conformal Clamped Entity Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnConfClampEntityCtrl(CigiBasePacket *Packet) { printf("OnConfClampEntityCtrl\n"); }

   //=========================================================
   //! OnMaritimeSurfaceCtrl<br>
   //! A base function to process incoming Maritime Surface Conditions Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnMaritimeSurfaceCtrl(CigiBasePacket *Packet) { printf("OnMaritimeSurfaceCtrl\n"); }

   //=========================================================
   //! OnEnvRgnCtrl<br>
   //! A base function to process incoming Environmental Region Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnEnvRgnCtrl(CigiBasePacket *Packet) { printf("OnEnvRgnCtrl\n"); }

   //=========================================================
   //! OnTerrestrialSurfaceCtrl<br>
   //! A base function to process incoming Terrestrial Surface Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnTerrestrialSurfaceCtrl(CigiBasePacket *Packet) { printf("OnTerrestrialSurfaceCtrl\n"); }

   //=========================================================
   //! OnMotionTrackCtrl<br>
   //! A base function to process incoming Motion Tracker control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnMotionTrackCtrl(CigiBasePacket *Packet) { printf("OnMotionTrackCtrl\n"); }

   //=========================================================
   //! OnEarthModelDef<br>
   //! A base function to process incoming Earth Model Definition packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnEarthModelDef(CigiBasePacket *Packet) { printf("OnEarthModelDef\n"); }

   //=========================================================
   //! OnPostionReq<br>
   //! A base function to process incoming Positon Request packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnPostionReq(CigiBasePacket *Packet) { printf("OnPostionReq\n"); }

   //=========================================================
   //! OnEnvCondReq<br>
   //! A base function to process incoming Environmental Conditions Request packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnEnvCondReq(CigiBasePacket *Packet) { printf("OnEnvCondReq\n"); }

   //=========================================================
   //! OnWaveCtrl<br>
   //! A base function to process incoming Wave Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnWaveCtrl(CigiBasePacket *Packet) { printf("OnWaveCtrl\n"); }

   //=========================================================
   //! OnSOF<br>
   //! A base function to process incoming Start Of Frame packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnSOF(CigiBasePacket *Packet) { printf("XSOF\n"); }

   //=========================================================
   //! OnCollDetSegResp<br>
   //! A base function to process incoming Collision Detection Segment Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnCollDetSegResp(CigiBasePacket *Packet) { printf("XCollDetSegResp\n"); }

   //=========================================================
   //! OnSensorResp<br>
   //! A base function to process incoming Sensor Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnSensorResp(CigiBasePacket *Packet) { printf("XSensorResp\n"); }

   //=========================================================
   //! OnSensorXResp<br>
   //! A base function to process incoming Sensor Extended Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnSensorXResp(CigiBasePacket *Packet) { printf("XSensorXResp\n"); }

   //=========================================================
   //! OnLosResp<br>
   //! A base function to process incoming Los Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnLosResp(CigiBasePacket *Packet) { printf("XLosResp\n"); }

   //=========================================================
   //! OnLosXResp<br>
   //! A base function to process incoming Los Extended Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnLosXResp(CigiBasePacket *Packet) { printf("XLosXResp\n"); }

   //=========================================================
   //! OnHatResp<br>
   //! A base function to process incoming Hat only Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnHatResp(CigiBasePacket *Packet) { printf("XHatHotResp\n"); }

   //=========================================================
   //! OnHotResp<br>
   //! A base function to process incoming Hot only Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnHotResp(CigiBasePacket *Packet) { printf("XHatHotResp\n"); }

   //=========================================================
   //! OnHatHotXResp<br>
   //! A base function to process incoming Hat Hot Extended Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnHatHotXResp(CigiBasePacket *Packet) { printf("XHatHotXResp\n"); }

   //=========================================================
   //! OnHatHotResp<br>
   //! A base function to process incoming Hat Hot Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnHatHotResp(CigiBasePacket *Packet) { printf("XHatHotResp\n"); }

   //=========================================================
   //! OnCollDetVolResp<br>
   //! A base function to process incoming Collision Detection Volume Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnCollDetVolResp(CigiBasePacket *Packet) { printf("XCollDetVolResp\n"); }

   //=========================================================
   //! OnPositionResp<br>
   //! A base function to process incoming Position Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnPositionResp(CigiBasePacket *Packet) { printf("XPositionResp\n"); }

   //=========================================================
   //! OnWeatherCondResp<br>
   //! A base function to process incoming Weather Condition Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnWeatherCondResp(CigiBasePacket *Packet) { printf("XWeatherCondResp\n"); }

   //=========================================================
   //! OnAerosolResp<br>
   //! A base function to process incoming Aerosol Resp packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnAerosolResp(CigiBasePacket *Packet) { printf("XAerosolResp\n"); }

   //=========================================================
   //! OnMaritimeSurfaceResp<br>
   //! A base function to process incoming Maritime Surface Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnMaritimeSurfaceResp(CigiBasePacket *Packet) { printf("XMaritimeSurfaceResp\n"); }

   //=========================================================
   //! OnTerrestrialSurfaceResp<br>
   //! A base function to process incoming Terrestrial Surface Response packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnTerrestrialSurfaceResp(CigiBasePacket *Packet) { printf("XTerrestrialSurfaceResp\n"); }

   //=========================================================
   //! OnAnimationStop<br>
   //! A base function to process incoming Animation Stop Notification packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnAnimationStop(CigiBasePacket *Packet) { printf("XAnimationStop\n"); }

   //=========================================================
   //! OnEventNotification<br>
   //! A base function to process incoming Event Notification packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnEventNotification(CigiBasePacket *Packet) { printf("XEventNotification\n"); }

   //=========================================================
   //! OnIGMsg<br>
   //! A base function to process incoming IG Message packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnIGMsg(CigiBasePacket *Packet) { printf("XIGMsg\n"); }

   //=========================================================
   //! OnIGMsg<br>
   //! A base function to process incoming Component Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnCompCtrl(CigiBasePacket *Packet) { printf("OnCompCtrl\n"); }

   //=========================================================
   //! OnIGMsg<br>
   //! A base function to process incoming Short Component Control packets.<br>
   //!   Segment Definition packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnShortCompCtrl(CigiBasePacket *Packet) { printf("OnShortCompCtrl\n"); }

   //=========================================================
   //! OnAtmosCtrl<br>
   //! A base function to process incoming Atmosphere Control packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnAtmosCtrl(CigiBasePacket *Packet) { printf("OnAtmosCtrl\n"); };

   //=========================================================
   //! OnCelestialCtrl<br>
   //! A base function to process incoming Celestial Control packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnCelestialCtrl(CigiBasePacket *Packet) { printf("OnCelestialCtrl\n"); };






   //=========================================================
   //! OnUnrecognized<br>
   //! A base function to process any incoming unrecognized packets.<br>
   //! This function does nothing in this base class.<br>
   //! If processing is required, the inheriting class must
   //!   implement this call.
   //!
   virtual void OnUnrecognized(CigiBasePacket *Packet) { };

};

#endif // !defined(_SIGNAL_PROCESSING_INCLUDED_)
