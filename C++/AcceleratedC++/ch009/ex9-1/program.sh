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

# echo "Rick 99 89 78 89 78 89 78 89 79" | ./${folderName}.out

cat "students10.txt" | ./${folderName}.out
