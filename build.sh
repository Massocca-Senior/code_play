#!/bin/sh
[ -e build ] || mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ../
#cmake -DCMAKE_BUILD_TYPE=Release ../
make VERBOSE=true
