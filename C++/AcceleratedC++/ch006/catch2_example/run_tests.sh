#!/usr/local/bin/bash

echo "Compiling tests..."
g++ -std=c++11 -Wall -o 010-TestCase 010-TestCase.cpp
echo "Running tests..."
./010-TestCase --success
#g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success 