#pragma once

#include <stdio.h>
#include <vector>
#include <string>

#include "split.cpp"

using std::vector;
using std::string;

template <class Out>
void split(const string& str, Out os);