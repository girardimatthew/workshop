#!/usr/local/bin/bash

set -o errexit
set -o nounset

folderName=${PWD##*/}

echo
echo "Cleaning..."
make clean

echo
echo "Building..."
make

echo 
echo
cat "students.txt" | ./${folderName}.out