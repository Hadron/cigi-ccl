#################################
#
#  This makefile is used to create the TestIG Executable
#  It depends on the variables CC, CPP, and 
#  the CFLAGS, CCFLAGS being defined, along with
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

OBJ_FILES=TestIG.o \
DefaultProc.o \
Network.o \
ParseLine.o \
ParseValue.o \
TestGen.o \
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
XTerrestrialSurfaceCtrl.o \
XTrajectory.o \
XViewCtrl.o \
XViewDef.o \
XWaveCtrl.o \
XWeatherCtrl.o

.SUFFIXES: .cpp .c
 
.cpp.o:
	 $(CPP) $(CC_OPTS) $(INCLUDES) -c $<


LDFLAGS = -lc
LD = g++

all: CigiTestIG

clean:
	rm -f *.o
	rm -f *.so
	rm CigiTestIG

depend:
	makedepend -f makefile $(INCLUDES) \
	./DefaultProc.cpp \
	./Network.cpp \
	./ParseLine.cpp \
	./ParseValue.cpp \
	./TestGen.cpp \
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
	./XTerrestrialSurfaceCtrl.cpp \
	./XTrajectory.cpp \
	./XViewCtrl.cpp \
	./XViewDef.cpp \
	./XWaveCtrl.cpp \
	./XWeatherCtrl.cpp
	build_dependencies -f makefile -s ./TestIG.cpp
#
#  How to make MiniHost
#

CigiTestIG: makefile $(OBJ_FILES) $(LIB_FILES)
	$(LD) \
	-o CigiTestIG \
	$(OBJ_FILES) \
	$(LIB_FILES) -lm -lpthread \
	`pkg-config --libs cigicl`


#
#
# DO NOT DELETE

