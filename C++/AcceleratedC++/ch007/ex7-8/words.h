#ifndef words_h
#define words_h

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "split.h"

using std::vector;      using std::istream;
using std::string;
using std::map;

map<string, vector<int> >xref(istream& in, vector<string> find_words(const string&) = split);

#endif /* words_h */