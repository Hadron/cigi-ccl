# Microsoft Developer Studio Project File - Name="ccl_dll" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=ccl_dll - Win32 dllDebugMT_DLL
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "ccl_dll.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "ccl_dll.mak" CFG="ccl_dll - Win32 dllDebugMT_DLL"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "ccl_dll - Win32 dllDebugMT_DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ccl_dll - Win32 dllReleaseMT_DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ccl_dll - Win32 dllDebugMT_DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "dllDebugMT_DLL"
# PROP BASE Intermediate_Dir "dllDebugMT_DLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin\dllDebugMT_DLL"
# PROP Intermediate_Dir "..\bin\dllDebugMT_DLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CCL_DLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CCL_DLL_EXPORTS" /D "CCL_DLL" /D "CIGI_LITTLE_ENDIAN" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept

!ELSEIF  "$(CFG)" == "ccl_dll - Win32 dllReleaseMT_DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "dllReleaseMT_DLL"
# PROP BASE Intermediate_Dir "dllReleaseMT_DLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin\dllReleaseMT_DLL"
# PROP Intermediate_Dir "..\bin\dllReleaseMT_DLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CCL_DLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CCL_DLL_EXPORTS" /D "CCL_DLL" /D "CIGI_LITTLE_ENDIAN" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386

!ENDIF

# Begin Target

