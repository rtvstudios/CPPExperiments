#!/bin/bash

mkdir -p build/linux
cd build/linux
cmake -DCMAKE_CXX_COMPILER=g++-11 ../..
