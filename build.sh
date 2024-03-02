#!/bin/bash
#Directory for your Header files
mkdir HEADER_FILES
mv *.h HEADER_FILES/
#Directory for your Source files
mkdir SOURCE_FILES
mv *.c SOURCE_FILES/
mkdir build/

cd build/
cmake ..
make
cd ..
./build/executable "$@"