# Name "ccl_dll - Win32 dllDebugMT_DLL"
# Name "ccl_dll - Win32 dllReleaseMT_DLL"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\source\CigiAerosolRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiAnimationStopV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiAnimationTable.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiArtPartCtrlV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiArtPartCtrlV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiArtPartCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiAtmosCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseAerosolResp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseArtPartCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseCollDetSegResp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseCollDetVolDef.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseCollDetVolResp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseConfClampEntityCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseEntityCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseEnvCondReq.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseEnvCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseEnvRgnCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseEventNotification.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseHatHotReq.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseIGCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseLosResp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseLosSegReq.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseLosVectReq.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseMaritimeSurfaceCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseMaritimeSurfaceResp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseMotionTrackCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBasePositionReq.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBasePositionResp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseSensorCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseSensorResp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseShortArtPartCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseSOF.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseSpecEffDef.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseTerrestrialSurfaceCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseTrajectoryDef.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseViewCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseViewDef.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseWaveCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseWeatherCondResp.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiBaseWeatherCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCelestialCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetSegDefV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetSegDefV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetSegDefV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetSegRespV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetSegRespV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetSegRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetVolDefV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetVolDefV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetVolRespV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCollDetVolRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCompCtrlV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCompCtrlV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiCompCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiConfClampEntityCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiDefaultPacket.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEarthModelDefV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEntityCtrlV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEntityCtrlV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEntityCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEnvCondReqV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEnvCtrlV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEnvCtrlV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEnvRgnCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEventList.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiEventNotificationV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatHotReqV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatHotReqV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatHotRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatHotRespV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatHotXRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatHotXRespV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatReqV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatReqV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatRespV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHatRespV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHostSession.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHotReqV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiHotRespV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiIGCtrlV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiIGCtrlV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiIGCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiIGCtrlV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiIGMsgV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiIGMsgV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiIGSession.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiIncomingMsg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiIO.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosRespV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosRespV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosRespV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosSegReqV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosSegReqV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosSegReqV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosSegReqV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosVectReqV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosVectReqV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosVectReqV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosVectReqV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosXRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiLosXRespV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiMaritimeSurfaceCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiMaritimeSurfaceRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiMessage.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiMotionTrackCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiOutgoingMsg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiPositionReqV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiPositionRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiRateCtrlV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiRateCtrlV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiRateCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiRateCtrlV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSensorCtrlV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSensorCtrlV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSensorCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSensorRespV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSensorRespV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSensorRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSensorXRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSession.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiShortArtPartCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiShortCompCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSOFV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSOFV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSOFV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSOFV3_2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSpecEffDefV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSpecEffDefV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiSwapping.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiTerrestrialSurfaceCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiTerrestrialSurfaceRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiTrajectoryDefV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiTrajectoryDefV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiTrajectoryDefV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiVersionJumpTable.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiViewCtrlV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiViewCtrlV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiViewCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiViewDefV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiViewDefV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiViewDefV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiWaveCtrlV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiWeatherCondRespV3.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiWeatherCtrlV1.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiWeatherCtrlV2.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CigiWeatherCtrlV3.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\CigiAerosolRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiAnimationStopV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiAnimationTable.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiArtPartCtrlV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiArtPartCtrlV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiArtPartCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiAtmosCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseAerosolResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseAnimationStop.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseArtPartCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseCollDetSegDef.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseCollDetSegResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseCollDetVolDef.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseCollDetVolResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseCompCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseConfClampEntityCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseEarthModelDef.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseEntityCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseEnvCondReq.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseEnvCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseEnvRgnCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseEventNotification.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseEventProcessor.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseHatHotReq.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseHatHotResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseIGCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseIGMsg.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseLosResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseLosSegReq.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseLosVectReq.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseMaritimeSurfaceCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseMaritimeSurfaceResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseMotionTrackCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBasePacket.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBasePositionReq.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBasePositionResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseRateCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseSensorCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseSensorResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseShortArtPartCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseSignalProcessing.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseSOF.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseSpecEffDef.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseTerrestrialSurfaceCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseTerrestrialSurfaceResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseTrajectoryDef.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseViewCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseViewDef.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseWaveCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseWeatherCondResp.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiBaseWeatherCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCelestialCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetSegDefV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetSegDefV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetSegDefV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetSegRespV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetSegRespV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetSegRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetVolDefV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetVolDefV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetVolRespV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCollDetVolRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCompCtrlV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCompCtrlV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiCompCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiConfClampEntityCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiDefaultPacket.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEarthModelDefV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEntityCtrlV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEntityCtrlV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEntityCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEnvCondReqV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEnvCtrlV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEnvCtrlV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEnvRgnCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiErrorCodes.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEventList.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiEventNotificationV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiException.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiExceptions.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHatHotReqV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHatHotReqV3_2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHatHotRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHatHotXRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHatHotXRespV3_2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHatReqV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHatReqV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHatRespV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHatRespV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHoldEnvCtrl.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHostSession.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHotReqV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiHotRespV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiIGCtrlV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiIGCtrlV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiIGCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiIGCtrlV3_2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiIGMsgV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiIGMsgV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiIGSession.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiIncomingMsg.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiIO.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosRespV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosRespV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosRespV3_2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosSegReqV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosSegReqV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosSegReqV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosSegReqV3_2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosVectReqV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosVectReqV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosVectReqV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosVectReqV3_2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosXRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiLosXRespV3_2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiMaritimeSurfaceCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiMaritimeSurfaceRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiMessage.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiMotionTrackCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiOutgoingMsg.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiPositionReqV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiPositionRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiRateCtrlV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiRateCtrlV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiRateCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiRateCtrlV3_2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSensorCtrlV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSensorCtrlV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSensorCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSensorRespV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSensorRespV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSensorRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSensorXRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSession.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiShortArtPartCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiShortCompCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSOFV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSOFV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSOFV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSOFV3_2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSpecEffDefV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSpecEffDefV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiSwapping.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiTerrestrialSurfaceCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiTerrestrialSurfaceRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiTrajectoryDefV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiTrajectoryDefV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiTrajectoryDefV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiTypes.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiVersionJumpTable.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiViewCtrlV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiViewCtrlV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiViewCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiViewDefV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiViewDefV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiViewDefV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiWaveCtrlV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiWeatherCondRespV3.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiWeatherCtrlV1.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiWeatherCtrlV2.h
# End Source File
# Begin Source File

SOURCE=..\include\CigiWeatherCtrlV3.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
