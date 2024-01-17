#!/bin/bash
mkdir build/
cd build/
cmake ..
make
cd ..
./build/executable "$@"

