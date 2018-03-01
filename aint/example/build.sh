#!/bin/bash

function build_mingw
{
    CXX=${1}-g++.exe
    DLLTOOL=${1}-dlltool.exe
    SOURCE=$2
    OUTPUT=$3

    CXX_LIB=$(${CXX} -print-file-name=libstdc++.a)
    PTH_LIB=$(${CXX} -print-file-name=libpthread.a)
    DLL_PATH=$(cygpath -m ../../../lib/aint.dll)
    DLL_PATH_MANGLE=$(echo ${DLL_PATH} | sed 's@/@_@g' | sed 's@:@_@')
    DLL_PATH_DOS=$(echo ${DLL_PATH} | sed 's@/@\\\\@g')
    echo ${DLL_PATH_MANGLE} | awk -v d=\" '{ print "LIBRARY " d $1 d }' > a.def
    cat ../../../lib/aint.def >> a.def
    ${DLLTOOL} --output-lib a.lib --input-def a.def
    ${CXX} -o a.exe ${SOURCE} -std=c++11 -I ../../../include a.lib -static-libgcc ${CXX_LIB} ${PTH_LIB}
    cat a.exe | sed "s@${DLL_PATH_MANGLE}@${DLL_PATH_DOS}@" > ${OUTPUT}
    chmod 755 ${OUTPUT}
    rm -f a.exe a.lib a.def
}

function build
{
    file=$1
    biny=$(basename $file .cxx)

    echo "building $biny ..."
    case $(uname -s) in
    Linux|Darwin)
        g++ -o $biny $file -std=c++11 -I ../../../include -L ../../../lib -laint -Wl,-rpath,../../../lib
        ;;
    CYGWIN*)
        if [ "_$(which i686-w64-mingw32-g++.exe 2> /dev/null)" != "_" ]; then
            build_mingw i686-w64-mingw32 $file ${biny}_32.exe
        fi
        if [ "_$(which x86_64-w64-mingw32-g++.exe 2> /dev/null)" != "_" ]; then
            build_mingw x86_64-w64-mingw32 $file ${biny}_64.exe
        fi
        ;;
    esac
    echo "building $biny ... done."
}

build example.cxx  

# eof
