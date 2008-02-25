#################################
#
#  This makefile is used to create the CigiTestHost Executable
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

OBJ_FILES=MiniHost.o \
Callbacks.o \
DefaultProc.o \
InputProc.o \
Network.o \
OutputProc.o \
ParseLine.o \
ParseValue.o \
StdAfx.o \
XAerosolResp.o \
XAnimationStop.o \
XCollDetSegResp.o \
XCollDetVolResp.o \
XEventNotification.o \
XHatHotResp.o \
XHatHotXResp.o \
XIGMsg.o \
XLosResp.o \
XLosXResp.o \
XMaritimeSurfaceResp.o \
XPositionResp.o \
XSensorResp.o \
XSensorXResp.o \
XSOF.o \
XTerrestrialSurfaceResp.o \
XWeatherCondResp.o

.SUFFIXES: .cpp .c
 
.cpp.o:
	 $(CPP) $(CC_OPTS) $(INCLUDES) -c $<



LDFLAGS = -lc
LD = g++

all: CigiTestHost

clean:
	rm -f *.o
	rm -f *.so
	rm CigiTestHost

depend:
	makedepend -f makefile $(INCLUDES) \
	./Callbacks.cpp \
	./DefaultProc.cpp \
	./InputProc.cpp \
	./Network.cpp \
	./OutputProc.cpp \
	./ParseLine.cpp \
	./ParseValue.cpp \
	./StdAfx.cpp \
	./XAerosolResp.cpp \
	./XAnimationStop.cpp \
	./XCollDetSegResp.cpp \
	./XCollDetVolResp.cpp \
	./XEventNotification.cpp \
	./XHatHotResp.cpp \
	./XHatHotXResp.cpp \
	./XIGMsg.cpp \
	./XLosResp.cpp \
	./XLosXResp.cpp \
	./XMaritimeSurfaceResp.cpp \
	./XPositionResp.cpp \
	./XSensorResp.cpp \
	./XSensorXResp.cpp \
	./XSOF.cpp \
	./XTerrestrialSurfaceResp.cpp \
	./XWeatherCondResp.cpp
	build_dependencies -f makefile -s ./MiniHost.cpp
#
#  How to make CigiTestHost
#

CigiTestHost: makefile $(OBJ_FILES) $(LIB_FILES)
	$(LD) \
	-o CigiTestHost \
	$(OBJ_FILES) \
	$(LIB_FILES) -lm -lpthread \
	`pkg-config --libs cigicl`


#
#
# DO NOT DELETE

