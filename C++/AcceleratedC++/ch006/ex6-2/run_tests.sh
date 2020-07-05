#!/usr/local/bin/bash

echo "Compiling tests..."
g++ -std=c++11 -Wall furls.o furls_TestCase.cpp -o furls_TestCase
echo "Running tests..."
./furls_TestCase --success

#g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success 