#!/bin/bash

folderName=${PWD##*/}

make
echo 
echo
cat "students.txt" | "./${folderName}"