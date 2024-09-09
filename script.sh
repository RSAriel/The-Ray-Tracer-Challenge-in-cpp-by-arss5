#!/bin/sh

mkdir build
mkdir lib
cd build || exit 
cmake ..
make
