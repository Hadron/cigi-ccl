SET(MINIHOST_HDRS
AnimStop.h
DefaultProc.h
Network.h
SOFP.h
)
  
SET(MINIHOST_SRCS
AnimStop.cpp
DefaultProc.cpp
MiniHost.cpp
Network.cpp
SOFP.cpp
)

INCLUDE_DIRECTORIES(../../include)

ADD_EXECUTABLE(CigiMiniHost ${MINIHOST_HDRS} ${MINIHOST_SRCS})
TARGET_LINK_LIBRARIES(CigiMiniHost cigicl-shared tinyxml)

INSTALL(TARGETS CigiMiniHost DESTINATION bin)
