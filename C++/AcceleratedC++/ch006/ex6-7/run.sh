#!/bin/bash

make
echo 
echo "Executing..."
echo "Students list: Name midterm final homework"
cat students10.txt
echo
echo
cat "students10.txt" | ./ex6-7