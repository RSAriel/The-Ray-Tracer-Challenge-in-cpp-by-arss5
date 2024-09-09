#!/bin/sh

mkdir build
mkdir lib
git clone https://github.com/catchorg/Catch2.git lib
cd build || exit 
cmake ..
make
