#!/bin/bash

function build
{
    file=$1
    biny=$(basename $file .cxx)

    echo "building $biny ..."
    case $(uname -s) in
    Linux)
        g++ -o $biny $file -I ../../../include -L ../../../lib -laint -Wl,-rpath,../../../lib
        ;;
    esac
    echo "building $biny ... done."
}

build example.cxx  

# eof
