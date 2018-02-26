# Sample toolchain file for building for Windows from an Ubuntu Linux system.
#
# Typical usage:
#    *) install cross compiler: `sudo apt-get install mingw-w64 g++-mingw-w64`
#    *) cd build
#    *) cmake -DCMAKE_TOOLCHAIN_FILE=~/Toolchain-Ubuntu-mingw32.cmake ..

set(CMAKE_SYSTEM_NAME Windows)
set(TOOLCHAIN_PREFIX i686-w64-mingw32)

# cross compilers to use for C and C++
set(CMAKE_C_COMPILER   "/usr/bin/${TOOLCHAIN_PREFIX}-gcc.exe")
set(CMAKE_CXX_COMPILER "/usr/bin/${TOOLCHAIN_PREFIX}-g++.exe")
set(CMAKE_RC_COMPILER  "/usr/bin/${TOOLCHAIN_PREFIX}-windres.exe")

# target environment on the build host system
#   set 1st to dir with the cross compiler's C/C++ headers/libs
set(CMAKE_FIND_ROOT_PATH /usr/${TOOLCHAIN_PREFIX})

# modify default behavior of FIND_XXX() commands to
# search for headers/libs in the target environment and
# search for programs in the build host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(X_ROOT "/usr/${TOOLCHAIN_PREFIX}/sys-root/mingw")
if(IS_DIRECTORY "${X_ROOT}")
    set(ENV{BOOST_ROOT}   "${X_ROOT}")
    set(ENV{CPPUNIT_ROOT} "${X_ROOT}")
endif()

