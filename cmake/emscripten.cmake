SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR x86)

SET(CMAKE_CROSSCOMPILING TRUE)
SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS FALSE)

# Unset WIN32 and APPLE
SET(WIN32)
SET(APPLE)

# Emscripten is able to mimic Unix systems
SET(UNIX 1)

if (CMAKE_HOST_WIN32)
  SET(CMAKE_C_COMPILER   "emcc.bat")
  SET(CMAKE_CXX_COMPILER "em++.bat")
else ()
  SET(CMAKE_C_COMPILER   "emcc")
  SET(CMAKE_CXX_COMPILER "em++")
endif()

if(NOT DEFINED CMAKE_AR)
  find_program(CMAKE_AR NAMES emar)
endif()
if(NOT DEFINED CMAKE_RANLIB)
  find_program(CMAKE_RANLIB NAMES emranlib)
endif()

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
