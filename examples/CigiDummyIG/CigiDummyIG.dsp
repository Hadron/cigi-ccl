# Microsoft Developer Studio Project File - Name="CigiDummyIG" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=CigiDummyIG - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CigiDummyIG.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CigiDummyIG.mak" CFG="CigiDummyIG - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CigiDummyIG - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "CigiDummyIG - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CigiDummyIG - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\include" /I "..\tinyxml" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib ccl_lib.lib tinyxml_STL.lib /nologo /subsystem:console /machine:I386 /libpath:"..\..\bin\libReleaseMT_DLL" /libpath:"..\tinyxml\Release_STL"

!ELSEIF  "$(CFG)" == "CigiDummyIG - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\include" /I "..\tinyxml" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib ccl_lib.lib tinyxmld_STL.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\bin\libDebugMT_DLL" /libpath:"..\tinyxml\Debug_STL"

!ENDIF 

# Begin Target

# Name "CigiDummyIG - Win32 Release"
# Name "CigiDummyIG - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DefaultProc.cpp
# End Source File
# Begin Source File

SOURCE=.\DummyIG.cpp
# End Source File
# Begin Source File

SOURCE=.\Network.cpp
# End Source File
# Begin Source File

SOURCE=.\XArtPartCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XAtmosCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XCelestialCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XCollDetSegDef.cpp
# End Source File
# Begin Source File

SOURCE=.\XCollDetVolDef.cpp
# End Source File
# Begin Source File

SOURCE=.\XCompCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XConfClampEntityCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XEarthModelDef.cpp
# End Source File
# Begin Source File

SOURCE=.\XEntityCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XEnvCondReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XEnvRgnCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XEventNotification.cpp
# End Source File
# Begin Source File

SOURCE=.\XHatHotReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XIGCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XLosSegReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XLosVectReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XMaritimeSurfaceCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XMotionTrackCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XPostionReq.cpp
# End Source File
# Begin Source File

SOURCE=.\XRateCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XSensorCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XShortArtPartCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XShortCompCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XTerrestrialSurfaceCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XTrajectory.cpp
# End Source File
# Begin Source File

SOURCE=.\XViewCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XViewDef.cpp
# End Source File
# Begin Source File

SOURCE=.\XWaveCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XWeatherCtrl.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DefaultProc.h
# End Source File
# Begin Source File

SOURCE=.\Network.h
# End Source File
# Begin Source File

SOURCE=.\XArtPartCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XAtmosCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XCelestialCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XCollDetSegDef.h
# End Source File
# Begin Source File

SOURCE=.\XCollDetVolDef.h
# End Source File
# Begin Source File

SOURCE=.\XCompCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XConfClampEntityCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XEarthModelDef.h
# End Source File
# Begin Source File

SOURCE=.\XEntityCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XEnvCondReq.h
# End Source File
# Begin Source File

SOURCE=.\XEnvRgnCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XEventNotification.h
# End Source File
# Begin Source File

SOURCE=.\XHatHotReq.h
# End Source File
# Begin Source File

SOURCE=.\XIGCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XLosSegReq.h
# End Source File
# Begin Source File

SOURCE=.\XLosVectReq.h
# End Source File
# Begin Source File

SOURCE=.\XMaritimeSurfaceCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XMotionTrackCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XPostionReq.h
# End Source File
# Begin Source File

SOURCE=.\XRateCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XSensorCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XShortArtPartCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XShortCompCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XTerrestrialSurfaceCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XTrajectory.h
# End Source File
# Begin Source File

SOURCE=.\XViewCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XViewDef.h
# End Source File
# Begin Source File

SOURCE=.\XWaveCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XWeatherCtrl.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
