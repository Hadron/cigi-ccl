# Microsoft Developer Studio Project File - Name="CigiTestHost" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=CigiTestHost - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CigiTestHost.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CigiTestHost.mak" CFG="CigiTestHost - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CigiTestHost - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "CigiTestHost - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CigiTestHost - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\tinyxml" /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ccl_lib.lib tinyxml_STL.lib wsock32.lib /nologo /subsystem:console /machine:I386 /libpath:"..\tinyxml\Release_STL" /libpath:"..\..\bin\libReleaseMT_DLL"

!ELSEIF  "$(CFG)" == "CigiTestHost - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\tinyxml" /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ccl_lib.lib tinyxmld_STL.lib wsock32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\tinyxml\Debug_STL" /libpath:"..\..\bin\libDebugMT_DLL"

!ENDIF 

# Begin Target

# Name "CigiTestHost - Win32 Release"
# Name "CigiTestHost - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Callbacks.cpp
# End Source File
# Begin Source File

SOURCE=.\DefaultProc.cpp
# End Source File
# Begin Source File

SOURCE=.\InputProc.cpp
# End Source File
# Begin Source File

SOURCE=.\MiniHost.cpp
# End Source File
# Begin Source File

SOURCE=.\Network.cpp
# End Source File
# Begin Source File

SOURCE=.\OutputProc.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseLine.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseValue.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# Begin Source File

SOURCE=.\XAerosolResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XAnimationStop.cpp
# End Source File
# Begin Source File

SOURCE=.\XCollDetSegResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XCollDetVolResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XEventNotification.cpp
# End Source File
# Begin Source File

SOURCE=.\XHatHotResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XHatHotXResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XIGMsg.cpp
# End Source File
# Begin Source File

SOURCE=.\XLosResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XLosXResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XMaritimeSurfaceResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XPositionResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XSensorResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XSensorXResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XSOF.cpp
# End Source File
# Begin Source File

SOURCE=.\XTerrestrialSurfaceResp.cpp
# End Source File
# Begin Source File

SOURCE=.\XWeatherCondResp.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AllCigi.h
# End Source File
# Begin Source File

SOURCE=.\Callbacks.h
# End Source File
# Begin Source File

SOURCE=.\DefaultProc.h
# End Source File
# Begin Source File

SOURCE=.\InputProc.h
# End Source File
# Begin Source File

SOURCE=.\Network.h
# End Source File
# Begin Source File

SOURCE=.\OutputProc.h
# End Source File
# Begin Source File

SOURCE=.\ParseLine.h
# End Source File
# Begin Source File

SOURCE=.\ParseValue.h
# End Source File
# Begin Source File

SOURCE=.\SignalProcessing.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\XAerosolResp.h
# End Source File
# Begin Source File

SOURCE=.\XAnimationStop.h
# End Source File
# Begin Source File

SOURCE=.\XCollDetSegResp.h
# End Source File
# Begin Source File

SOURCE=.\XCollDetVolResp.h
# End Source File
# Begin Source File

SOURCE=.\XEventNotification.h
# End Source File
# Begin Source File

SOURCE=.\XHatHotResp.h
# End Source File
# Begin Source File

SOURCE=.\XHatHotXResp.h
# End Source File
# Begin Source File

SOURCE=.\XIGMsg.h
# End Source File
# Begin Source File

SOURCE=.\XLosResp.h
# End Source File
# Begin Source File

SOURCE=.\XLosXResp.h
# End Source File
# Begin Source File

SOURCE=.\XMaritimeSurfaceResp.h
# End Source File
# Begin Source File

SOURCE=.\XPositionResp.h
# End Source File
# Begin Source File

SOURCE=.\XSensorResp.h
# End Source File
# Begin Source File

SOURCE=.\XSensorXResp.h
# End Source File
# Begin Source File

SOURCE=.\XSOF.h
# End Source File
# Begin Source File

SOURCE=.\XTerrestrialSurfaceResp.h
# End Source File
# Begin Source File

SOURCE=.\XWeatherCondResp.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
