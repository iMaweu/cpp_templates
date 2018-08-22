#!/bin/bash
set -x
PROJECT_ROOT=`pwd`

# compile chapter object(s)
g++ -o0 -std=c++17 -I./include -c -fPIC -Wall \
-o objs/chapter2.o src/chapter2.cpp

# generate shared libraries
ld -shared objs/chapter2.o -o objs/libchapter2.so

# build main
g++ -o0 -std=c++17 -Wall \
-I./include -L./objs \
-Wl,-rpath=$PROJECT_ROOT/objs \
-lchapter2 \
src/main.cpp -o cpp_temp_exe

