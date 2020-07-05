#!/usr/local/bin/bash

# exit when any command fails
set -e

echo "Compiling tests..."
g++ -std=c++11 -Wall median.o median_TestCase.cpp -o median_TestCase

echo "Running tests..."
./median_TestCase --success

#g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success 