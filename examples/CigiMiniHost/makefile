#################################
#
#  This makefile is used to create the CigiMiniHost Executable
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
DefaultProc.o \
SOFP.o \
AnimStop.o \
Network.o

.SUFFIXES: .cpp .c
 
.cpp.o:
	 $(CPP) $(CC_OPTS) $(INCLUDES) -c $<



LDFLAGS = -lc
LD = g++

all: CigiMiniHost

clean:
	rm -f *.o
	rm -f *.so
	rm CigiMiniHost

depend:
	makedepend -f makefile $(INCLUDES) \
	   ./MiniHost.cpp \
	   ./DefaultProc.cpp \
	   ./SOFP.cpp \
	   ./AnimStop.cpp \
	   ./Network.cpp
	build_dependencies -f makefile -s ./MiniHost.cpp
#
#  How to make MiniHost
#

CigiMiniHost: makefile $(OBJ_FILES) $(LIB_FILES)
	$(LD) \
	-o CigiMiniHost \
	$(OBJ_FILES) \
	$(LIB_FILES) -lm -lpthread \
	`pkg-config --libs cigicl`


#
#
# DO NOT DELETE

