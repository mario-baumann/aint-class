#!/bin/sh
##
 #  This file is part of aint.
 #
 #  aint provides a C++ class for arbitrary long integers which can be
 #  used the same way as the C/C++ integer types (e.g. int or long),
 #  but has no restriction on the length (if there is enough memory).
 #  Aim of this project is to include fast integer multiplications
 #  like the Toom-Cook algorithm or the Schoenhage-Strassen algorithm.
 #  Copyright (C) 2014 Mario Baumann (mario-baumann@web.de)
 #
 #  aint is free software: you can redistribute it and/or modify it
 #  under the terms of the GNU General Public License as published by
 #  the Free Software Foundation, either version 3 of the License, or
 #  (at your option) any later version.
 #
 #  aint is distributed in the hope that it will be useful, but
 #  WITHOUT ANY WARRANTY; without even the implied warranty of
 #  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 #  General Public License for more details.
 #
 #  You should have received a copy of the GNU General Public License
 #  along with aint.  If not, see <http://www.gnu.org/licenses/>.
 #
 ###########################################################################

# shell script to build aint project

run_cmake() {
    echo "+ cmake $@"
    cmake "$@"
}

if [ "_$1" = "_" ]; then
    echo "Usage: $(basename $0) SRC_DIR [OPTION]"
    echo " "
    echo "How to use:"
    echo "    mkdir <build-folder>"
    echo "    cd <build-folder>"
    echo "    $(basename $0) <path-to-aint-sources> [OPTION]"
    echo " "
    echo "Options:"
    echo "    -r ..... Release build (default)"
    echo "    -d ..... Debug build"
    echo "    -i8 .... Uses int size  8 for single component"
    echo "    -i16 ... Uses int size 16 for single component"
    echo "    -i32 ... Uses int size 32 for single component"
    exit 0
fi

BUILD_TYPE="Release"
while [ $# -gt 0 ]
do
    case '_'$1 in
    _-r)
        BUILD_TYPE="Release"
        ;;
    _-d)
        BUILD_TYPE="Debug"
        ;;
    _-i8)
        SINGLE_SIZE="8"
        ;;
    _-i16)
        SINGLE_SIZE="16"
        ;;
    _-i32)
        SINGLE_SIZE="32"
        ;;
    *)
        SOURCE_DIR=$1
        ;;
    esac
    shift
done      

if [ ! -d ${SOURCE_DIR} ]; then
    echo "ERROR: source folder ${SOURCE_DIR} does not exist!"
    exit 1
fi

case '_'$(uname -s) in
_CYGWIN*)
    CXX="$(which x86_64-w64-mingw32-g++.exe)"
    if [ "_${CXX}" != "_" ]; then
        export CXX
    fi
    BOOST_ROOT="/usr/x86_64-w64-mingw32/sys-root/mingw"
    if [ -d ${BOOST_ROOT} ]; then
        export BOOST_ROOT
    fi
    ;;
esac

run_cmake \
    -G "Eclipse CDT4 - Unix Makefiles" \
    -D "CMAKE_BUILD_TYPE=${BUILD_TYPE}" \
    -D "_ECLIPSE_VERSION=4.3" \
    -D "AINT_SINGLE_SIZE=${SINGLE_SIZE}" \
    -D "CMAKE_CXX_COMPILER_ARG1=-std=c++11" \
    -D "CMAKE_ECLIPSE_MAKE_ARGUMENTS=-j4 --no-print-directory" \
    -D "CMAKE_INSTALL_PREFIX=$(pwd)/install" \
    ${SOURCE_DIR}

# eof
