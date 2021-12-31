#!/bin/bash

mkdir -p build/linux
pushd .
cd build/linux
cmake -DCMAKE_CXX_COMPILER=g++-11 ../..
popd

