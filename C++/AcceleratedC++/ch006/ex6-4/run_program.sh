#!/usr/local/bin/bash

echo
echo "Cleaning..."
make clean

echo
echo "Building..."
make 

echo
echo "Executing..."
./${PWD##*/} 