#!/usr/local/bin/bash

folderName=${PWD##*/}

echo
echo "Cleaning..."
make clean

echo
echo "Building..."
make

echo 
echo
#echo "students10.txt" | ./${folderName}.out
./${folderName}.out