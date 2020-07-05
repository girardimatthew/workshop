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

echo "Abba 0 0" | ./${folderName}.out