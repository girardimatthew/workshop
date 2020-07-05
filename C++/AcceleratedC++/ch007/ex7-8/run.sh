#!/bin/bash

folderName=${PWD##*/}

make
echo 
echo
cat "input.txt" | "./${folderName}"