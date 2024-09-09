#!/bin/sh

mkdir build
mkdir lib
git clone https://github.com/catchorg/Catch2.git lib/Catch2
cd build || exit 
cmake ..
make
