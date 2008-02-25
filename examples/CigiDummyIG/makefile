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

./DefaultProc.o: DefaultProc.h
./DefaultProc.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./DefaultProc.o: /usr/local/include/cigicl/CigiBasePacket.h
./DefaultProc.o: /usr/local/include/cigicl/CigiTypes.h
./DefaultProc.o: /usr/local/include/cigicl/CigiErrorCodes.h
./DefaultProc.o: /usr/local/include/cigicl/CigiDefaultPacket.h
./Network.o: Network.h /usr/include/sys/types.h /usr/include/features.h
./Network.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./Network.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./Network.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./Network.o: /usr/include/bits/typesizes.h /usr/include/time.h
./Network.o: /usr/include/sys/socket.h /usr/include/sys/uio.h
./Network.o: /usr/include/bits/uio.h /usr/include/bits/socket.h
./Network.o: /usr/include/limits.h
./Network.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/limits.h
./Network.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
./Network.o: /usr/include/asm/sockios.h /usr/include/netinet/in.h
./Network.o: /usr/include/stdint.h /usr/include/bits/wchar.h
./Network.o: /usr/include/bits/in.h /usr/include/endian.h
./Network.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
./Network.o: /usr/include/arpa/inet.h /usr/include/unistd.h
./Network.o: /usr/include/bits/posix_opt.h /usr/include/bits/confname.h
./Network.o: /usr/include/netdb.h /usr/include/bits/netdb.h
./Network.o: /usr/include/stdio.h /usr/include/libio.h
./Network.o: /usr/include/_G_config.h /usr/include/wchar.h
./Network.o: /usr/include/gconv.h
./Network.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./Network.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./Network.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
./XArtPartCtrl.o: XArtPartCtrl.h
./XArtPartCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XArtPartCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XArtPartCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XArtPartCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XArtPartCtrl.o: /usr/local/include/cigicl/CigiArtPartCtrlV3.h
./XArtPartCtrl.o: /usr/local/include/cigicl/CigiBaseArtPartCtrl.h
./XArtPartCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XArtPartCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XArtPartCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XArtPartCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XArtPartCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XArtPartCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XArtPartCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XArtPartCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XArtPartCtrl.o: /usr/include/bits/stdio_lim.h
./XArtPartCtrl.o: /usr/include/bits/sys_errlist.h
./XAtmosCtrl.o: XAtmosCtrl.h
./XAtmosCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XAtmosCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XAtmosCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XAtmosCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XAtmosCtrl.o: /usr/local/include/cigicl/CigiAtmosCtrl.h
./XAtmosCtrl.o: /usr/local/include/cigicl/CigiBaseEnvCtrl.h
./XAtmosCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XAtmosCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XAtmosCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XAtmosCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XAtmosCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XAtmosCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XAtmosCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XAtmosCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XAtmosCtrl.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./XCelestialCtrl.o: XCelestialCtrl.h
./XCelestialCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XCelestialCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XCelestialCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XCelestialCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XCelestialCtrl.o: /usr/local/include/cigicl/CigiCelestialCtrl.h
./XCelestialCtrl.o: /usr/local/include/cigicl/CigiBaseEnvCtrl.h
./XCelestialCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XCelestialCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XCelestialCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XCelestialCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XCelestialCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XCelestialCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XCelestialCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XCelestialCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XCelestialCtrl.o: /usr/include/bits/stdio_lim.h
./XCelestialCtrl.o: /usr/include/bits/sys_errlist.h
./XCollDetSegDef.o: XCollDetSegDef.h
./XCollDetSegDef.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XCollDetSegDef.o: /usr/local/include/cigicl/CigiBasePacket.h
./XCollDetSegDef.o: /usr/local/include/cigicl/CigiTypes.h
./XCollDetSegDef.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XCollDetSegDef.o: /usr/local/include/cigicl/CigiCollDetSegDefV3.h
./XCollDetSegDef.o: /usr/local/include/cigicl/CigiBaseCollDetSegDef.h
./XCollDetSegDef.o: /usr/include/stdio.h /usr/include/features.h
./XCollDetSegDef.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XCollDetSegDef.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XCollDetSegDef.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XCollDetSegDef.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XCollDetSegDef.o: /usr/include/_G_config.h /usr/include/wchar.h
./XCollDetSegDef.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XCollDetSegDef.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XCollDetSegDef.o: /usr/include/bits/stdio_lim.h
./XCollDetSegDef.o: /usr/include/bits/sys_errlist.h
./XCollDetVolDef.o: XCollDetVolDef.h
./XCollDetVolDef.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XCollDetVolDef.o: /usr/local/include/cigicl/CigiBasePacket.h
./XCollDetVolDef.o: /usr/local/include/cigicl/CigiTypes.h
./XCollDetVolDef.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XCollDetVolDef.o: /usr/local/include/cigicl/CigiCollDetVolDefV3.h
./XCollDetVolDef.o: /usr/local/include/cigicl/CigiBaseCollDetVolDef.h
./XCollDetVolDef.o: /usr/include/stdio.h /usr/include/features.h
./XCollDetVolDef.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XCollDetVolDef.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XCollDetVolDef.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XCollDetVolDef.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XCollDetVolDef.o: /usr/include/_G_config.h /usr/include/wchar.h
./XCollDetVolDef.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XCollDetVolDef.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XCollDetVolDef.o: /usr/include/bits/stdio_lim.h
./XCollDetVolDef.o: /usr/include/bits/sys_errlist.h
./XCompCtrl.o: XCompCtrl.h /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XCompCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XCompCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XCompCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XCompCtrl.o: /usr/local/include/cigicl/CigiCompCtrlV3.h
./XCompCtrl.o: /usr/local/include/cigicl/CigiBaseCompCtrl.h
./XCompCtrl.o: /usr/local/include/cigicl/CigiExceptions.h
./XCompCtrl.o: /usr/local/include/cigicl/CigiException.h
./XCompCtrl.o: /usr/include/string.h /usr/include/features.h
./XCompCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XCompCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XCompCtrl.o: /usr/include/stdio.h /usr/include/bits/types.h
./XCompCtrl.o: /usr/include/bits/wordsize.h /usr/include/bits/typesizes.h
./XCompCtrl.o: /usr/include/libio.h /usr/include/_G_config.h
./XCompCtrl.o: /usr/include/wchar.h /usr/include/bits/wchar.h
./XCompCtrl.o: /usr/include/gconv.h
./XCompCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XCompCtrl.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./XConfClampEntityCtrl.o: XConfClampEntityCtrl.h
./XConfClampEntityCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XConfClampEntityCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XConfClampEntityCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XConfClampEntityCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XConfClampEntityCtrl.o: /usr/local/include/cigicl/CigiConfClampEntityCtrlV3.h
./XConfClampEntityCtrl.o: /usr/local/include/cigicl/CigiBaseConfClampEntityCtrl.h
./XConfClampEntityCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XConfClampEntityCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XConfClampEntityCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XConfClampEntityCtrl.o: /usr/include/bits/types.h
./XConfClampEntityCtrl.o: /usr/include/bits/wordsize.h
./XConfClampEntityCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XConfClampEntityCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XConfClampEntityCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XConfClampEntityCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XConfClampEntityCtrl.o: /usr/include/bits/stdio_lim.h
./XConfClampEntityCtrl.o: /usr/include/bits/sys_errlist.h
./XEarthModelDef.o: XEarthModelDef.h
./XEarthModelDef.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XEarthModelDef.o: /usr/local/include/cigicl/CigiBasePacket.h
./XEarthModelDef.o: /usr/local/include/cigicl/CigiTypes.h
./XEarthModelDef.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XEarthModelDef.o: /usr/local/include/cigicl/CigiEarthModelDefV3.h
./XEarthModelDef.o: /usr/local/include/cigicl/CigiBaseEarthModelDef.h
./XEarthModelDef.o: /usr/include/stdio.h /usr/include/features.h
./XEarthModelDef.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XEarthModelDef.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XEarthModelDef.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XEarthModelDef.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XEarthModelDef.o: /usr/include/_G_config.h /usr/include/wchar.h
./XEarthModelDef.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XEarthModelDef.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XEarthModelDef.o: /usr/include/bits/stdio_lim.h
./XEarthModelDef.o: /usr/include/bits/sys_errlist.h
./XEntityCtrl.o: XEntityCtrl.h
./XEntityCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XEntityCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XEntityCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XEntityCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XEntityCtrl.o: /usr/local/include/cigicl/CigiEntityCtrlV3.h
./XEntityCtrl.o: /usr/local/include/cigicl/CigiBaseEntityCtrl.h
./XEntityCtrl.o: /usr/local/include/cigicl/CigiAnimationTable.h
./XEntityCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XEntityCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XEntityCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XEntityCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XEntityCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XEntityCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XEntityCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XEntityCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XEntityCtrl.o: /usr/include/bits/stdio_lim.h
./XEntityCtrl.o: /usr/include/bits/sys_errlist.h
./XEnvCondReq.o: XEnvCondReq.h
./XEnvCondReq.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XEnvCondReq.o: /usr/local/include/cigicl/CigiBasePacket.h
./XEnvCondReq.o: /usr/local/include/cigicl/CigiTypes.h
./XEnvCondReq.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XEnvCondReq.o: /usr/local/include/cigicl/CigiEnvCondReqV3.h
./XEnvCondReq.o: /usr/local/include/cigicl/CigiBaseEnvCondReq.h
./XEnvCondReq.o: /usr/include/stdio.h /usr/include/features.h
./XEnvCondReq.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XEnvCondReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XEnvCondReq.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XEnvCondReq.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XEnvCondReq.o: /usr/include/_G_config.h /usr/include/wchar.h
./XEnvCondReq.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XEnvCondReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XEnvCondReq.o: /usr/include/bits/stdio_lim.h
./XEnvCondReq.o: /usr/include/bits/sys_errlist.h
./XEnvRgnCtrl.o: XEnvRgnCtrl.h
./XEnvRgnCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XEnvRgnCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XEnvRgnCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XEnvRgnCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XEnvRgnCtrl.o: /usr/local/include/cigicl/CigiEnvRgnCtrlV3.h
./XEnvRgnCtrl.o: /usr/local/include/cigicl/CigiBaseEnvRgnCtrl.h
./XEnvRgnCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XEnvRgnCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XEnvRgnCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XEnvRgnCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XEnvRgnCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XEnvRgnCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XEnvRgnCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XEnvRgnCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XEnvRgnCtrl.o: /usr/include/bits/stdio_lim.h
./XEnvRgnCtrl.o: /usr/include/bits/sys_errlist.h
./XEventNotification.o: XEventNotification.h
./XEventNotification.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XEventNotification.o: /usr/local/include/cigicl/CigiBasePacket.h
./XEventNotification.o: /usr/local/include/cigicl/CigiTypes.h
./XEventNotification.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XEventNotification.o: /usr/local/include/cigicl/CigiEventNotificationV3.h
./XEventNotification.o: /usr/local/include/cigicl/CigiBaseEventNotification.h
./XEventNotification.o: /usr/include/stdio.h /usr/include/features.h
./XEventNotification.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XEventNotification.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XEventNotification.o: /usr/include/bits/types.h
./XEventNotification.o: /usr/include/bits/wordsize.h
./XEventNotification.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XEventNotification.o: /usr/include/_G_config.h /usr/include/wchar.h
./XEventNotification.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XEventNotification.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XEventNotification.o: /usr/include/bits/stdio_lim.h
./XEventNotification.o: /usr/include/bits/sys_errlist.h
./XHatHotReq.o: XHatHotReq.h
./XHatHotReq.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XHatHotReq.o: /usr/local/include/cigicl/CigiBasePacket.h
./XHatHotReq.o: /usr/local/include/cigicl/CigiTypes.h
./XHatHotReq.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XHatHotReq.o: /usr/local/include/cigicl/CigiHatHotReqV3.h
./XHatHotReq.o: /usr/local/include/cigicl/CigiBaseHatHotReq.h
./XHatHotReq.o: /usr/include/stdio.h /usr/include/features.h
./XHatHotReq.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XHatHotReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XHatHotReq.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XHatHotReq.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XHatHotReq.o: /usr/include/_G_config.h /usr/include/wchar.h
./XHatHotReq.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XHatHotReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XHatHotReq.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./XIGCtrl.o: XIGCtrl.h /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XIGCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XIGCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XIGCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XIGCtrl.o: /usr/local/include/cigicl/CigiIGCtrlV3.h
./XIGCtrl.o: /usr/local/include/cigicl/CigiBaseIGCtrl.h /usr/include/stdio.h
./XIGCtrl.o: /usr/include/features.h /usr/include/sys/cdefs.h
./XIGCtrl.o: /usr/include/gnu/stubs.h
./XIGCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XIGCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XIGCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XIGCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XIGCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XIGCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XIGCtrl.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./XLosSegReq.o: XLosSegReq.h
./XLosSegReq.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XLosSegReq.o: /usr/local/include/cigicl/CigiBasePacket.h
./XLosSegReq.o: /usr/local/include/cigicl/CigiTypes.h
./XLosSegReq.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XLosSegReq.o: /usr/local/include/cigicl/CigiLosSegReqV3.h
./XLosSegReq.o: /usr/local/include/cigicl/CigiBaseLosSegReq.h
./XLosSegReq.o: /usr/include/stdio.h /usr/include/features.h
./XLosSegReq.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XLosSegReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XLosSegReq.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XLosSegReq.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XLosSegReq.o: /usr/include/_G_config.h /usr/include/wchar.h
./XLosSegReq.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XLosSegReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XLosSegReq.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./XLosVectReq.o: XLosVectReq.h
./XLosVectReq.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XLosVectReq.o: /usr/local/include/cigicl/CigiBasePacket.h
./XLosVectReq.o: /usr/local/include/cigicl/CigiTypes.h
./XLosVectReq.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XLosVectReq.o: /usr/local/include/cigicl/CigiLosVectReqV3.h
./XLosVectReq.o: /usr/local/include/cigicl/CigiBaseLosVectReq.h
./XLosVectReq.o: /usr/include/stdio.h /usr/include/features.h
./XLosVectReq.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XLosVectReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XLosVectReq.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XLosVectReq.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XLosVectReq.o: /usr/include/_G_config.h /usr/include/wchar.h
./XLosVectReq.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XLosVectReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XLosVectReq.o: /usr/include/bits/stdio_lim.h
./XLosVectReq.o: /usr/include/bits/sys_errlist.h
./XMaritimeSurfaceCtrl.o: XMaritimeSurfaceCtrl.h
./XMaritimeSurfaceCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XMaritimeSurfaceCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XMaritimeSurfaceCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XMaritimeSurfaceCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XMaritimeSurfaceCtrl.o: /usr/local/include/cigicl/CigiMaritimeSurfaceCtrlV3.h
./XMaritimeSurfaceCtrl.o: /usr/local/include/cigicl/CigiBaseMaritimeSurfaceCtrl.h
./XMaritimeSurfaceCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XMaritimeSurfaceCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XMaritimeSurfaceCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XMaritimeSurfaceCtrl.o: /usr/include/bits/types.h
./XMaritimeSurfaceCtrl.o: /usr/include/bits/wordsize.h
./XMaritimeSurfaceCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XMaritimeSurfaceCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XMaritimeSurfaceCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XMaritimeSurfaceCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XMaritimeSurfaceCtrl.o: /usr/include/bits/stdio_lim.h
./XMaritimeSurfaceCtrl.o: /usr/include/bits/sys_errlist.h
./XMotionTrackCtrl.o: XMotionTrackCtrl.h
./XMotionTrackCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XMotionTrackCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XMotionTrackCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XMotionTrackCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XMotionTrackCtrl.o: /usr/local/include/cigicl/CigiMotionTrackCtrlV3.h
./XMotionTrackCtrl.o: /usr/local/include/cigicl/CigiBaseMotionTrackCtrl.h
./XMotionTrackCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XMotionTrackCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XMotionTrackCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XMotionTrackCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XMotionTrackCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XMotionTrackCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XMotionTrackCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XMotionTrackCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XMotionTrackCtrl.o: /usr/include/bits/stdio_lim.h
./XMotionTrackCtrl.o: /usr/include/bits/sys_errlist.h
./XPostionReq.o: XPostionReq.h
./XPostionReq.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XPostionReq.o: /usr/local/include/cigicl/CigiBasePacket.h
./XPostionReq.o: /usr/local/include/cigicl/CigiTypes.h
./XPostionReq.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XPostionReq.o: /usr/local/include/cigicl/CigiPositionReqV3.h
./XPostionReq.o: /usr/local/include/cigicl/CigiBasePositionReq.h
./XPostionReq.o: /usr/include/stdio.h /usr/include/features.h
./XPostionReq.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XPostionReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XPostionReq.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XPostionReq.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XPostionReq.o: /usr/include/_G_config.h /usr/include/wchar.h
./XPostionReq.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XPostionReq.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XPostionReq.o: /usr/include/bits/stdio_lim.h
./XPostionReq.o: /usr/include/bits/sys_errlist.h
./XRateCtrl.o: XRateCtrl.h /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XRateCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XRateCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XRateCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XRateCtrl.o: /usr/local/include/cigicl/CigiRateCtrlV3.h
./XRateCtrl.o: /usr/local/include/cigicl/CigiBaseRateCtrl.h
./XRateCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XRateCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XRateCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XRateCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XRateCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XRateCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XRateCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XRateCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XRateCtrl.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./XSensorCtrl.o: XSensorCtrl.h
./XSensorCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XSensorCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XSensorCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XSensorCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XSensorCtrl.o: /usr/local/include/cigicl/CigiSensorCtrlV3.h
./XSensorCtrl.o: /usr/local/include/cigicl/CigiBaseSensorCtrl.h
./XSensorCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XSensorCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XSensorCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XSensorCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XSensorCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XSensorCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XSensorCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XSensorCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XSensorCtrl.o: /usr/include/bits/stdio_lim.h
./XSensorCtrl.o: /usr/include/bits/sys_errlist.h
./XShortArtPartCtrl.o: XShortArtPartCtrl.h
./XShortArtPartCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XShortArtPartCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XShortArtPartCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XShortArtPartCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XShortArtPartCtrl.o: /usr/local/include/cigicl/CigiShortArtPartCtrlV3.h
./XShortArtPartCtrl.o: /usr/local/include/cigicl/CigiBaseShortArtPartCtrl.h
./XShortArtPartCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XShortArtPartCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XShortArtPartCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XShortArtPartCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XShortArtPartCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XShortArtPartCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XShortArtPartCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XShortArtPartCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XShortArtPartCtrl.o: /usr/include/bits/stdio_lim.h
./XShortArtPartCtrl.o: /usr/include/bits/sys_errlist.h
./XShortCompCtrl.o: XShortCompCtrl.h
./XShortCompCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XShortCompCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XShortCompCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XShortCompCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XShortCompCtrl.o: /usr/local/include/cigicl/CigiShortCompCtrlV3.h
./XShortCompCtrl.o: /usr/local/include/cigicl/CigiBaseCompCtrl.h
./XShortCompCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XShortCompCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XShortCompCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XShortCompCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XShortCompCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XShortCompCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XShortCompCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XShortCompCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XShortCompCtrl.o: /usr/include/bits/stdio_lim.h
./XShortCompCtrl.o: /usr/include/bits/sys_errlist.h
./XTerrestrialSurfaceCtrl.o: XTerrestrialSurfaceCtrl.h
./XTerrestrialSurfaceCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XTerrestrialSurfaceCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XTerrestrialSurfaceCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XTerrestrialSurfaceCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XTerrestrialSurfaceCtrl.o: /usr/local/include/cigicl/CigiTerrestrialSurfaceCtrlV3.h
./XTerrestrialSurfaceCtrl.o: /usr/local/include/cigicl/CigiBaseTerrestrialSurfaceCtrl.h
./XTerrestrialSurfaceCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XTerrestrialSurfaceCtrl.o: /usr/include/sys/cdefs.h
./XTerrestrialSurfaceCtrl.o: /usr/include/gnu/stubs.h
./XTerrestrialSurfaceCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XTerrestrialSurfaceCtrl.o: /usr/include/bits/types.h
./XTerrestrialSurfaceCtrl.o: /usr/include/bits/wordsize.h
./XTerrestrialSurfaceCtrl.o: /usr/include/bits/typesizes.h
./XTerrestrialSurfaceCtrl.o: /usr/include/libio.h /usr/include/_G_config.h
./XTerrestrialSurfaceCtrl.o: /usr/include/wchar.h /usr/include/bits/wchar.h
./XTerrestrialSurfaceCtrl.o: /usr/include/gconv.h
./XTerrestrialSurfaceCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XTerrestrialSurfaceCtrl.o: /usr/include/bits/stdio_lim.h
./XTerrestrialSurfaceCtrl.o: /usr/include/bits/sys_errlist.h
./XTrajectory.o: XTrajectory.h
./XTrajectory.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XTrajectory.o: /usr/local/include/cigicl/CigiBasePacket.h
./XTrajectory.o: /usr/local/include/cigicl/CigiTypes.h
./XTrajectory.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XTrajectory.o: /usr/local/include/cigicl/CigiTrajectoryDefV3.h
./XTrajectory.o: /usr/local/include/cigicl/CigiBaseTrajectoryDef.h
./XTrajectory.o: /usr/include/stdio.h /usr/include/features.h
./XTrajectory.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XTrajectory.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XTrajectory.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XTrajectory.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XTrajectory.o: /usr/include/_G_config.h /usr/include/wchar.h
./XTrajectory.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XTrajectory.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XTrajectory.o: /usr/include/bits/stdio_lim.h
./XTrajectory.o: /usr/include/bits/sys_errlist.h
./XViewCtrl.o: XViewCtrl.h /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XViewCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XViewCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XViewCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XViewCtrl.o: /usr/local/include/cigicl/CigiViewCtrlV3.h
./XViewCtrl.o: /usr/local/include/cigicl/CigiBaseViewCtrl.h
./XViewCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XViewCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XViewCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XViewCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XViewCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XViewCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XViewCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XViewCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XViewCtrl.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./XViewDef.o: XViewDef.h /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XViewDef.o: /usr/local/include/cigicl/CigiBasePacket.h
./XViewDef.o: /usr/local/include/cigicl/CigiTypes.h
./XViewDef.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XViewDef.o: /usr/local/include/cigicl/CigiViewDefV3.h
./XViewDef.o: /usr/local/include/cigicl/CigiBaseViewDef.h
./XViewDef.o: /usr/include/stdio.h /usr/include/features.h
./XViewDef.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XViewDef.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XViewDef.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XViewDef.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XViewDef.o: /usr/include/_G_config.h /usr/include/wchar.h
./XViewDef.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XViewDef.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XViewDef.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./XWaveCtrl.o: XWaveCtrl.h /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XWaveCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XWaveCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XWaveCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XWaveCtrl.o: /usr/local/include/cigicl/CigiWaveCtrlV3.h
./XWaveCtrl.o: /usr/local/include/cigicl/CigiBaseWaveCtrl.h
./XWaveCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XWaveCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XWaveCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XWaveCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XWaveCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XWaveCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XWaveCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XWaveCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XWaveCtrl.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
./XWeatherCtrl.o: XWeatherCtrl.h
./XWeatherCtrl.o: /usr/local/include/cigicl/CigiBaseEventProcessor.h
./XWeatherCtrl.o: /usr/local/include/cigicl/CigiBasePacket.h
./XWeatherCtrl.o: /usr/local/include/cigicl/CigiTypes.h
./XWeatherCtrl.o: /usr/local/include/cigicl/CigiErrorCodes.h
./XWeatherCtrl.o: /usr/local/include/cigicl/CigiWeatherCtrlV3.h
./XWeatherCtrl.o: /usr/local/include/cigicl/CigiBaseWeatherCtrl.h
./XWeatherCtrl.o: /usr/include/stdio.h /usr/include/features.h
./XWeatherCtrl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
./XWeatherCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stddef.h
./XWeatherCtrl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
./XWeatherCtrl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
./XWeatherCtrl.o: /usr/include/_G_config.h /usr/include/wchar.h
./XWeatherCtrl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
./XWeatherCtrl.o: /usr/lib/gcc/i386-redhat-linux/3.4.2/include/stdarg.h
./XWeatherCtrl.o: /usr/include/bits/stdio_lim.h
./XWeatherCtrl.o: /usr/include/bits/sys_errlist.h
