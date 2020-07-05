#pragma once

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "crossref.cpp"

using std::vector;      using std::istream;
using std::string;      using std::back_insert_iterator;
using std::map;

template <class Out>
Out xref(
    istream& in, 
    void find_words(const string&, back_insert_iterator<vector<string> > ),
    Out os
    );