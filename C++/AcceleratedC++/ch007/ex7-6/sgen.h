#ifndef sgen_h
#define sgen_h

#include <map>
#include "split.h"


typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef std::map<string, Rule_collection> Grammar;

Grammar read_grammar(std::istream& in);
vector<string> gen_sentence(const Grammar& g);

#endif /* sgen_h */