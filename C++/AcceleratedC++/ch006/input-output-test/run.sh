#!/bin/bash

make clean
make
echo
cat test.txt | ./test