#!/bin/sh
# shell script to build aint project on linux and cygwin

run_cmake() {
    echo "+ cmake $@"
    cmake "$@"
}

if [ $(echo $HOME | grep -c -e '^/cygdrive/') -gt 0 ]; then
    BUILD_ARCH="cygwin"
else
    BUILD_ARCH="linux"
fi
echo "BUILD_ARCH: $BUILD_ARCH"

BUILD_TYPE="Debug"
BUILD_TYPE="Release"
echo "BUILD_TYPE: $BUILD_TYPE"

DEVEL_DIRY=$(dirname $(readlink -f "$0"))
echo "DEVEL_DIRY: $DEVEL_DIRY"

BUILD_DIRY="$(dirname $DEVEL_DIRY)/${BUILD_ARCH}-eclipse"
echo "BUILD_DIRY: $BUILD_DIRY"

rm -rf   $BUILD_DIRY
mkdir -p $BUILD_DIRY
cd       $BUILD_DIRY

run_cmake \
    -G "Eclipse CDT4 - Unix Makefiles" \
    -D "CMAKE_BUILD_TYPE=${BUILD_TYPE}" \
    -D "_ECLIPSE_VERSION=4.3" \
    -D "CMAKE_CXX_COMPILER_ARG1=-std=c++11" \
    -D "CMAKE_ECLIPSE_MAKE_ARGUMENTS=-j4 --no-print-directory" \
    -D "CMAKE_INSTALL_PREFIX=/tmp" \
    $DEVEL_DIRY
if [ -f Makefile ]; then
    make -j 4
fi
#

