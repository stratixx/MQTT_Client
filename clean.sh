#!/bin/bash
for file in CMakeCache.txt CMakeFiles/ Makefile cmake_install.cmake lib/ bin/ *.vcxproj* *.sln Win32/ Debug/ *.dir/ Release/
do
    ls ./*/$file
    rm -f -r ./*/$file
done