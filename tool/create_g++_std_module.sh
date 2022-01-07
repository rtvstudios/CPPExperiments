#!/bin/bash

CXX=g++
DIR=`pwd`

if [ $# -eq 0 ]
then
    exit
fi

if [ $# -ge 1 ]
then
    MODULE=$1
fi

if [ $# -ge 2 ]
then
    CXX=$2
fi

if [ $# -ge 3 ]
then
    DIR=$3
fi

cd $DIR

if [ -f gcm.cache/usr/include/c++/11/$MODULE.gcm ]
then
    exit
fi

$CXX -std=c++20 -fmodules-ts -xc++-system-header $MODULE


