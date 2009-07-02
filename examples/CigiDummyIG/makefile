#################################
#
#  This makefile is used to create the CigiDummyIG Executable
#  It depends on the variables CC, CPP, F77 and 
#  the CFLAGS, CCFLAGS, FFLAGS being defined, along with
#  LIBDIR to indicate the current platform/option value.
#
#################################

CPP=g++
cc=gcc

LIBDIR =LINUX_9

CCL_INC=`pkg-config --cflags cigicl`

TINY_XML=../tinyxml

INCLUDES=$(CCL_INC) -I$(TINY_XML) 

LIB_FILES = $(TINY_XML)/TinyXML.a


CC_OPTS= -Wall -g -D__cplusplus
C_OPTS= -g

CFLAGS  = $(C_OPTS) $(INCLUDES)
CCFLAGS = $(CC_OPTS) $(INCLUDES)

OBJ_FILES=DummyIG.o \
DefaultProc.o \
Network.o \
XArtPartCtrl.o \
XAtmosCtrl.o \
XCelestialCtrl.o \
XCollDetSegDef.o \
XCollDetVolDef.o \
XCompCtrl.o \
XConfClampEntityCtrl.o \
XEarthModelDef.o \
XEntityCtrl.o \
XEnvCondReq.o \
XEnvRgnCtrl.o \
XEventNotification.o \
XHatHotReq.o \
XIGCtrl.o \
XLosSegReq.o \
XLosVectReq.o \
XMaritimeSurfaceCtrl.o \
XMotionTrackCtrl.o \
XPostionReq.o \
XRateCtrl.o \
XSensorCtrl.o \
XShortArtPartCtrl.o \
XShortCompCtrl.o \
XShortSymbolCtrlV3_3.o \
XSymbolCircleDefV3_3.o \
XSymbolCloneV3_3.o \
XSymbolCtrlV3_3.o \
XSymbolLineDefV3_3.o \
XSymbolSurfaceDefV3_3.o \
XSymbolTextDefV3_3.o \
XTerrestrialSurfaceCtrl.o \
XTrajectory.o \
XViewCtrl.o \
XViewDef.o \
XWaveCtrl.o \
XWeatherCtrl.o \

.SUFFIXES: .cpp .c
 
.cpp.o:
	 $(CPP) $(CC_OPTS) $(INCLUDES) -c $<


LDFLAGS = -lc
LD = g++

all: CigiDummyIG

clean:
	rm -f *.o
	rm -f *.so
	rm CigiDummyIG

depend:
	makedepend -f makefile $(INCLUDES) \
	./DefaultProc.cpp \
	./Network.cpp \
	./XArtPartCtrl.cpp \
	./XAtmosCtrl.cpp \
	./XCelestialCtrl.cpp \
	./XCollDetSegDef.cpp \
	./XCollDetVolDef.cpp \
	./XCompCtrl.cpp \
	./XConfClampEntityCtrl.cpp \
	./XEarthModelDef.cpp \
	./XEntityCtrl.cpp \
	./XEnvCondReq.cpp \
	./XEnvRgnCtrl.cpp \
	./XEventNotification.cpp \
	./XHatHotReq.cpp \
	./XIGCtrl.cpp \
	./XLosSegReq.cpp \
	./XLosVectReq.cpp \
	./XMaritimeSurfaceCtrl.cpp \
	./XMotionTrackCtrl.cpp \
	./XPostionReq.cpp \
	./XRateCtrl.cpp \
	./XSensorCtrl.cpp \
	./XShortArtPartCtrl.cpp \
	./XShortCompCtrl.cpp \
	./XShortArtPartCtrl.cpp \
	./XShortCompCtrl.cpp \
	./XShortSymbolCtrlV3_3.cpp \
	./XSymbolCircleDefV3_3.cpp \
	./XSymbolCloneV3_3.cpp \
	./XSymbolCtrlV3_3.cpp \
	./XSymbolLineDefV3_3.cpp \
	./XSymbolSurfaceDefV3_3.cpp \
	./XSymbolTextDefV3_3.cpp \
	./XTerrestrialSurfaceCtrl.cpp \
	./XTrajectory.cpp \
	./XViewCtrl.cpp \
	./XViewDef.cpp \
	./XWaveCtrl.cpp \
	./XWeatherCtrl.cpp
	build_dependencies -f makefile -s ./DummyIG.cpp
#
#  How to make MiniHost
#

CigiDummyIG: makefile $(OBJ_FILES) $(LIB_FILES)
	$(LD) \
	-o CigiDummyIG \
	$(OBJ_FILES) \
	$(LIB_FILES) -lm -lpthread \
	`pkg-config --libs cigicl`


#
#
# DO NOT DELETE

